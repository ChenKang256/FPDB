#!/bin/bash

QUERIES=("09")
BASE_DIR="/mnt/Work/FlexPushdownDB-Dev"
ALLOWED_CONTAINERS=("/client1")


if [ $# -ne 1 ]; then
    echo "Usage: $0 <tag>"
    exit 1
fi

tag=$1
ts=$(date +%s)
sync_tag="${tag}_sync"
async_tag="${tag}_async"

log_folder=${BASE_DIR}/client_logs
log_file=${log_folder}/${tag}_${ts}_log.txt
dstat_file=${log_folder}/${tag}_${ts}_dstat.csv

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

function run_query {
    query=$1
    mode=$2
    run_tag="${tag}_${mode}"
    for container in $(docker ps -a -q)
    do
      container_name=$(docker inspect --format '{{.Name}}' ${container})
      if [[ ! " ${ALLOWED_CONTAINERS[@]} " =~ " ${container_name} " ]]; then
        echo "Skipping ${container_name}"
        continue
      fi

      echo "Running container: ${container}"
      if [[ "$mode" == "sync" ]]; then
        docker exec -it $container /bin/sh -c "/mnt/Work/FlexPushdownDB-Dev/resources/script/run_distr.sh ${run_tag} ${query}" > /dev/null 2>&1
      else
        docker exec -dit $container /bin/sh -c "/mnt/Work/FlexPushdownDB-Dev/resources/script/run_distr.sh ${run_tag} ${query}"
      fi
    done
}

function wait_for_containers {
    echo "Waiting for all containers to finish"
    docker_ps=$(ps -ef | grep "fpdb-main-test" | grep -v grep | awk '{print $2}')
    while [ -n "$docker_ps" ]
    do
      sleep 1
      docker_ps=$(ps -ef | grep "fpdb-main-test" | grep -v grep | awk '{print $2}')
    done
}

function parse_results {
    query=$1
    for container in $(docker ps -a -q)
    do
      container_name=$(docker inspect --format '{{.Name}}' $container)
      if [[ ! " ${ALLOWED_CONTAINERS[@]} " =~ " ${container_name} " ]]; then
        echo "Skipping $container_name"
        continue
      fi
      docker exec -it $container /bin/sh -c "python3 /mnt/Work/FlexPushdownDB-Dev/resources/script/parse_metrics.py ${sync_tag}_${query}"
      docker exec -it $container /bin/sh -c "python3 /mnt/Work/FlexPushdownDB-Dev/resources/script/parse_metrics.py ${async_tag}_${query}"
    done
}

function aggregate_results {
  # Remove first line of each file
  for query in "${QUERIES[@]}"
  do
    # except first query
    if [ "$query" != "${QUERIES[0]}" ];
    then
      for container in $(docker ps -a -q)
      do
        container_name=$(docker inspect --format '{{.Name}}' $container)
        if [[ ! " ${ALLOWED_CONTAINERS[@]} " =~ " ${container_name} " ]]; then
          echo "Skipping $container_name"
          continue
        fi
        docker exec -it $container /bin/sh -c "sed -i '1d' /mnt/Work/FlexPushdownDB-Dev/results/${sync_tag}_${query}*"
        docker exec -it $container /bin/sh -c "sed -i '1d' /mnt/Work/FlexPushdownDB-Dev/results/${async_tag}_${query}*"
      done
    fi
  done

  for container in $(docker ps -a -q)
  do
    container_name=$(docker inspect --format '{{.Name}}' $container)
    if [[ ! " ${ALLOWED_CONTAINERS[@]} " =~ " ${container_name} " ]]; then
      echo "Skipping $container_name"
      continue
    fi
    docker exec -it $container /bin/sh -c "cat /mnt/Work/FlexPushdownDB-Dev/results/${sync_tag}_*.csv > /mnt/Work/FlexPushdownDB-Dev/results/${sync_tag}.csv"
    docker exec -it $container /bin/sh -c "cat /mnt/Work/FlexPushdownDB-Dev/results/${async_tag}_*.csv > /mnt/Work/FlexPushdownDB-Dev/results/${async_tag}.csv"
  done
}

function main {
  echo "Starting..."
  start_dstat

  for query in "${QUERIES[@]}"
  do
      echo "Query: $query"

      echo "Running sync mode"
      run_query $query "sync"

      echo "Running async mode"
      run_query $query "async"
      wait_for_containers

      echo "Parsing results"
      parse_results $query
  done

  echo "Aggregating results"
  aggregate_results

  stop_dstat

  echo "Done"
}

main