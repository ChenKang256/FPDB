#!/bin/bash

ts=$(date +%s)
BASE_DIR=/mnt/Work/FlexPushdownDB-Dev
RUN_DIR=$BASE_DIR/build/fpdb-main

log_folder=$BASE_DIR/server_logs
dstat_file=$log_folder/${ts}_dstat.csv

mkdir -p $log_folder

function start_dstat() {
  echo "Logging dstat at file $dstat_file"
  pkill -9 -f /usr/bin/dstat
  sleep 1
  dstat -t --cpu --mem --disk --io --net --int --sys --tcp --noheaders --nocolor --output $dstat_file > /dev/null &
}

function stop_dstat() {
  echo "Stopping dstat"
  pkill -9 -f /usr/bin/dstat
}

function ctrl_c() {
    echo "** Trapped CTRL-C"
    stop_dstat
    popd
    exit
}

trap ctrl_c SIGINT

start_dstat
pushd $RUN_DIR
./fpdb-main-server
popd
