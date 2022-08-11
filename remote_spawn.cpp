// This program illustrates how to spawn a simple calculator
// across the network.
//
// Run server at port 4242:
// - remote_spawn -s -p 4242
//
// Run client at the same host:
// - remote_spawn -H localhost -p 4242

#include <array>
#include <cassert>
#include <functional>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>

#include "caf/all.hpp"
#include "caf/io/all.hpp"

// --(rst-calculator-begin)--
using calculator
  = caf::typed_actor<caf::result<void>(std::string)>;
// --(rst-calculator-end)--

CAF_BEGIN_TYPE_ID_BLOCK(remote_spawn, first_custom_type_id)

  CAF_ADD_TYPE_ID(remote_spawn, (calculator))

CAF_END_TYPE_ID_BLOCK(remote_spawn)

using std::cerr;
using std::cout;
using std::endl;
using std::string;

using namespace caf;

calculator::behavior_type calculator_fun(calculator::pointer self) {
  return {
    [=](std::string msg) {
      aout(self) << "Received messages from a remote node." << endl;
      // aout(self) << "The content is: " + msg[0] << endl;
    },
  };
}

struct config : actor_system_config {
  config() {
    add_actor_type("calculator", calculator_fun);
    opt_group{custom_options_, "global"}
      .add(port, "port,p", "set port")
      .add(host, "host,H", "set node (ignored in server mode)")
      .add(server_mode, "server-mode,s", "enable server mode");
  }
  uint16_t port = 0;
  string host = "localhost";
  bool server_mode = false;
};

void server(actor_system& system, const config& cfg) {
  auto res = system.middleman().open(cfg.port);
  if (!res) {
    cerr << "*** cannot open port: " << to_string(res.error()) << endl;
    return;
  }
  cout << "*** running on port: " << *res << endl
       << "*** press <enter> to shutdown server" << endl;
  getchar();
}

// --(rst-client-begin)--
void client(actor_system& system, const config& cfg) {
  auto node = system.middleman().connect("192.168.1.5", cfg.port);
  if (!node) {
    cerr << "*** connect failed: " << to_string(node.error()) << endl;
    return;
  }
  auto type = "calculator";             // type of the actor we wish to spawn
  auto args = make_message();           // arguments to construct the actor
  auto tout = std::chrono::seconds(30); // wait no longer than 30s
  auto worker_num = 1500;               // the number of actors we want
  std::vector<typed_actor<caf::result<void>(std::string)>> workers; 
  for (int i = 0; i < worker_num; i++) {
    workers.push_back(*system.middleman().remote_spawn<calculator>(*node, type, args,
                                                            tout));
  }
  // start using worker in main loop
  std::ifstream ifs("/home/partho/Work/FPDB-build/resources/metadata/ssb-sf10-sortlineorder/csv/data/lineorder_sharded/lineorder.tbl.0");
  std::string msg(
                  (std::istreambuf_iterator<char>(ifs)),
					        (std::istreambuf_iterator<char>()) 
                  );
  ifs.close();
  cout << "Single message size: " + std::to_string(msg.length() * sizeof(char)) + " Bytes"<< endl;
  for (int i = 0; i < worker_num; i++) {
    anon_send(workers[i], msg);
  }
  cout << "Successful send " + std::to_string(worker_num) + " messages" << endl;
  for (int i = 0; i < worker_num; i++) {
    // anon_send_exit(workers[i], exit_reason::kill);
  }
}
// --(rst-client-end)--

void caf_main(actor_system& system, const config& cfg) {
  auto f = cfg.server_mode ? server : client;
  f(system, cfg);
}

CAF_MAIN(id_block::remote_spawn, io::middleman)
