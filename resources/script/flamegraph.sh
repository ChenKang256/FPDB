#!/bin/bash

# Current timestamp
timestamp=$(date +%s)

FLAME_DIR=/mnt/Work/FlameGraph
BASE_DIR=/mnt/Work/FlexPushdownDB-Dev

pushd $BASE_DIR
PERF_LOG_DIR=$BASE_DIR/logs

mkdir -p $PERF_LOG_DIR

# list of all pids
appPids=$(pgrep -f fpdb-main-test)

# if appPids is empty, then there is no app running
if [ -z "$appPids" ]
then
    echo "No app running"
    popd
    exit 1
fi

# split the pid into an array
IFS=' ' read -r -a appPidsArray <<< "$appPids"

appPid=${appPidsArray[0]}

echo "Recording... ${appPid}"
sudo perf record -F 500 -p $appPid -g -- sleep 120

sudo chmod 666 perf.data

echo "Stack traces"
perf script | $FLAME_DIR/stackcollapse-perf.pl > $PERF_LOG_DIR/out.perf-folded

echo "Plot..."
$FLAME_DIR/flamegraph.pl $PERF_LOG_DIR/out.perf-folded > $PERF_LOG_DIR/perf_${timestamp}.svg

echo "Cleanup"
sudo rm perf.data
sudo rm $PERF_LOG_DIR/out.perf-folded

popd
