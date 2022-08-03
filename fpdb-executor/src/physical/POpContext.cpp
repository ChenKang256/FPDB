//
// Created by matt on 5/12/19.
//

#include <fpdb/executor/physical/POpContext.h>
#include <fpdb/executor/cache/SegmentCacheActor.h>
#include <fpdb/executor/message/Message.h>
#include <fpdb/executor/message/CompleteMessage.h>
#include <fpdb/executor/message/DebugMessage.h>
#include <fpdb/executor/message/cache/LoadRequestMessage.h>
#include <fpdb/executor/message/cache/CacheMetricsMessage.h>
#include <spdlog/spdlog.h>
#include <utility>
#include <cassert>

using namespace fpdb::executor::message;

namespace fpdb::executor::physical {

void POpContext::tell(std::shared_ptr<Message> &msg) {
  assert(this);
  if(complete_)
    notifyError(fmt::format("Cannot tell message to consumers, operator {} ('{}') is complete", this->operatorActor()->id(), this->operatorActor()->operator_()->name()));

  message::Envelope e(msg);

  // Send message to consumers
  string str = this->operatorActor()->operator_()->name();
  for(const auto& consumer: this->operatorActor()->operator_()->consumers()){
    ::caf::actor actorHandle = operatorMap_.get(consumer).value().getActor();
    operatorActor_->anon_send(actorHandle, e);
  }
}

void POpContext::send(const std::shared_ptr<message::Message> &msg, const std::string& recipientId) {
  message::Envelope e(msg);

  if(recipientId == "SegmentCache"){
    if(msg->type() == MessageType::LOAD_REQUEST){
      operatorActor_->request(segmentCacheActor_, infinite, LoadAtom_v, std::static_pointer_cast<fpdb::executor::message::LoadRequestMessage>(msg))
      .then([=](const std::shared_ptr<fpdb::executor::message::LoadResponseMessage>& response){
      operatorActor_->anon_send(this->operatorActor(), Envelope(response));
      });
    }
    else if(msg->type() == MessageType::STORE_REQUEST){
      operatorActor_->anon_send(segmentCacheActor_, StoreAtom_v, std::static_pointer_cast<fpdb::executor::message::StoreRequestMessage>(msg));
    }
    else if(msg->type() == MessageType::WEIGHT_REQUEST){
      operatorActor_->anon_send(segmentCacheActor_, WeightAtom_v, std::static_pointer_cast<fpdb::executor::message::WeightRequestMessage>(msg));
    }
    else if(msg->type() == MessageType::CACHE_METRICS){
      operatorActor_->anon_send(segmentCacheActor_, MetricsAtom_v, std::static_pointer_cast<fpdb::executor::message::CacheMetricsMessage>(msg));
    }
    else{
      notifyError("Unrecognized message " + msg->getTypeString());
    }

    return;
  }

  auto expectedOperator = operatorMap_.get(recipientId);
  if(expectedOperator.has_value()){
    auto recipientOperator = expectedOperator.value();
    operatorActor_->anon_send(recipientOperator.getActor(), e);
  } else{
  	notifyError(fmt::format("Actor with id '{}' not found", recipientId));
  }
}

/**
 * Send a CompleteMessage to all consumers and the root actor
 */
void POpContext::notifyComplete() {
  SPDLOG_DEBUG("Completing operator  |  source: {} ('{}')", this->operatorActor()->id(), this->operatorActor()->operator_()->name());
  if(complete_)
    notifyError(fmt::format("Cannot complete already completed operator {} ('{}')", this->operatorActor()->id(), this->operatorActor()->operator_()->name()));

  POpActor* operatorActor = this->operatorActor();

  std::shared_ptr<message::Message> msg = std::make_shared<message::CompleteMessage>(operatorActor->operator_()->name());
  message::Envelope e(msg);

  // Send message to consumers
  for(const auto& consumer: this->operatorActor()->operator_()->consumers()){
    ::caf::actor actorHandle = operatorMap_.get(consumer).value().getActor();
    operatorActor->anon_send(actorHandle, e);
  }

  // Send message to root actor
  operatorActor->anon_send(rootActor_, e);

  // Clear internal state, except collate whose internal state is final result
  if (operatorActor->operator_()->getType() != POpType::COLLATE) {
    operatorActor->operator_()->clear();
  }

  complete_ = true;
}

/**
 * Send error to the root actor
 */
void POpContext::notifyError(const std::string &content) {
  std::shared_ptr<Message> errorMsg = std::make_shared<ErrorMessage>(content, operatorActor_->name());
  message::Envelope e(errorMsg);
  operatorActor_->anon_send(rootActor_, e);
  operatorActor_->on_exit();
}

void POpContext::notifyDebug() {
  std::shared_ptr<Message> debugMsg = std::make_shared<DebugMessage>(operatorActor_->name());
  message::Envelope e(debugMsg);
  for(const auto& consumer: this->operatorActor()->operator_()->consumers()){
    ::caf::actor actorHandle = operatorMap_.get(consumer).value().getActor();
    operatorActor_->anon_send(actorHandle, e);
  }
}

POpContext::POpContext(::caf::actor rootActor, ::caf::actor segmentCacheActor):
    operatorActor_(nullptr),
    rootActor_(std::move(rootActor)),
    segmentCacheActor_(std::move(segmentCacheActor))
{}

LocalPOpDirectory &POpContext::operatorMap() {
  return operatorMap_;
}
POpActor* POpContext::operatorActor() {
  return operatorActor_;
}
void POpContext::operatorActor(POpActor *operatorActor) {
  operatorActor_ = operatorActor;
}

bool POpContext::isComplete() const {
  return complete_;
}

void POpContext::destroyActorHandles() {
  operatorMap_.destroyActorHandles();
  destroy(rootActor_);
  destroy(segmentCacheActor_);
}

} // namespace
