#!/bin/bash

TAG_BASE=$1
QUERY=$2
BASE_DIR=/mnt/Work/FlexPushdownDB-Dev/build/fpdb-main
pushd $BASE_DIR

runs=4
for i in $(seq 1 $runs)
do
  echo "Run $i"
  ./fpdb-main-test -ts=tpch-sf1-distributed -tc=tpch-sf1-distributed-$QUERY
done

echo "Done"

TAG="${TAG_BASE}_${QUERY}"
echo "Copying results to $TAG"
METRICS_DIR=$BASE_DIR/metrics

pushd $METRICS_DIR
TAG_DIR=$METRICS_DIR/$TAG
mkdir -p $TAG_DIR
for i in $(\ls -d  [0-9]*[0-9])
do
 mv $i $TAG_DIR
done

popd
popd
