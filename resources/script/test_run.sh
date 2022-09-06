#!/bin/bash
size_set=(10 20 30)
ori_sql_set=(1.1 1.2 1.3 2.1 2.2 2.3 3.1 3.2 3.3 3.4 4.1 4.2 4.3)
gen_sql_set=(1 2 3 4 5)
for SIZE in ${size_set[@]}
do	
	for SQL in ${ori_sql_set[@]}
	do	
		echo "ssb/original/$SQL.sql" | ./fpdb-main-test -ts=ssb-sf$SIZE-distributed 2>&1 | tee tmp_result
		cat tmp_result >> result
		sleep 30s
	done
	for SQL in ${gen_sql_set[@]}
	do	
		echo "ssb/generated/$SQL.sql" | ./fpdb-main-test -ts=ssb-sf$SIZE-distributed 2>&1 | tee tmp_result
		cat tmp_result >> result
		sleep 30s
	done
done

