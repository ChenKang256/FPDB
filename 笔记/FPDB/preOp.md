# preOp

## SSB

+ 1.1

  ```
  [doctest] doctest version is "2.4.0"
  [doctest] run with "--help" for options
  Query: ssb/original/1.1.sql
  Head: FileScan_onRemote[2]-date.tbl, node id: 0
     Sub: Filter_onRemote[2]-date.tbl
  Head: Filter_onRemote[2]-date.tbl, node id: 0
     Sub: Shuffle_onRemote[1]-Filter_onRemote[2]-date.tbl
  Head: FileScan_onRemote[3]-lineorder.tbl.31, node id: 0
     Sub: Filter_onRemote[3]-lineorder.tbl.31
  Head: FileScan_onRemote[3]-lineorder.tbl.29, node id: 1
     Sub: Filter_onRemote[3]-lineorder.tbl.29
  Head: FileScan_onRemote[3]-lineorder.tbl.9, node id: 0
     Sub: Filter_onRemote[3]-lineorder.tbl.9
  Head: FileScan_onRemote[3]-lineorder.tbl.21, node id: 1
     Sub: Filter_onRemote[3]-lineorder.tbl.21
  Head: FileScan_onRemote[3]-lineorder.tbl.5, node id: 0
     Sub: Filter_onRemote[3]-lineorder.tbl.5
  Head: FileScan_onRemote[3]-lineorder.tbl.11, node id: 1
     Sub: Filter_onRemote[3]-lineorder.tbl.11
  Head: FileScan_onRemote[3]-lineorder.tbl.6, node id: 0
     Sub: Filter_onRemote[3]-lineorder.tbl.6
  Head: FileScan_onRemote[3]-lineorder.tbl.4, node id: 1
     Sub: Filter_onRemote[3]-lineorder.tbl.4
  Head: FileScan_onRemote[3]-lineorder.tbl.10, node id: 0
     Sub: Filter_onRemote[3]-lineorder.tbl.10
  Head: FileScan_onRemote[3]-lineorder.tbl.13, node id: 1
     Sub: Filter_onRemote[3]-lineorder.tbl.13
  Head: FileScan_onRemote[3]-lineorder.tbl.3, node id: 0
     Sub: Filter_onRemote[3]-lineorder.tbl.3
  Head: FileScan_onRemote[3]-lineorder.tbl.2, node id: 1
     Sub: Filter_onRemote[3]-lineorder.tbl.2
  Head: FileScan_onRemote[3]-lineorder.tbl.1, node id: 0
     Sub: Filter_onRemote[3]-lineorder.tbl.1
  Head: FileScan_onRemote[3]-lineorder.tbl.0, node id: 1
     Sub: Filter_onRemote[3]-lineorder.tbl.0
  Head: FileScan_onRemote[3]-lineorder.tbl.12, node id: 0
     Sub: Filter_onRemote[3]-lineorder.tbl.12
  Head: FileScan_onRemote[3]-lineorder.tbl.15, node id: 1
     Sub: Filter_onRemote[3]-lineorder.tbl.15
  Head: FileScan_onRemote[3]-lineorder.tbl.16, node id: 0
     Sub: Filter_onRemote[3]-lineorder.tbl.16
  Head: FileScan_onRemote[3]-lineorder.tbl.20, node id: 1
     Sub: Filter_onRemote[3]-lineorder.tbl.20
  Head: FileScan_onRemote[3]-lineorder.tbl.18, node id: 0
     Sub: Filter_onRemote[3]-lineorder.tbl.18
  Head: FileScan_onRemote[3]-lineorder.tbl.19, node id: 1
     Sub: Filter_onRemote[3]-lineorder.tbl.19
  Head: FileScan_onRemote[3]-lineorder.tbl.30, node id: 0
     Sub: Filter_onRemote[3]-lineorder.tbl.30
  Head: FileScan_onRemote[3]-lineorder.tbl.22, node id: 1
     Sub: Filter_onRemote[3]-lineorder.tbl.22
  Head: FileScan_onRemote[3]-lineorder.tbl.8, node id: 0
     Sub: Filter_onRemote[3]-lineorder.tbl.8
  Head: FileScan_onRemote[3]-lineorder.tbl.27, node id: 1
     Sub: Filter_onRemote[3]-lineorder.tbl.27
  Head: FileScan_onRemote[3]-lineorder.tbl.14, node id: 0
     Sub: Filter_onRemote[3]-lineorder.tbl.14
  Head: FileScan_onRemote[3]-lineorder.tbl.28, node id: 1
     Sub: Filter_onRemote[3]-lineorder.tbl.28
  Head: FileScan_onRemote[3]-lineorder.tbl.17, node id: 0
     Sub: Filter_onRemote[3]-lineorder.tbl.17
  Head: FileScan_onRemote[3]-lineorder.tbl.23, node id: 1
     Sub: Filter_onRemote[3]-lineorder.tbl.23
  Head: FileScan_onRemote[3]-lineorder.tbl.24, node id: 0
     Sub: Filter_onRemote[3]-lineorder.tbl.24
  Head: FileScan_onRemote[3]-lineorder.tbl.7, node id: 1
     Sub: Filter_onRemote[3]-lineorder.tbl.7
  Head: FileScan_onRemote[3]-lineorder.tbl.25, node id: 0
     Sub: Filter_onRemote[3]-lineorder.tbl.25
  Head: FileScan_onRemote[3]-lineorder.tbl.26, node id: 1
     Sub: Filter_onRemote[3]-lineorder.tbl.26
  Head: Filter_onRemote[3]-lineorder.tbl.31, node id: 0
     Sub: Shuffle_onRemote[1]-Filter_onRemote[3]-lineorder.tbl.31
  Head: Filter_onRemote[3]-lineorder.tbl.29, node id: 1
     Sub: Shuffle_onRemote[1]-Filter_onRemote[3]-lineorder.tbl.29
  Head: Filter_onRemote[3]-lineorder.tbl.9, node id: 0
     Sub: Shuffle_onRemote[1]-Filter_onRemote[3]-lineorder.tbl.9
  Head: Filter_onRemote[3]-lineorder.tbl.21, node id: 1
     Sub: Shuffle_onRemote[1]-Filter_onRemote[3]-lineorder.tbl.21
  Head: Filter_onRemote[3]-lineorder.tbl.5, node id: 0
     Sub: Shuffle_onRemote[1]-Filter_onRemote[3]-lineorder.tbl.5
  Head: Filter_onRemote[3]-lineorder.tbl.11, node id: 1
     Sub: Shuffle_onRemote[1]-Filter_onRemote[3]-lineorder.tbl.11
  Head: Filter_onRemote[3]-lineorder.tbl.6, node id: 0
     Sub: Shuffle_onRemote[1]-Filter_onRemote[3]-lineorder.tbl.6
  Head: Filter_onRemote[3]-lineorder.tbl.4, node id: 1
     Sub: Shuffle_onRemote[1]-Filter_onRemote[3]-lineorder.tbl.4
  Head: Filter_onRemote[3]-lineorder.tbl.10, node id: 0
     Sub: Shuffle_onRemote[1]-Filter_onRemote[3]-lineorder.tbl.10
  Head: Filter_onRemote[3]-lineorder.tbl.13, node id: 1
     Sub: Shuffle_onRemote[1]-Filter_onRemote[3]-lineorder.tbl.13
  Head: Filter_onRemote[3]-lineorder.tbl.3, node id: 0
     Sub: Shuffle_onRemote[1]-Filter_onRemote[3]-lineorder.tbl.3
  Head: Filter_onRemote[3]-lineorder.tbl.2, node id: 1
     Sub: Shuffle_onRemote[1]-Filter_onRemote[3]-lineorder.tbl.2
  Head: Filter_onRemote[3]-lineorder.tbl.1, node id: 0
     Sub: Shuffle_onRemote[1]-Filter_onRemote[3]-lineorder.tbl.1
  Head: Filter_onRemote[3]-lineorder.tbl.0, node id: 1
     Sub: Shuffle_onRemote[1]-Filter_onRemote[3]-lineorder.tbl.0
  Head: Filter_onRemote[3]-lineorder.tbl.12, node id: 0
     Sub: Shuffle_onRemote[1]-Filter_onRemote[3]-lineorder.tbl.12
  Head: Filter_onRemote[3]-lineorder.tbl.15, node id: 1
     Sub: Shuffle_onRemote[1]-Filter_onRemote[3]-lineorder.tbl.15
  Head: Filter_onRemote[3]-lineorder.tbl.16, node id: 0
     Sub: Shuffle_onRemote[1]-Filter_onRemote[3]-lineorder.tbl.16
  Head: Filter_onRemote[3]-lineorder.tbl.20, node id: 1
     Sub: Shuffle_onRemote[1]-Filter_onRemote[3]-lineorder.tbl.20
  Head: Filter_onRemote[3]-lineorder.tbl.18, node id: 0
     Sub: Shuffle_onRemote[1]-Filter_onRemote[3]-lineorder.tbl.18
  Head: Filter_onRemote[3]-lineorder.tbl.19, node id: 1
     Sub: Shuffle_onRemote[1]-Filter_onRemote[3]-lineorder.tbl.19
  Head: Filter_onRemote[3]-lineorder.tbl.30, node id: 0
     Sub: Shuffle_onRemote[1]-Filter_onRemote[3]-lineorder.tbl.30
  Head: Filter_onRemote[3]-lineorder.tbl.22, node id: 1
     Sub: Shuffle_onRemote[1]-Filter_onRemote[3]-lineorder.tbl.22
  Head: Filter_onRemote[3]-lineorder.tbl.8, node id: 0
     Sub: Shuffle_onRemote[1]-Filter_onRemote[3]-lineorder.tbl.8
  Head: Filter_onRemote[3]-lineorder.tbl.27, node id: 1
     Sub: Shuffle_onRemote[1]-Filter_onRemote[3]-lineorder.tbl.27
  Head: Filter_onRemote[3]-lineorder.tbl.14, node id: 0
     Sub: Shuffle_onRemote[1]-Filter_onRemote[3]-lineorder.tbl.14
  Head: Filter_onRemote[3]-lineorder.tbl.28, node id: 1
     Sub: Shuffle_onRemote[1]-Filter_onRemote[3]-lineorder.tbl.28
  Head: Filter_onRemote[3]-lineorder.tbl.17, node id: 0
     Sub: Shuffle_onRemote[1]-Filter_onRemote[3]-lineorder.tbl.17
  Head: Filter_onRemote[3]-lineorder.tbl.23, node id: 1
     Sub: Shuffle_onRemote[1]-Filter_onRemote[3]-lineorder.tbl.23
  Head: Filter_onRemote[3]-lineorder.tbl.24, node id: 0
     Sub: Shuffle_onRemote[1]-Filter_onRemote[3]-lineorder.tbl.24
  Head: Filter_onRemote[3]-lineorder.tbl.7, node id: 1
     Sub: Shuffle_onRemote[1]-Filter_onRemote[3]-lineorder.tbl.7
  Head: Filter_onRemote[3]-lineorder.tbl.25, node id: 0
     Sub: Shuffle_onRemote[1]-Filter_onRemote[3]-lineorder.tbl.25
  Head: Filter_onRemote[3]-lineorder.tbl.26, node id: 1
     Sub: Shuffle_onRemote[1]-Filter_onRemote[3]-lineorder.tbl.26
  Head: HashJoinBuild[1]-d_datekey-lo_orderdate-0, node id: 0
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-0
  Head: HashJoinBuild[1]-d_datekey-lo_orderdate-1, node id: 1
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-1
  Head: HashJoinBuild[1]-d_datekey-lo_orderdate-2, node id: 0
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-2
  Head: HashJoinBuild[1]-d_datekey-lo_orderdate-3, node id: 1
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-3
  Head: HashJoinBuild[1]-d_datekey-lo_orderdate-4, node id: 0
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-4
  Head: HashJoinBuild[1]-d_datekey-lo_orderdate-5, node id: 1
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-5
  Head: HashJoinBuild[1]-d_datekey-lo_orderdate-6, node id: 0
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-6
  Head: HashJoinBuild[1]-d_datekey-lo_orderdate-7, node id: 1
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-7
  Head: HashJoinBuild[1]-d_datekey-lo_orderdate-8, node id: 0
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-8
  Head: HashJoinBuild[1]-d_datekey-lo_orderdate-9, node id: 1
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-9
  Head: HashJoinBuild[1]-d_datekey-lo_orderdate-10, node id: 0
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-10
  Head: HashJoinBuild[1]-d_datekey-lo_orderdate-11, node id: 1
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-11
  Head: HashJoinBuild[1]-d_datekey-lo_orderdate-12, node id: 0
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-12
  Head: HashJoinBuild[1]-d_datekey-lo_orderdate-13, node id: 1
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-13
  Head: HashJoinBuild[1]-d_datekey-lo_orderdate-14, node id: 0
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-14
  Head: HashJoinBuild[1]-d_datekey-lo_orderdate-15, node id: 1
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-15
  Head: HashJoinBuild[1]-d_datekey-lo_orderdate-16, node id: 0
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-16
  Head: HashJoinBuild[1]-d_datekey-lo_orderdate-17, node id: 1
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-17
  Head: HashJoinBuild[1]-d_datekey-lo_orderdate-18, node id: 0
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-18
  Head: HashJoinBuild[1]-d_datekey-lo_orderdate-19, node id: 1
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-19
  Head: HashJoinProbe[1]-d_datekey-lo_orderdate-0, node id: 0
     Sub: Aggregate[0]-0
  Head: HashJoinProbe[1]-d_datekey-lo_orderdate-1, node id: 1
     Sub: Aggregate[0]-1
  Head: HashJoinProbe[1]-d_datekey-lo_orderdate-2, node id: 0
     Sub: Aggregate[0]-2
  Head: HashJoinProbe[1]-d_datekey-lo_orderdate-3, node id: 1
     Sub: Aggregate[0]-3
  Head: HashJoinProbe[1]-d_datekey-lo_orderdate-4, node id: 0
     Sub: Aggregate[0]-4
  Head: HashJoinProbe[1]-d_datekey-lo_orderdate-5, node id: 1
     Sub: Aggregate[0]-5
  Head: HashJoinProbe[1]-d_datekey-lo_orderdate-6, node id: 0
     Sub: Aggregate[0]-6
  Head: HashJoinProbe[1]-d_datekey-lo_orderdate-7, node id: 1
     Sub: Aggregate[0]-7
  Head: HashJoinProbe[1]-d_datekey-lo_orderdate-8, node id: 0
     Sub: Aggregate[0]-8
  Head: HashJoinProbe[1]-d_datekey-lo_orderdate-9, node id: 1
     Sub: Aggregate[0]-9
  Head: HashJoinProbe[1]-d_datekey-lo_orderdate-10, node id: 0
     Sub: Aggregate[0]-10
  Head: HashJoinProbe[1]-d_datekey-lo_orderdate-11, node id: 1
     Sub: Aggregate[0]-11
  Head: HashJoinProbe[1]-d_datekey-lo_orderdate-12, node id: 0
     Sub: Aggregate[0]-12
  Head: HashJoinProbe[1]-d_datekey-lo_orderdate-13, node id: 1
     Sub: Aggregate[0]-13
  Head: HashJoinProbe[1]-d_datekey-lo_orderdate-14, node id: 0
     Sub: Aggregate[0]-14
  Head: HashJoinProbe[1]-d_datekey-lo_orderdate-15, node id: 1
     Sub: Aggregate[0]-15
  Head: HashJoinProbe[1]-d_datekey-lo_orderdate-16, node id: 0
     Sub: Aggregate[0]-16
  Head: HashJoinProbe[1]-d_datekey-lo_orderdate-17, node id: 1
     Sub: Aggregate[0]-17
  Head: HashJoinProbe[1]-d_datekey-lo_orderdate-18, node id: 0
     Sub: Aggregate[0]-18
  Head: HashJoinProbe[1]-d_datekey-lo_orderdate-19, node id: 1
     Sub: Aggregate[0]-19
  Head: Shuffle_onRemote[1]-Filter_onRemote[2]-date.tbl, node id: 0
     Sub: HashJoinBuild[1]-d_datekey-lo_orderdate-0
     Sub: HashJoinBuild[1]-d_datekey-lo_orderdate-1
     Sub: HashJoinBuild[1]-d_datekey-lo_orderdate-10
     Sub: HashJoinBuild[1]-d_datekey-lo_orderdate-11
     Sub: HashJoinBuild[1]-d_datekey-lo_orderdate-12
     Sub: HashJoinBuild[1]-d_datekey-lo_orderdate-13
     Sub: HashJoinBuild[1]-d_datekey-lo_orderdate-14
     Sub: HashJoinBuild[1]-d_datekey-lo_orderdate-15
     Sub: HashJoinBuild[1]-d_datekey-lo_orderdate-16
     Sub: HashJoinBuild[1]-d_datekey-lo_orderdate-17
     Sub: HashJoinBuild[1]-d_datekey-lo_orderdate-18
     Sub: HashJoinBuild[1]-d_datekey-lo_orderdate-19
     Sub: HashJoinBuild[1]-d_datekey-lo_orderdate-2
     Sub: HashJoinBuild[1]-d_datekey-lo_orderdate-3
     Sub: HashJoinBuild[1]-d_datekey-lo_orderdate-4
     Sub: HashJoinBuild[1]-d_datekey-lo_orderdate-5
     Sub: HashJoinBuild[1]-d_datekey-lo_orderdate-6
     Sub: HashJoinBuild[1]-d_datekey-lo_orderdate-7
     Sub: HashJoinBuild[1]-d_datekey-lo_orderdate-8
     Sub: HashJoinBuild[1]-d_datekey-lo_orderdate-9
  Head: Shuffle_onRemote[1]-Filter_onRemote[3]-lineorder.tbl.31, node id: 0
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-0
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-1
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-10
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-11
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-12
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-13
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-14
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-15
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-16
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-17
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-18
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-19
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-2
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-3
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-4
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-5
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-6
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-7
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-8
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-9
  Head: Shuffle_onRemote[1]-Filter_onRemote[3]-lineorder.tbl.29, node id: 1
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-0
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-1
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-10
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-11
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-12
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-13
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-14
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-15
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-16
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-17
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-18
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-19
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-2
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-3
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-4
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-5
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-6
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-7
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-8
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-9
  Head: Shuffle_onRemote[1]-Filter_onRemote[3]-lineorder.tbl.9, node id: 0
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-0
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-1
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-10
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-11
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-12
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-13
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-14
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-15
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-16
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-17
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-18
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-19
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-2
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-3
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-4
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-5
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-6
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-7
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-8
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-9
  Head: Shuffle_onRemote[1]-Filter_onRemote[3]-lineorder.tbl.21, node id: 1
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-0
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-1
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-10
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-11
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-12
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-13
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-14
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-15
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-16
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-17
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-18
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-19
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-2
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-3
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-4
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-5
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-6
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-7
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-8
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-9
  Head: Shuffle_onRemote[1]-Filter_onRemote[3]-lineorder.tbl.5, node id: 0
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-0
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-1
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-10
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-11
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-12
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-13
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-14
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-15
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-16
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-17
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-18
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-19
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-2
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-3
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-4
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-5
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-6
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-7
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-8
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-9
  Head: Shuffle_onRemote[1]-Filter_onRemote[3]-lineorder.tbl.11, node id: 1
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-0
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-1
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-10
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-11
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-12
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-13
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-14
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-15
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-16
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-17
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-18
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-19
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-2
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-3
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-4
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-5
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-6
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-7
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-8
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-9
  Head: Shuffle_onRemote[1]-Filter_onRemote[3]-lineorder.tbl.6, node id: 0
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-0
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-1
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-10
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-11
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-12
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-13
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-14
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-15
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-16
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-17
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-18
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-19
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-2
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-3
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-4
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-5
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-6
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-7
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-8
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-9
  Head: Shuffle_onRemote[1]-Filter_onRemote[3]-lineorder.tbl.4, node id: 1
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-0
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-1
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-10
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-11
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-12
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-13
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-14
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-15
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-16
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-17
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-18
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-19
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-2
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-3
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-4
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-5
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-6
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-7
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-8
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-9
  Head: Shuffle_onRemote[1]-Filter_onRemote[3]-lineorder.tbl.10, node id: 0
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-0
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-1
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-10
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-11
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-12
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-13
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-14
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-15
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-16
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-17
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-18
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-19
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-2
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-3
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-4
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-5
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-6
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-7
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-8
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-9
  Head: Shuffle_onRemote[1]-Filter_onRemote[3]-lineorder.tbl.13, node id: 1
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-0
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-1
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-10
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-11
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-12
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-13
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-14
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-15
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-16
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-17
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-18
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-19
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-2
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-3
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-4
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-5
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-6
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-7
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-8
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-9
  Head: Shuffle_onRemote[1]-Filter_onRemote[3]-lineorder.tbl.3, node id: 0
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-0
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-1
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-10
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-11
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-12
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-13
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-14
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-15
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-16
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-17
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-18
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-19
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-2
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-3
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-4
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-5
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-6
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-7
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-8
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-9
  Head: Shuffle_onRemote[1]-Filter_onRemote[3]-lineorder.tbl.2, node id: 1
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-0
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-1
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-10
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-11
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-12
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-13
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-14
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-15
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-16
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-17
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-18
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-19
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-2
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-3
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-4
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-5
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-6
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-7
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-8
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-9
  Head: Shuffle_onRemote[1]-Filter_onRemote[3]-lineorder.tbl.1, node id: 0
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-0
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-1
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-10
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-11
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-12
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-13
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-14
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-15
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-16
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-17
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-18
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-19
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-2
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-3
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-4
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-5
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-6
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-7
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-8
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-9
  Head: Shuffle_onRemote[1]-Filter_onRemote[3]-lineorder.tbl.0, node id: 1
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-0
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-1
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-10
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-11
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-12
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-13
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-14
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-15
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-16
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-17
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-18
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-19
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-2
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-3
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-4
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-5
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-6
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-7
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-8
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-9
  Head: Shuffle_onRemote[1]-Filter_onRemote[3]-lineorder.tbl.12, node id: 0
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-0
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-1
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-10
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-11
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-12
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-13
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-14
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-15
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-16
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-17
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-18
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-19
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-2
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-3
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-4
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-5
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-6
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-7
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-8
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-9
  Head: Shuffle_onRemote[1]-Filter_onRemote[3]-lineorder.tbl.15, node id: 1
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-0
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-1
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-10
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-11
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-12
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-13
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-14
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-15
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-16
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-17
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-18
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-19
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-2
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-3
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-4
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-5
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-6
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-7
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-8
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-9
  Head: Shuffle_onRemote[1]-Filter_onRemote[3]-lineorder.tbl.16, node id: 0
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-0
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-1
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-10
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-11
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-12
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-13
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-14
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-15
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-16
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-17
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-18
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-19
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-2
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-3
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-4
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-5
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-6
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-7
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-8
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-9
  Head: Shuffle_onRemote[1]-Filter_onRemote[3]-lineorder.tbl.20, node id: 1
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-0
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-1
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-10
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-11
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-12
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-13
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-14
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-15
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-16
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-17
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-18
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-19
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-2
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-3
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-4
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-5
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-6
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-7
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-8
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-9
  Head: Shuffle_onRemote[1]-Filter_onRemote[3]-lineorder.tbl.18, node id: 0
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-0
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-1
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-10
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-11
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-12
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-13
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-14
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-15
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-16
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-17
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-18
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-19
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-2
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-3
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-4
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-5
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-6
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-7
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-8
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-9
  Head: Shuffle_onRemote[1]-Filter_onRemote[3]-lineorder.tbl.19, node id: 1
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-0
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-1
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-10
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-11
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-12
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-13
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-14
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-15
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-16
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-17
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-18
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-19
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-2
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-3
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-4
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-5
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-6
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-7
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-8
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-9
  Head: Shuffle_onRemote[1]-Filter_onRemote[3]-lineorder.tbl.30, node id: 0
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-0
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-1
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-10
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-11
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-12
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-13
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-14
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-15
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-16
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-17
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-18
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-19
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-2
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-3
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-4
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-5
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-6
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-7
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-8
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-9
  Head: Shuffle_onRemote[1]-Filter_onRemote[3]-lineorder.tbl.22, node id: 1
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-0
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-1
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-10
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-11
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-12
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-13
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-14
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-15
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-16
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-17
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-18
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-19
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-2
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-3
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-4
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-5
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-6
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-7
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-8
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-9
  Head: Shuffle_onRemote[1]-Filter_onRemote[3]-lineorder.tbl.8, node id: 0
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-0
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-1
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-10
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-11
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-12
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-13
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-14
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-15
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-16
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-17
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-18
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-19
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-2
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-3
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-4
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-5
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-6
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-7
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-8
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-9
  Head: Shuffle_onRemote[1]-Filter_onRemote[3]-lineorder.tbl.27, node id: 1
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-0
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-1
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-10
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-11
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-12
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-13
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-14
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-15
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-16
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-17
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-18
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-19
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-2
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-3
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-4
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-5
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-6
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-7
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-8
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-9
  Head: Shuffle_onRemote[1]-Filter_onRemote[3]-lineorder.tbl.14, node id: 0
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-0
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-1
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-10
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-11
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-12
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-13
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-14
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-15
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-16
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-17
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-18
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-19
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-2
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-3
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-4
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-5
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-6
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-7
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-8
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-9
  Head: Shuffle_onRemote[1]-Filter_onRemote[3]-lineorder.tbl.28, node id: 1
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-0
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-1
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-10
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-11
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-12
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-13
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-14
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-15
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-16
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-17
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-18
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-19
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-2
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-3
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-4
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-5
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-6
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-7
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-8
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-9
  Head: Shuffle_onRemote[1]-Filter_onRemote[3]-lineorder.tbl.17, node id: 0
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-0
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-1
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-10
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-11
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-12
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-13
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-14
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-15
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-16
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-17
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-18
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-19
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-2
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-3
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-4
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-5
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-6
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-7
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-8
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-9
  Head: Shuffle_onRemote[1]-Filter_onRemote[3]-lineorder.tbl.23, node id: 1
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-0
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-1
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-10
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-11
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-12
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-13
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-14
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-15
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-16
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-17
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-18
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-19
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-2
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-3
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-4
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-5
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-6
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-7
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-8
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-9
  Head: Shuffle_onRemote[1]-Filter_onRemote[3]-lineorder.tbl.24, node id: 0
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-0
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-1
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-10
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-11
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-12
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-13
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-14
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-15
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-16
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-17
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-18
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-19
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-2
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-3
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-4
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-5
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-6
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-7
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-8
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-9
  Head: Shuffle_onRemote[1]-Filter_onRemote[3]-lineorder.tbl.7, node id: 1
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-0
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-1
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-10
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-11
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-12
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-13
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-14
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-15
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-16
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-17
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-18
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-19
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-2
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-3
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-4
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-5
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-6
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-7
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-8
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-9
  Head: Shuffle_onRemote[1]-Filter_onRemote[3]-lineorder.tbl.25, node id: 0
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-0
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-1
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-10
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-11
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-12
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-13
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-14
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-15
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-16
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-17
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-18
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-19
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-2
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-3
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-4
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-5
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-6
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-7
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-8
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-9
  Head: Shuffle_onRemote[1]-Filter_onRemote[3]-lineorder.tbl.26, node id: 1
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-0
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-1
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-10
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-11
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-12
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-13
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-14
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-15
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-16
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-17
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-18
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-19
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-2
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-3
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-4
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-5
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-6
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-7
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-8
     Sub: HashJoinProbe[1]-d_datekey-lo_orderdate-9
  Head: Aggregate[0]-0, node id: 0
     Sub: Aggregate[0]-Reduce
  Head: Aggregate[0]-1, node id: 1
     Sub: Aggregate[0]-Reduce
  Head: Aggregate[0]-2, node id: 0
     Sub: Aggregate[0]-Reduce
  Head: Aggregate[0]-3, node id: 1
     Sub: Aggregate[0]-Reduce
  Head: Aggregate[0]-4, node id: 0
     Sub: Aggregate[0]-Reduce
  Head: Aggregate[0]-5, node id: 1
     Sub: Aggregate[0]-Reduce
  Head: Aggregate[0]-6, node id: 0
     Sub: Aggregate[0]-Reduce
  Head: Aggregate[0]-7, node id: 1
     Sub: Aggregate[0]-Reduce
  Head: Aggregate[0]-8, node id: 0
     Sub: Aggregate[0]-Reduce
  Head: Aggregate[0]-9, node id: 1
     Sub: Aggregate[0]-Reduce
  Head: Aggregate[0]-10, node id: 0
     Sub: Aggregate[0]-Reduce
  Head: Aggregate[0]-11, node id: 1
     Sub: Aggregate[0]-Reduce
  Head: Aggregate[0]-12, node id: 0
     Sub: Aggregate[0]-Reduce
  Head: Aggregate[0]-13, node id: 1
     Sub: Aggregate[0]-Reduce
  Head: Aggregate[0]-14, node id: 0
     Sub: Aggregate[0]-Reduce
  Head: Aggregate[0]-15, node id: 1
     Sub: Aggregate[0]-Reduce
  Head: Aggregate[0]-16, node id: 0
     Sub: Aggregate[0]-Reduce
  Head: Aggregate[0]-17, node id: 1
     Sub: Aggregate[0]-Reduce
  Head: Aggregate[0]-18, node id: 0
     Sub: Aggregate[0]-Reduce
  Head: Aggregate[0]-19, node id: 1
     Sub: Aggregate[0]-Reduce
  Head: Aggregate[0]-Reduce, node id: 0
     Sub: collate
  Head: collate, node id: 0
  Remote Spawn Op: FileScan_onRemote[3]-lineorder.tbl.14
  Remote Spawn Op: FileScan_onRemote[3]-lineorder.tbl.30
  Remote Spawn Op: FileScan_onRemote[3]-lineorder.tbl.9
  Remote Spawn Op: FileScan_onRemote[3]-lineorder.tbl.8
  Remote Spawn Op: FileScan_onRemote[3]-lineorder.tbl.7
  Remote Spawn Op: FileScan_onRemote[3]-lineorder.tbl.24
  Remote Spawn Op: FileScan_onRemote[3]-lineorder.tbl.3
  Remote Spawn Op: FileScan_onRemote[3]-lineorder.tbl.20
  Remote Spawn Op: FileScan_onRemote[3]-lineorder.tbl.10
  Remote Spawn Op: FileScan_onRemote[3]-lineorder.tbl.25
  Remote Spawn Op: FileScan_onRemote[3]-lineorder.tbl.12
  Remote Spawn Op: FileScan_onRemote[3]-lineorder.tbl.17
  Remote Spawn Op: FileScan_onRemote[3]-lineorder.tbl.4
  Remote Spawn Op: FileScan_onRemote[3]-lineorder.tbl.11
  Remote Spawn Op: FileScan_onRemote[3]-lineorder.tbl.0
  Remote Spawn Op: FileScan_onRemote[3]-lineorder.tbl.23
  Remote Spawn Op: FileScan_onRemote[3]-lineorder.tbl.6
  Remote Spawn Op: FileScan_onRemote[3]-lineorder.tbl.27
  Remote Spawn Op: FileScan_onRemote[2]-date.tbl
  Remote Spawn Op: FileScan_onRemote[3]-lineorder.tbl.5
  Remote Spawn Op: FileScan_onRemote[3]-lineorder.tbl.29
  Remote Spawn Op: FileScan_onRemote[3]-lineorder.tbl.2
  Remote Spawn Op: FileScan_onRemote[3]-lineorder.tbl.31
  Remote Spawn Op: FileScan_onRemote[3]-lineorder.tbl.1
  Remote Spawn Op: FileScan_onRemote[3]-lineorder.tbl.19
  Remote Spawn Op: FileScan_onRemote[3]-lineorder.tbl.13
  Remote Spawn Op: FileScan_onRemote[3]-lineorder.tbl.15
  Remote Spawn Op: FileScan_onRemote[3]-lineorder.tbl.18
  Remote Spawn Op: FileScan_onRemote[3]-lineorder.tbl.16
  Remote Spawn Op: FileScan_onRemote[3]-lineorder.tbl.22
  Remote Spawn Op: FileScan_onRemote[3]-lineorder.tbl.28
  Remote Spawn Op: FileScan_onRemote[3]-lineorder.tbl.21
  Remote Spawn Op: FileScan_onRemote[3]-lineorder.tbl.26
  
  Time: 9.315021926 secs
  ```

+ 1：

  ```
  Query: ssb/generated/1.sql
  Head: FileScan_onRemote[3]-part.tbl, node id: 0
     Sub: Filter_onRemote[3]-part.tbl
  Head: Filter_onRemote[3]-part.tbl, node id: 0
     Sub: Shuffle_onRemote[2]-Filter_onRemote[3]-part.tbl
  Head: FileScan_onRemote[5]-date.tbl, node id: 0
     Sub: Shuffle_onRemote[4]-FileScan_onRemote[5]-date.tbl
  Head: FileScan_onRemote[7]-supplier.tbl, node id: 0
     Sub: Filter_onRemote[7]-supplier.tbl
  Head: Filter_onRemote[7]-supplier.tbl, node id: 0
     Sub: Shuffle_onRemote[6]-Filter_onRemote[7]-supplier.tbl
  Head: FileScan_onRemote[8]-lineorder.tbl.9, node id: 0
     Sub: Filter_onRemote[8]-lineorder.tbl.9
  Head: FileScan_onRemote[8]-lineorder.tbl.7, node id: 1
     Sub: Filter_onRemote[8]-lineorder.tbl.7
  Head: FileScan_onRemote[8]-lineorder.tbl.8, node id: 0
     Sub: Filter_onRemote[8]-lineorder.tbl.8
  Head: FileScan_onRemote[8]-lineorder.tbl.6, node id: 1
     Sub: Filter_onRemote[8]-lineorder.tbl.6
  Head: FileScan_onRemote[8]-lineorder.tbl.5, node id: 0
     Sub: Filter_onRemote[8]-lineorder.tbl.5
  Head: FileScan_onRemote[8]-lineorder.tbl.4, node id: 1
     Sub: Filter_onRemote[8]-lineorder.tbl.4
  Head: Filter_onRemote[8]-lineorder.tbl.9, node id: 0
     Sub: Shuffle_onRemote[6]-Filter_onRemote[8]-lineorder.tbl.9
  Head: Filter_onRemote[8]-lineorder.tbl.7, node id: 1
     Sub: Shuffle_onRemote[6]-Filter_onRemote[8]-lineorder.tbl.7
  Head: Filter_onRemote[8]-lineorder.tbl.8, node id: 0
     Sub: Shuffle_onRemote[6]-Filter_onRemote[8]-lineorder.tbl.8
  Head: Filter_onRemote[8]-lineorder.tbl.6, node id: 1
     Sub: Shuffle_onRemote[6]-Filter_onRemote[8]-lineorder.tbl.6
  Head: Filter_onRemote[8]-lineorder.tbl.5, node id: 0
     Sub: Shuffle_onRemote[6]-Filter_onRemote[8]-lineorder.tbl.5
  Head: Filter_onRemote[8]-lineorder.tbl.4, node id: 1
     Sub: Shuffle_onRemote[6]-Filter_onRemote[8]-lineorder.tbl.4
  Head: HashJoinBuild[6]-s_suppkey-lo_suppkey-0, node id: 0
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-0
  Head: HashJoinBuild[6]-s_suppkey-lo_suppkey-1, node id: 1
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-1
  Head: HashJoinBuild[6]-s_suppkey-lo_suppkey-2, node id: 0
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-2
  Head: HashJoinBuild[6]-s_suppkey-lo_suppkey-3, node id: 1
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-3
  Head: HashJoinBuild[6]-s_suppkey-lo_suppkey-4, node id: 0
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-4
  Head: HashJoinBuild[6]-s_suppkey-lo_suppkey-5, node id: 1
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-5
  Head: HashJoinBuild[6]-s_suppkey-lo_suppkey-6, node id: 0
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-6
  Head: HashJoinBuild[6]-s_suppkey-lo_suppkey-7, node id: 1
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-7
  Head: HashJoinBuild[6]-s_suppkey-lo_suppkey-8, node id: 0
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-8
  Head: HashJoinBuild[6]-s_suppkey-lo_suppkey-9, node id: 1
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-9
  Head: HashJoinBuild[6]-s_suppkey-lo_suppkey-10, node id: 0
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-10
  Head: HashJoinBuild[6]-s_suppkey-lo_suppkey-11, node id: 1
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-11
  Head: HashJoinBuild[6]-s_suppkey-lo_suppkey-12, node id: 0
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-12
  Head: HashJoinBuild[6]-s_suppkey-lo_suppkey-13, node id: 1
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-13
  Head: HashJoinBuild[6]-s_suppkey-lo_suppkey-14, node id: 0
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-14
  Head: HashJoinBuild[6]-s_suppkey-lo_suppkey-15, node id: 1
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-15
  Head: HashJoinBuild[6]-s_suppkey-lo_suppkey-16, node id: 0
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-16
  Head: HashJoinBuild[6]-s_suppkey-lo_suppkey-17, node id: 1
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-17
  Head: HashJoinBuild[6]-s_suppkey-lo_suppkey-18, node id: 0
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-18
  Head: HashJoinBuild[6]-s_suppkey-lo_suppkey-19, node id: 1
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-19
  Head: HashJoinProbe[6]-s_suppkey-lo_suppkey-0, node id: 0
     Sub: Shuffle[4]-HashJoinProbe[6]-s_suppkey-lo_suppkey-0
  Head: HashJoinProbe[6]-s_suppkey-lo_suppkey-1, node id: 1
     Sub: Shuffle[4]-HashJoinProbe[6]-s_suppkey-lo_suppkey-1
  Head: HashJoinProbe[6]-s_suppkey-lo_suppkey-2, node id: 0
     Sub: Shuffle[4]-HashJoinProbe[6]-s_suppkey-lo_suppkey-2
  Head: HashJoinProbe[6]-s_suppkey-lo_suppkey-3, node id: 1
     Sub: Shuffle[4]-HashJoinProbe[6]-s_suppkey-lo_suppkey-3
  Head: HashJoinProbe[6]-s_suppkey-lo_suppkey-4, node id: 0
     Sub: Shuffle[4]-HashJoinProbe[6]-s_suppkey-lo_suppkey-4
  Head: HashJoinProbe[6]-s_suppkey-lo_suppkey-5, node id: 1
     Sub: Shuffle[4]-HashJoinProbe[6]-s_suppkey-lo_suppkey-5
  Head: HashJoinProbe[6]-s_suppkey-lo_suppkey-6, node id: 0
     Sub: Shuffle[4]-HashJoinProbe[6]-s_suppkey-lo_suppkey-6
  Head: HashJoinProbe[6]-s_suppkey-lo_suppkey-7, node id: 1
     Sub: Shuffle[4]-HashJoinProbe[6]-s_suppkey-lo_suppkey-7
  Head: HashJoinProbe[6]-s_suppkey-lo_suppkey-8, node id: 0
     Sub: Shuffle[4]-HashJoinProbe[6]-s_suppkey-lo_suppkey-8
  Head: HashJoinProbe[6]-s_suppkey-lo_suppkey-9, node id: 1
     Sub: Shuffle[4]-HashJoinProbe[6]-s_suppkey-lo_suppkey-9
  Head: HashJoinProbe[6]-s_suppkey-lo_suppkey-10, node id: 0
     Sub: Shuffle[4]-HashJoinProbe[6]-s_suppkey-lo_suppkey-10
  Head: HashJoinProbe[6]-s_suppkey-lo_suppkey-11, node id: 1
     Sub: Shuffle[4]-HashJoinProbe[6]-s_suppkey-lo_suppkey-11
  Head: HashJoinProbe[6]-s_suppkey-lo_suppkey-12, node id: 0
     Sub: Shuffle[4]-HashJoinProbe[6]-s_suppkey-lo_suppkey-12
  Head: HashJoinProbe[6]-s_suppkey-lo_suppkey-13, node id: 1
     Sub: Shuffle[4]-HashJoinProbe[6]-s_suppkey-lo_suppkey-13
  Head: HashJoinProbe[6]-s_suppkey-lo_suppkey-14, node id: 0
     Sub: Shuffle[4]-HashJoinProbe[6]-s_suppkey-lo_suppkey-14
  Head: HashJoinProbe[6]-s_suppkey-lo_suppkey-15, node id: 1
     Sub: Shuffle[4]-HashJoinProbe[6]-s_suppkey-lo_suppkey-15
  Head: HashJoinProbe[6]-s_suppkey-lo_suppkey-16, node id: 0
     Sub: Shuffle[4]-HashJoinProbe[6]-s_suppkey-lo_suppkey-16
  Head: HashJoinProbe[6]-s_suppkey-lo_suppkey-17, node id: 1
     Sub: Shuffle[4]-HashJoinProbe[6]-s_suppkey-lo_suppkey-17
  Head: HashJoinProbe[6]-s_suppkey-lo_suppkey-18, node id: 0
     Sub: Shuffle[4]-HashJoinProbe[6]-s_suppkey-lo_suppkey-18
  Head: HashJoinProbe[6]-s_suppkey-lo_suppkey-19, node id: 1
     Sub: Shuffle[4]-HashJoinProbe[6]-s_suppkey-lo_suppkey-19
  Head: Shuffle_onRemote[6]-Filter_onRemote[7]-supplier.tbl, node id: 0
     Sub: HashJoinBuild[6]-s_suppkey-lo_suppkey-0
     Sub: HashJoinBuild[6]-s_suppkey-lo_suppkey-1
     Sub: HashJoinBuild[6]-s_suppkey-lo_suppkey-10
     Sub: HashJoinBuild[6]-s_suppkey-lo_suppkey-11
     Sub: HashJoinBuild[6]-s_suppkey-lo_suppkey-12
     Sub: HashJoinBuild[6]-s_suppkey-lo_suppkey-13
     Sub: HashJoinBuild[6]-s_suppkey-lo_suppkey-14
     Sub: HashJoinBuild[6]-s_suppkey-lo_suppkey-15
     Sub: HashJoinBuild[6]-s_suppkey-lo_suppkey-16
     Sub: HashJoinBuild[6]-s_suppkey-lo_suppkey-17
     Sub: HashJoinBuild[6]-s_suppkey-lo_suppkey-18
     Sub: HashJoinBuild[6]-s_suppkey-lo_suppkey-19
     Sub: HashJoinBuild[6]-s_suppkey-lo_suppkey-2
     Sub: HashJoinBuild[6]-s_suppkey-lo_suppkey-3
     Sub: HashJoinBuild[6]-s_suppkey-lo_suppkey-4
     Sub: HashJoinBuild[6]-s_suppkey-lo_suppkey-5
     Sub: HashJoinBuild[6]-s_suppkey-lo_suppkey-6
     Sub: HashJoinBuild[6]-s_suppkey-lo_suppkey-7
     Sub: HashJoinBuild[6]-s_suppkey-lo_suppkey-8
     Sub: HashJoinBuild[6]-s_suppkey-lo_suppkey-9
  Head: Shuffle_onRemote[6]-Filter_onRemote[8]-lineorder.tbl.9, node id: 0
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-0
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-1
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-10
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-11
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-12
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-13
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-14
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-15
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-16
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-17
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-18
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-19
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-2
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-3
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-4
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-5
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-6
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-7
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-8
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-9
  Head: Shuffle_onRemote[6]-Filter_onRemote[8]-lineorder.tbl.7, node id: 1
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-0
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-1
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-10
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-11
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-12
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-13
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-14
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-15
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-16
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-17
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-18
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-19
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-2
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-3
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-4
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-5
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-6
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-7
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-8
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-9
  Head: Shuffle_onRemote[6]-Filter_onRemote[8]-lineorder.tbl.8, node id: 0
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-0
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-1
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-10
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-11
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-12
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-13
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-14
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-15
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-16
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-17
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-18
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-19
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-2
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-3
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-4
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-5
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-6
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-7
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-8
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-9
  Head: Shuffle_onRemote[6]-Filter_onRemote[8]-lineorder.tbl.6, node id: 1
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-0
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-1
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-10
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-11
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-12
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-13
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-14
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-15
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-16
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-17
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-18
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-19
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-2
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-3
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-4
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-5
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-6
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-7
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-8
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-9
  Head: Shuffle_onRemote[6]-Filter_onRemote[8]-lineorder.tbl.5, node id: 0
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-0
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-1
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-10
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-11
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-12
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-13
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-14
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-15
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-16
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-17
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-18
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-19
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-2
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-3
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-4
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-5
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-6
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-7
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-8
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-9
  Head: Shuffle_onRemote[6]-Filter_onRemote[8]-lineorder.tbl.4, node id: 1
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-0
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-1
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-10
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-11
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-12
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-13
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-14
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-15
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-16
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-17
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-18
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-19
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-2
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-3
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-4
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-5
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-6
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-7
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-8
     Sub: HashJoinProbe[6]-s_suppkey-lo_suppkey-9
  Head: HashJoinBuild[4]-d_datekey-lo_orderdate-0, node id: 0
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-0
  Head: HashJoinBuild[4]-d_datekey-lo_orderdate-1, node id: 1
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-1
  Head: HashJoinBuild[4]-d_datekey-lo_orderdate-2, node id: 0
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-2
  Head: HashJoinBuild[4]-d_datekey-lo_orderdate-3, node id: 1
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-3
  Head: HashJoinBuild[4]-d_datekey-lo_orderdate-4, node id: 0
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-4
  Head: HashJoinBuild[4]-d_datekey-lo_orderdate-5, node id: 1
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-5
  Head: HashJoinBuild[4]-d_datekey-lo_orderdate-6, node id: 0
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-6
  Head: HashJoinBuild[4]-d_datekey-lo_orderdate-7, node id: 1
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-7
  Head: HashJoinBuild[4]-d_datekey-lo_orderdate-8, node id: 0
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-8
  Head: HashJoinBuild[4]-d_datekey-lo_orderdate-9, node id: 1
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-9
  Head: HashJoinBuild[4]-d_datekey-lo_orderdate-10, node id: 0
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-10
  Head: HashJoinBuild[4]-d_datekey-lo_orderdate-11, node id: 1
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-11
  Head: HashJoinBuild[4]-d_datekey-lo_orderdate-12, node id: 0
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-12
  Head: HashJoinBuild[4]-d_datekey-lo_orderdate-13, node id: 1
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-13
  Head: HashJoinBuild[4]-d_datekey-lo_orderdate-14, node id: 0
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-14
  Head: HashJoinBuild[4]-d_datekey-lo_orderdate-15, node id: 1
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-15
  Head: HashJoinBuild[4]-d_datekey-lo_orderdate-16, node id: 0
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-16
  Head: HashJoinBuild[4]-d_datekey-lo_orderdate-17, node id: 1
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-17
  Head: HashJoinBuild[4]-d_datekey-lo_orderdate-18, node id: 0
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-18
  Head: HashJoinBuild[4]-d_datekey-lo_orderdate-19, node id: 1
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-19
  Head: HashJoinProbe[4]-d_datekey-lo_orderdate-0, node id: 0
     Sub: Shuffle[2]-HashJoinProbe[4]-d_datekey-lo_orderdate-0
  Head: HashJoinProbe[4]-d_datekey-lo_orderdate-1, node id: 1
     Sub: Shuffle[2]-HashJoinProbe[4]-d_datekey-lo_orderdate-1
  Head: HashJoinProbe[4]-d_datekey-lo_orderdate-2, node id: 0
     Sub: Shuffle[2]-HashJoinProbe[4]-d_datekey-lo_orderdate-2
  Head: HashJoinProbe[4]-d_datekey-lo_orderdate-3, node id: 1
     Sub: Shuffle[2]-HashJoinProbe[4]-d_datekey-lo_orderdate-3
  Head: HashJoinProbe[4]-d_datekey-lo_orderdate-4, node id: 0
     Sub: Shuffle[2]-HashJoinProbe[4]-d_datekey-lo_orderdate-4
  Head: HashJoinProbe[4]-d_datekey-lo_orderdate-5, node id: 1
     Sub: Shuffle[2]-HashJoinProbe[4]-d_datekey-lo_orderdate-5
  Head: HashJoinProbe[4]-d_datekey-lo_orderdate-6, node id: 0
     Sub: Shuffle[2]-HashJoinProbe[4]-d_datekey-lo_orderdate-6
  Head: HashJoinProbe[4]-d_datekey-lo_orderdate-7, node id: 1
     Sub: Shuffle[2]-HashJoinProbe[4]-d_datekey-lo_orderdate-7
  Head: HashJoinProbe[4]-d_datekey-lo_orderdate-8, node id: 0
     Sub: Shuffle[2]-HashJoinProbe[4]-d_datekey-lo_orderdate-8
  Head: HashJoinProbe[4]-d_datekey-lo_orderdate-9, node id: 1
     Sub: Shuffle[2]-HashJoinProbe[4]-d_datekey-lo_orderdate-9
  Head: HashJoinProbe[4]-d_datekey-lo_orderdate-10, node id: 0
     Sub: Shuffle[2]-HashJoinProbe[4]-d_datekey-lo_orderdate-10
  Head: HashJoinProbe[4]-d_datekey-lo_orderdate-11, node id: 1
     Sub: Shuffle[2]-HashJoinProbe[4]-d_datekey-lo_orderdate-11
  Head: HashJoinProbe[4]-d_datekey-lo_orderdate-12, node id: 0
     Sub: Shuffle[2]-HashJoinProbe[4]-d_datekey-lo_orderdate-12
  Head: HashJoinProbe[4]-d_datekey-lo_orderdate-13, node id: 1
     Sub: Shuffle[2]-HashJoinProbe[4]-d_datekey-lo_orderdate-13
  Head: HashJoinProbe[4]-d_datekey-lo_orderdate-14, node id: 0
     Sub: Shuffle[2]-HashJoinProbe[4]-d_datekey-lo_orderdate-14
  Head: HashJoinProbe[4]-d_datekey-lo_orderdate-15, node id: 1
     Sub: Shuffle[2]-HashJoinProbe[4]-d_datekey-lo_orderdate-15
  Head: HashJoinProbe[4]-d_datekey-lo_orderdate-16, node id: 0
     Sub: Shuffle[2]-HashJoinProbe[4]-d_datekey-lo_orderdate-16
  Head: HashJoinProbe[4]-d_datekey-lo_orderdate-17, node id: 1
     Sub: Shuffle[2]-HashJoinProbe[4]-d_datekey-lo_orderdate-17
  Head: HashJoinProbe[4]-d_datekey-lo_orderdate-18, node id: 0
     Sub: Shuffle[2]-HashJoinProbe[4]-d_datekey-lo_orderdate-18
  Head: HashJoinProbe[4]-d_datekey-lo_orderdate-19, node id: 1
     Sub: Shuffle[2]-HashJoinProbe[4]-d_datekey-lo_orderdate-19
  Head: Shuffle_onRemote[4]-FileScan_onRemote[5]-date.tbl, node id: 0
     Sub: HashJoinBuild[4]-d_datekey-lo_orderdate-0
     Sub: HashJoinBuild[4]-d_datekey-lo_orderdate-1
     Sub: HashJoinBuild[4]-d_datekey-lo_orderdate-10
     Sub: HashJoinBuild[4]-d_datekey-lo_orderdate-11
     Sub: HashJoinBuild[4]-d_datekey-lo_orderdate-12
     Sub: HashJoinBuild[4]-d_datekey-lo_orderdate-13
     Sub: HashJoinBuild[4]-d_datekey-lo_orderdate-14
     Sub: HashJoinBuild[4]-d_datekey-lo_orderdate-15
     Sub: HashJoinBuild[4]-d_datekey-lo_orderdate-16
     Sub: HashJoinBuild[4]-d_datekey-lo_orderdate-17
     Sub: HashJoinBuild[4]-d_datekey-lo_orderdate-18
     Sub: HashJoinBuild[4]-d_datekey-lo_orderdate-19
     Sub: HashJoinBuild[4]-d_datekey-lo_orderdate-2
     Sub: HashJoinBuild[4]-d_datekey-lo_orderdate-3
     Sub: HashJoinBuild[4]-d_datekey-lo_orderdate-4
     Sub: HashJoinBuild[4]-d_datekey-lo_orderdate-5
     Sub: HashJoinBuild[4]-d_datekey-lo_orderdate-6
     Sub: HashJoinBuild[4]-d_datekey-lo_orderdate-7
     Sub: HashJoinBuild[4]-d_datekey-lo_orderdate-8
     Sub: HashJoinBuild[4]-d_datekey-lo_orderdate-9
  Head: Shuffle[4]-HashJoinProbe[6]-s_suppkey-lo_suppkey-0, node id: 0
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-0
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-1
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-10
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-11
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-12
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-13
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-14
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-15
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-16
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-17
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-18
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-19
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-2
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-3
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-4
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-5
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-6
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-7
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-8
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-9
  Head: Shuffle[4]-HashJoinProbe[6]-s_suppkey-lo_suppkey-1, node id: 1
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-0
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-1
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-10
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-11
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-12
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-13
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-14
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-15
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-16
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-17
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-18
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-19
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-2
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-3
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-4
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-5
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-6
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-7
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-8
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-9
  Head: Shuffle[4]-HashJoinProbe[6]-s_suppkey-lo_suppkey-2, node id: 0
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-0
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-1
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-10
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-11
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-12
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-13
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-14
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-15
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-16
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-17
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-18
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-19
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-2
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-3
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-4
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-5
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-6
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-7
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-8
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-9
  Head: Shuffle[4]-HashJoinProbe[6]-s_suppkey-lo_suppkey-3, node id: 1
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-0
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-1
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-10
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-11
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-12
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-13
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-14
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-15
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-16
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-17
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-18
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-19
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-2
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-3
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-4
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-5
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-6
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-7
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-8
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-9
  Head: Shuffle[4]-HashJoinProbe[6]-s_suppkey-lo_suppkey-4, node id: 0
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-0
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-1
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-10
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-11
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-12
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-13
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-14
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-15
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-16
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-17
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-18
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-19
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-2
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-3
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-4
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-5
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-6
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-7
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-8
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-9
  Head: Shuffle[4]-HashJoinProbe[6]-s_suppkey-lo_suppkey-5, node id: 1
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-0
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-1
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-10
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-11
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-12
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-13
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-14
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-15
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-16
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-17
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-18
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-19
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-2
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-3
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-4
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-5
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-6
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-7
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-8
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-9
  Head: Shuffle[4]-HashJoinProbe[6]-s_suppkey-lo_suppkey-6, node id: 0
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-0
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-1
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-10
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-11
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-12
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-13
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-14
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-15
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-16
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-17
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-18
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-19
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-2
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-3
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-4
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-5
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-6
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-7
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-8
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-9
  Head: Shuffle[4]-HashJoinProbe[6]-s_suppkey-lo_suppkey-7, node id: 1
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-0
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-1
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-10
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-11
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-12
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-13
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-14
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-15
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-16
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-17
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-18
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-19
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-2
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-3
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-4
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-5
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-6
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-7
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-8
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-9
  Head: Shuffle[4]-HashJoinProbe[6]-s_suppkey-lo_suppkey-8, node id: 0
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-0
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-1
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-10
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-11
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-12
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-13
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-14
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-15
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-16
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-17
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-18
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-19
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-2
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-3
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-4
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-5
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-6
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-7
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-8
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-9
  Head: Shuffle[4]-HashJoinProbe[6]-s_suppkey-lo_suppkey-9, node id: 1
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-0
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-1
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-10
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-11
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-12
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-13
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-14
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-15
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-16
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-17
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-18
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-19
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-2
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-3
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-4
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-5
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-6
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-7
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-8
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-9
  Head: Shuffle[4]-HashJoinProbe[6]-s_suppkey-lo_suppkey-10, node id: 0
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-0
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-1
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-10
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-11
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-12
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-13
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-14
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-15
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-16
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-17
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-18
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-19
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-2
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-3
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-4
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-5
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-6
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-7
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-8
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-9
  Head: Shuffle[4]-HashJoinProbe[6]-s_suppkey-lo_suppkey-11, node id: 1
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-0
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-1
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-10
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-11
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-12
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-13
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-14
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-15
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-16
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-17
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-18
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-19
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-2
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-3
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-4
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-5
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-6
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-7
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-8
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-9
  Head: Shuffle[4]-HashJoinProbe[6]-s_suppkey-lo_suppkey-12, node id: 0
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-0
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-1
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-10
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-11
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-12
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-13
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-14
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-15
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-16
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-17
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-18
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-19
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-2
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-3
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-4
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-5
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-6
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-7
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-8
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-9
  Head: Shuffle[4]-HashJoinProbe[6]-s_suppkey-lo_suppkey-13, node id: 1
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-0
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-1
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-10
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-11
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-12
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-13
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-14
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-15
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-16
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-17
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-18
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-19
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-2
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-3
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-4
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-5
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-6
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-7
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-8
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-9
  Head: Shuffle[4]-HashJoinProbe[6]-s_suppkey-lo_suppkey-14, node id: 0
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-0
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-1
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-10
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-11
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-12
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-13
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-14
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-15
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-16
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-17
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-18
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-19
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-2
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-3
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-4
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-5
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-6
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-7
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-8
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-9
  Head: Shuffle[4]-HashJoinProbe[6]-s_suppkey-lo_suppkey-15, node id: 1
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-0
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-1
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-10
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-11
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-12
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-13
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-14
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-15
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-16
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-17
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-18
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-19
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-2
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-3
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-4
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-5
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-6
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-7
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-8
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-9
  Head: Shuffle[4]-HashJoinProbe[6]-s_suppkey-lo_suppkey-16, node id: 0
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-0
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-1
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-10
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-11
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-12
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-13
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-14
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-15
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-16
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-17
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-18
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-19
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-2
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-3
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-4
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-5
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-6
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-7
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-8
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-9
  Head: Shuffle[4]-HashJoinProbe[6]-s_suppkey-lo_suppkey-17, node id: 1
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-0
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-1
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-10
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-11
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-12
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-13
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-14
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-15
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-16
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-17
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-18
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-19
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-2
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-3
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-4
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-5
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-6
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-7
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-8
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-9
  Head: Shuffle[4]-HashJoinProbe[6]-s_suppkey-lo_suppkey-18, node id: 0
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-0
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-1
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-10
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-11
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-12
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-13
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-14
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-15
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-16
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-17
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-18
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-19
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-2
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-3
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-4
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-5
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-6
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-7
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-8
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-9
  Head: Shuffle[4]-HashJoinProbe[6]-s_suppkey-lo_suppkey-19, node id: 1
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-0
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-1
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-10
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-11
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-12
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-13
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-14
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-15
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-16
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-17
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-18
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-19
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-2
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-3
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-4
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-5
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-6
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-7
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-8
     Sub: HashJoinProbe[4]-d_datekey-lo_orderdate-9
  Head: HashJoinBuild[2]-p_partkey-lo_partkey-0, node id: 0
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-0
  Head: HashJoinBuild[2]-p_partkey-lo_partkey-1, node id: 1
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-1
  Head: HashJoinBuild[2]-p_partkey-lo_partkey-2, node id: 0
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-2
  Head: HashJoinBuild[2]-p_partkey-lo_partkey-3, node id: 1
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-3
  Head: HashJoinBuild[2]-p_partkey-lo_partkey-4, node id: 0
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-4
  Head: HashJoinBuild[2]-p_partkey-lo_partkey-5, node id: 1
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-5
  Head: HashJoinBuild[2]-p_partkey-lo_partkey-6, node id: 0
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-6
  Head: HashJoinBuild[2]-p_partkey-lo_partkey-7, node id: 1
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-7
  Head: HashJoinBuild[2]-p_partkey-lo_partkey-8, node id: 0
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-8
  Head: HashJoinBuild[2]-p_partkey-lo_partkey-9, node id: 1
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-9
  Head: HashJoinBuild[2]-p_partkey-lo_partkey-10, node id: 0
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-10
  Head: HashJoinBuild[2]-p_partkey-lo_partkey-11, node id: 1
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-11
  Head: HashJoinBuild[2]-p_partkey-lo_partkey-12, node id: 0
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-12
  Head: HashJoinBuild[2]-p_partkey-lo_partkey-13, node id: 1
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-13
  Head: HashJoinBuild[2]-p_partkey-lo_partkey-14, node id: 0
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-14
  Head: HashJoinBuild[2]-p_partkey-lo_partkey-15, node id: 1
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-15
  Head: HashJoinBuild[2]-p_partkey-lo_partkey-16, node id: 0
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-16
  Head: HashJoinBuild[2]-p_partkey-lo_partkey-17, node id: 1
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-17
  Head: HashJoinBuild[2]-p_partkey-lo_partkey-18, node id: 0
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-18
  Head: HashJoinBuild[2]-p_partkey-lo_partkey-19, node id: 1
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-19
  Head: HashJoinProbe[2]-p_partkey-lo_partkey-0, node id: 0
     Sub: Shuffle[1]-HashJoinProbe[2]-p_partkey-lo_partkey-0
  Head: HashJoinProbe[2]-p_partkey-lo_partkey-1, node id: 1
     Sub: Shuffle[1]-HashJoinProbe[2]-p_partkey-lo_partkey-1
  Head: HashJoinProbe[2]-p_partkey-lo_partkey-2, node id: 0
     Sub: Shuffle[1]-HashJoinProbe[2]-p_partkey-lo_partkey-2
  Head: HashJoinProbe[2]-p_partkey-lo_partkey-3, node id: 1
     Sub: Shuffle[1]-HashJoinProbe[2]-p_partkey-lo_partkey-3
  Head: HashJoinProbe[2]-p_partkey-lo_partkey-4, node id: 0
     Sub: Shuffle[1]-HashJoinProbe[2]-p_partkey-lo_partkey-4
  Head: HashJoinProbe[2]-p_partkey-lo_partkey-5, node id: 1
     Sub: Shuffle[1]-HashJoinProbe[2]-p_partkey-lo_partkey-5
  Head: HashJoinProbe[2]-p_partkey-lo_partkey-6, node id: 0
     Sub: Shuffle[1]-HashJoinProbe[2]-p_partkey-lo_partkey-6
  Head: HashJoinProbe[2]-p_partkey-lo_partkey-7, node id: 1
     Sub: Shuffle[1]-HashJoinProbe[2]-p_partkey-lo_partkey-7
  Head: HashJoinProbe[2]-p_partkey-lo_partkey-8, node id: 0
     Sub: Shuffle[1]-HashJoinProbe[2]-p_partkey-lo_partkey-8
  Head: HashJoinProbe[2]-p_partkey-lo_partkey-9, node id: 1
     Sub: Shuffle[1]-HashJoinProbe[2]-p_partkey-lo_partkey-9
  Head: HashJoinProbe[2]-p_partkey-lo_partkey-10, node id: 0
     Sub: Shuffle[1]-HashJoinProbe[2]-p_partkey-lo_partkey-10
  Head: HashJoinProbe[2]-p_partkey-lo_partkey-11, node id: 1
     Sub: Shuffle[1]-HashJoinProbe[2]-p_partkey-lo_partkey-11
  Head: HashJoinProbe[2]-p_partkey-lo_partkey-12, node id: 0
     Sub: Shuffle[1]-HashJoinProbe[2]-p_partkey-lo_partkey-12
  Head: HashJoinProbe[2]-p_partkey-lo_partkey-13, node id: 1
     Sub: Shuffle[1]-HashJoinProbe[2]-p_partkey-lo_partkey-13
  Head: HashJoinProbe[2]-p_partkey-lo_partkey-14, node id: 0
     Sub: Shuffle[1]-HashJoinProbe[2]-p_partkey-lo_partkey-14
  Head: HashJoinProbe[2]-p_partkey-lo_partkey-15, node id: 1
     Sub: Shuffle[1]-HashJoinProbe[2]-p_partkey-lo_partkey-15
  Head: HashJoinProbe[2]-p_partkey-lo_partkey-16, node id: 0
     Sub: Shuffle[1]-HashJoinProbe[2]-p_partkey-lo_partkey-16
  Head: HashJoinProbe[2]-p_partkey-lo_partkey-17, node id: 1
     Sub: Shuffle[1]-HashJoinProbe[2]-p_partkey-lo_partkey-17
  Head: HashJoinProbe[2]-p_partkey-lo_partkey-18, node id: 0
     Sub: Shuffle[1]-HashJoinProbe[2]-p_partkey-lo_partkey-18
  Head: HashJoinProbe[2]-p_partkey-lo_partkey-19, node id: 1
     Sub: Shuffle[1]-HashJoinProbe[2]-p_partkey-lo_partkey-19
  Head: Shuffle_onRemote[2]-Filter_onRemote[3]-part.tbl, node id: 0
     Sub: HashJoinBuild[2]-p_partkey-lo_partkey-0
     Sub: HashJoinBuild[2]-p_partkey-lo_partkey-1
     Sub: HashJoinBuild[2]-p_partkey-lo_partkey-10
     Sub: HashJoinBuild[2]-p_partkey-lo_partkey-11
     Sub: HashJoinBuild[2]-p_partkey-lo_partkey-12
     Sub: HashJoinBuild[2]-p_partkey-lo_partkey-13
     Sub: HashJoinBuild[2]-p_partkey-lo_partkey-14
     Sub: HashJoinBuild[2]-p_partkey-lo_partkey-15
     Sub: HashJoinBuild[2]-p_partkey-lo_partkey-16
     Sub: HashJoinBuild[2]-p_partkey-lo_partkey-17
     Sub: HashJoinBuild[2]-p_partkey-lo_partkey-18
     Sub: HashJoinBuild[2]-p_partkey-lo_partkey-19
     Sub: HashJoinBuild[2]-p_partkey-lo_partkey-2
     Sub: HashJoinBuild[2]-p_partkey-lo_partkey-3
     Sub: HashJoinBuild[2]-p_partkey-lo_partkey-4
     Sub: HashJoinBuild[2]-p_partkey-lo_partkey-5
     Sub: HashJoinBuild[2]-p_partkey-lo_partkey-6
     Sub: HashJoinBuild[2]-p_partkey-lo_partkey-7
     Sub: HashJoinBuild[2]-p_partkey-lo_partkey-8
     Sub: HashJoinBuild[2]-p_partkey-lo_partkey-9
  Head: Shuffle[2]-HashJoinProbe[4]-d_datekey-lo_orderdate-0, node id: 0
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-0
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-1
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-10
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-11
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-12
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-13
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-14
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-15
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-16
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-17
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-18
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-19
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-2
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-3
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-4
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-5
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-6
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-7
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-8
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-9
  Head: Shuffle[2]-HashJoinProbe[4]-d_datekey-lo_orderdate-1, node id: 1
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-0
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-1
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-10
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-11
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-12
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-13
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-14
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-15
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-16
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-17
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-18
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-19
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-2
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-3
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-4
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-5
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-6
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-7
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-8
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-9
  Head: Shuffle[2]-HashJoinProbe[4]-d_datekey-lo_orderdate-2, node id: 0
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-0
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-1
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-10
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-11
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-12
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-13
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-14
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-15
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-16
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-17
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-18
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-19
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-2
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-3
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-4
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-5
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-6
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-7
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-8
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-9
  Head: Shuffle[2]-HashJoinProbe[4]-d_datekey-lo_orderdate-3, node id: 1
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-0
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-1
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-10
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-11
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-12
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-13
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-14
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-15
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-16
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-17
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-18
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-19
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-2
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-3
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-4
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-5
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-6
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-7
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-8
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-9
  Head: Shuffle[2]-HashJoinProbe[4]-d_datekey-lo_orderdate-4, node id: 0
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-0
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-1
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-10
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-11
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-12
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-13
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-14
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-15
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-16
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-17
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-18
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-19
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-2
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-3
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-4
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-5
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-6
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-7
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-8
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-9
  Head: Shuffle[2]-HashJoinProbe[4]-d_datekey-lo_orderdate-5, node id: 1
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-0
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-1
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-10
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-11
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-12
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-13
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-14
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-15
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-16
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-17
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-18
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-19
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-2
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-3
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-4
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-5
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-6
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-7
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-8
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-9
  Head: Shuffle[2]-HashJoinProbe[4]-d_datekey-lo_orderdate-6, node id: 0
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-0
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-1
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-10
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-11
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-12
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-13
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-14
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-15
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-16
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-17
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-18
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-19
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-2
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-3
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-4
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-5
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-6
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-7
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-8
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-9
  Head: Shuffle[2]-HashJoinProbe[4]-d_datekey-lo_orderdate-7, node id: 1
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-0
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-1
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-10
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-11
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-12
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-13
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-14
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-15
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-16
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-17
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-18
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-19
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-2
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-3
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-4
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-5
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-6
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-7
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-8
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-9
  Head: Shuffle[2]-HashJoinProbe[4]-d_datekey-lo_orderdate-8, node id: 0
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-0
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-1
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-10
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-11
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-12
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-13
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-14
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-15
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-16
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-17
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-18
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-19
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-2
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-3
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-4
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-5
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-6
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-7
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-8
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-9
  Head: Shuffle[2]-HashJoinProbe[4]-d_datekey-lo_orderdate-9, node id: 1
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-0
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-1
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-10
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-11
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-12
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-13
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-14
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-15
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-16
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-17
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-18
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-19
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-2
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-3
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-4
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-5
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-6
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-7
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-8
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-9
  Head: Shuffle[2]-HashJoinProbe[4]-d_datekey-lo_orderdate-10, node id: 0
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-0
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-1
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-10
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-11
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-12
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-13
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-14
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-15
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-16
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-17
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-18
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-19
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-2
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-3
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-4
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-5
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-6
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-7
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-8
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-9
  Head: Shuffle[2]-HashJoinProbe[4]-d_datekey-lo_orderdate-11, node id: 1
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-0
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-1
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-10
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-11
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-12
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-13
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-14
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-15
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-16
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-17
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-18
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-19
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-2
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-3
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-4
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-5
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-6
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-7
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-8
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-9
  Head: Shuffle[2]-HashJoinProbe[4]-d_datekey-lo_orderdate-12, node id: 0
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-0
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-1
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-10
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-11
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-12
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-13
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-14
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-15
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-16
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-17
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-18
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-19
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-2
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-3
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-4
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-5
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-6
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-7
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-8
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-9
  Head: Shuffle[2]-HashJoinProbe[4]-d_datekey-lo_orderdate-13, node id: 1
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-0
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-1
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-10
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-11
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-12
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-13
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-14
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-15
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-16
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-17
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-18
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-19
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-2
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-3
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-4
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-5
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-6
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-7
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-8
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-9
  Head: Shuffle[2]-HashJoinProbe[4]-d_datekey-lo_orderdate-14, node id: 0
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-0
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-1
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-10
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-11
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-12
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-13
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-14
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-15
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-16
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-17
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-18
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-19
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-2
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-3
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-4
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-5
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-6
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-7
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-8
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-9
  Head: Shuffle[2]-HashJoinProbe[4]-d_datekey-lo_orderdate-15, node id: 1
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-0
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-1
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-10
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-11
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-12
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-13
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-14
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-15
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-16
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-17
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-18
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-19
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-2
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-3
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-4
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-5
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-6
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-7
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-8
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-9
  Head: Shuffle[2]-HashJoinProbe[4]-d_datekey-lo_orderdate-16, node id: 0
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-0
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-1
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-10
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-11
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-12
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-13
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-14
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-15
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-16
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-17
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-18
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-19
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-2
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-3
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-4
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-5
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-6
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-7
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-8
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-9
  Head: Shuffle[2]-HashJoinProbe[4]-d_datekey-lo_orderdate-17, node id: 1
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-0
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-1
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-10
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-11
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-12
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-13
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-14
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-15
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-16
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-17
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-18
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-19
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-2
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-3
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-4
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-5
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-6
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-7
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-8
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-9
  Head: Shuffle[2]-HashJoinProbe[4]-d_datekey-lo_orderdate-18, node id: 0
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-0
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-1
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-10
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-11
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-12
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-13
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-14
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-15
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-16
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-17
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-18
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-19
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-2
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-3
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-4
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-5
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-6
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-7
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-8
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-9
  Head: Shuffle[2]-HashJoinProbe[4]-d_datekey-lo_orderdate-19, node id: 1
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-0
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-1
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-10
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-11
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-12
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-13
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-14
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-15
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-16
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-17
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-18
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-19
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-2
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-3
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-4
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-5
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-6
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-7
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-8
     Sub: HashJoinProbe[2]-p_partkey-lo_partkey-9
  Head: Group[1]-0, node id: 0
     Sub: Sort[0]
  Head: Group[1]-1, node id: 1
     Sub: Sort[0]
  Head: Group[1]-2, node id: 0
     Sub: Sort[0]
  Head: Group[1]-3, node id: 1
     Sub: Sort[0]
  Head: Group[1]-4, node id: 0
     Sub: Sort[0]
  Head: Group[1]-5, node id: 1
     Sub: Sort[0]
  Head: Group[1]-6, node id: 0
     Sub: Sort[0]
  Head: Group[1]-7, node id: 1
     Sub: Sort[0]
  Head: Group[1]-8, node id: 0
     Sub: Sort[0]
  Head: Group[1]-9, node id: 1
     Sub: Sort[0]
  Head: Group[1]-10, node id: 0
     Sub: Sort[0]
  Head: Group[1]-11, node id: 1
     Sub: Sort[0]
  Head: Group[1]-12, node id: 0
     Sub: Sort[0]
  Head: Group[1]-13, node id: 1
     Sub: Sort[0]
  Head: Group[1]-14, node id: 0
     Sub: Sort[0]
  Head: Group[1]-15, node id: 1
     Sub: Sort[0]
  Head: Group[1]-16, node id: 0
     Sub: Sort[0]
  Head: Group[1]-17, node id: 1
     Sub: Sort[0]
  Head: Group[1]-18, node id: 0
     Sub: Sort[0]
  Head: Group[1]-19, node id: 1
     Sub: Sort[0]
  Head: Shuffle[1]-HashJoinProbe[2]-p_partkey-lo_partkey-0, node id: 0
     Sub: Group[1]-0
     Sub: Group[1]-1
     Sub: Group[1]-10
     Sub: Group[1]-11
     Sub: Group[1]-12
     Sub: Group[1]-13
     Sub: Group[1]-14
     Sub: Group[1]-15
     Sub: Group[1]-16
     Sub: Group[1]-17
     Sub: Group[1]-18
     Sub: Group[1]-19
     Sub: Group[1]-2
     Sub: Group[1]-3
     Sub: Group[1]-4
     Sub: Group[1]-5
     Sub: Group[1]-6
     Sub: Group[1]-7
     Sub: Group[1]-8
     Sub: Group[1]-9
  Head: Shuffle[1]-HashJoinProbe[2]-p_partkey-lo_partkey-1, node id: 1
     Sub: Group[1]-0
     Sub: Group[1]-1
     Sub: Group[1]-10
     Sub: Group[1]-11
     Sub: Group[1]-12
     Sub: Group[1]-13
     Sub: Group[1]-14
     Sub: Group[1]-15
     Sub: Group[1]-16
     Sub: Group[1]-17
     Sub: Group[1]-18
     Sub: Group[1]-19
     Sub: Group[1]-2
     Sub: Group[1]-3
     Sub: Group[1]-4
     Sub: Group[1]-5
     Sub: Group[1]-6
     Sub: Group[1]-7
     Sub: Group[1]-8
     Sub: Group[1]-9
  Head: Shuffle[1]-HashJoinProbe[2]-p_partkey-lo_partkey-2, node id: 0
     Sub: Group[1]-0
     Sub: Group[1]-1
     Sub: Group[1]-10
     Sub: Group[1]-11
     Sub: Group[1]-12
     Sub: Group[1]-13
     Sub: Group[1]-14
     Sub: Group[1]-15
     Sub: Group[1]-16
     Sub: Group[1]-17
     Sub: Group[1]-18
     Sub: Group[1]-19
     Sub: Group[1]-2
     Sub: Group[1]-3
     Sub: Group[1]-4
     Sub: Group[1]-5
     Sub: Group[1]-6
     Sub: Group[1]-7
     Sub: Group[1]-8
     Sub: Group[1]-9
  Head: Shuffle[1]-HashJoinProbe[2]-p_partkey-lo_partkey-3, node id: 1
     Sub: Group[1]-0
     Sub: Group[1]-1
     Sub: Group[1]-10
     Sub: Group[1]-11
     Sub: Group[1]-12
     Sub: Group[1]-13
     Sub: Group[1]-14
     Sub: Group[1]-15
     Sub: Group[1]-16
     Sub: Group[1]-17
     Sub: Group[1]-18
     Sub: Group[1]-19
     Sub: Group[1]-2
     Sub: Group[1]-3
     Sub: Group[1]-4
     Sub: Group[1]-5
     Sub: Group[1]-6
     Sub: Group[1]-7
     Sub: Group[1]-8
     Sub: Group[1]-9
  Head: Shuffle[1]-HashJoinProbe[2]-p_partkey-lo_partkey-4, node id: 0
     Sub: Group[1]-0
     Sub: Group[1]-1
     Sub: Group[1]-10
     Sub: Group[1]-11
     Sub: Group[1]-12
     Sub: Group[1]-13
     Sub: Group[1]-14
     Sub: Group[1]-15
     Sub: Group[1]-16
     Sub: Group[1]-17
     Sub: Group[1]-18
     Sub: Group[1]-19
     Sub: Group[1]-2
     Sub: Group[1]-3
     Sub: Group[1]-4
     Sub: Group[1]-5
     Sub: Group[1]-6
     Sub: Group[1]-7
     Sub: Group[1]-8
     Sub: Group[1]-9
  Head: Shuffle[1]-HashJoinProbe[2]-p_partkey-lo_partkey-5, node id: 1
     Sub: Group[1]-0
     Sub: Group[1]-1
     Sub: Group[1]-10
     Sub: Group[1]-11
     Sub: Group[1]-12
     Sub: Group[1]-13
     Sub: Group[1]-14
     Sub: Group[1]-15
     Sub: Group[1]-16
     Sub: Group[1]-17
     Sub: Group[1]-18
     Sub: Group[1]-19
     Sub: Group[1]-2
     Sub: Group[1]-3
     Sub: Group[1]-4
     Sub: Group[1]-5
     Sub: Group[1]-6
     Sub: Group[1]-7
     Sub: Group[1]-8
     Sub: Group[1]-9
  Head: Shuffle[1]-HashJoinProbe[2]-p_partkey-lo_partkey-6, node id: 0
     Sub: Group[1]-0
     Sub: Group[1]-1
     Sub: Group[1]-10
     Sub: Group[1]-11
     Sub: Group[1]-12
     Sub: Group[1]-13
     Sub: Group[1]-14
     Sub: Group[1]-15
     Sub: Group[1]-16
     Sub: Group[1]-17
     Sub: Group[1]-18
     Sub: Group[1]-19
     Sub: Group[1]-2
     Sub: Group[1]-3
     Sub: Group[1]-4
     Sub: Group[1]-5
     Sub: Group[1]-6
     Sub: Group[1]-7
     Sub: Group[1]-8
     Sub: Group[1]-9
  Head: Shuffle[1]-HashJoinProbe[2]-p_partkey-lo_partkey-7, node id: 1
     Sub: Group[1]-0
     Sub: Group[1]-1
     Sub: Group[1]-10
     Sub: Group[1]-11
     Sub: Group[1]-12
     Sub: Group[1]-13
     Sub: Group[1]-14
     Sub: Group[1]-15
     Sub: Group[1]-16
     Sub: Group[1]-17
     Sub: Group[1]-18
     Sub: Group[1]-19
     Sub: Group[1]-2
     Sub: Group[1]-3
     Sub: Group[1]-4
     Sub: Group[1]-5
     Sub: Group[1]-6
     Sub: Group[1]-7
     Sub: Group[1]-8
     Sub: Group[1]-9
  Head: Shuffle[1]-HashJoinProbe[2]-p_partkey-lo_partkey-8, node id: 0
     Sub: Group[1]-0
     Sub: Group[1]-1
     Sub: Group[1]-10
     Sub: Group[1]-11
     Sub: Group[1]-12
     Sub: Group[1]-13
     Sub: Group[1]-14
     Sub: Group[1]-15
     Sub: Group[1]-16
     Sub: Group[1]-17
     Sub: Group[1]-18
     Sub: Group[1]-19
     Sub: Group[1]-2
     Sub: Group[1]-3
     Sub: Group[1]-4
     Sub: Group[1]-5
     Sub: Group[1]-6
     Sub: Group[1]-7
     Sub: Group[1]-8
     Sub: Group[1]-9
  Head: Shuffle[1]-HashJoinProbe[2]-p_partkey-lo_partkey-9, node id: 1
     Sub: Group[1]-0
     Sub: Group[1]-1
     Sub: Group[1]-10
     Sub: Group[1]-11
     Sub: Group[1]-12
     Sub: Group[1]-13
     Sub: Group[1]-14
     Sub: Group[1]-15
     Sub: Group[1]-16
     Sub: Group[1]-17
     Sub: Group[1]-18
     Sub: Group[1]-19
     Sub: Group[1]-2
     Sub: Group[1]-3
     Sub: Group[1]-4
     Sub: Group[1]-5
     Sub: Group[1]-6
     Sub: Group[1]-7
     Sub: Group[1]-8
     Sub: Group[1]-9
  Head: Shuffle[1]-HashJoinProbe[2]-p_partkey-lo_partkey-10, node id: 0
     Sub: Group[1]-0
     Sub: Group[1]-1
     Sub: Group[1]-10
     Sub: Group[1]-11
     Sub: Group[1]-12
     Sub: Group[1]-13
     Sub: Group[1]-14
     Sub: Group[1]-15
     Sub: Group[1]-16
     Sub: Group[1]-17
     Sub: Group[1]-18
     Sub: Group[1]-19
     Sub: Group[1]-2
     Sub: Group[1]-3
     Sub: Group[1]-4
     Sub: Group[1]-5
     Sub: Group[1]-6
     Sub: Group[1]-7
     Sub: Group[1]-8
     Sub: Group[1]-9
  Head: Shuffle[1]-HashJoinProbe[2]-p_partkey-lo_partkey-11, node id: 1
     Sub: Group[1]-0
     Sub: Group[1]-1
     Sub: Group[1]-10
     Sub: Group[1]-11
     Sub: Group[1]-12
     Sub: Group[1]-13
     Sub: Group[1]-14
     Sub: Group[1]-15
     Sub: Group[1]-16
     Sub: Group[1]-17
     Sub: Group[1]-18
     Sub: Group[1]-19
     Sub: Group[1]-2
     Sub: Group[1]-3
     Sub: Group[1]-4
     Sub: Group[1]-5
     Sub: Group[1]-6
     Sub: Group[1]-7
     Sub: Group[1]-8
     Sub: Group[1]-9
  Head: Shuffle[1]-HashJoinProbe[2]-p_partkey-lo_partkey-12, node id: 0
     Sub: Group[1]-0
     Sub: Group[1]-1
     Sub: Group[1]-10
     Sub: Group[1]-11
     Sub: Group[1]-12
     Sub: Group[1]-13
     Sub: Group[1]-14
     Sub: Group[1]-15
     Sub: Group[1]-16
     Sub: Group[1]-17
     Sub: Group[1]-18
     Sub: Group[1]-19
     Sub: Group[1]-2
     Sub: Group[1]-3
     Sub: Group[1]-4
     Sub: Group[1]-5
     Sub: Group[1]-6
     Sub: Group[1]-7
     Sub: Group[1]-8
     Sub: Group[1]-9
  Head: Shuffle[1]-HashJoinProbe[2]-p_partkey-lo_partkey-13, node id: 1
     Sub: Group[1]-0
     Sub: Group[1]-1
     Sub: Group[1]-10
     Sub: Group[1]-11
     Sub: Group[1]-12
     Sub: Group[1]-13
     Sub: Group[1]-14
     Sub: Group[1]-15
     Sub: Group[1]-16
     Sub: Group[1]-17
     Sub: Group[1]-18
     Sub: Group[1]-19
     Sub: Group[1]-2
     Sub: Group[1]-3
     Sub: Group[1]-4
     Sub: Group[1]-5
     Sub: Group[1]-6
     Sub: Group[1]-7
     Sub: Group[1]-8
     Sub: Group[1]-9
  Head: Shuffle[1]-HashJoinProbe[2]-p_partkey-lo_partkey-14, node id: 0
     Sub: Group[1]-0
     Sub: Group[1]-1
     Sub: Group[1]-10
     Sub: Group[1]-11
     Sub: Group[1]-12
     Sub: Group[1]-13
     Sub: Group[1]-14
     Sub: Group[1]-15
     Sub: Group[1]-16
     Sub: Group[1]-17
     Sub: Group[1]-18
     Sub: Group[1]-19
     Sub: Group[1]-2
     Sub: Group[1]-3
     Sub: Group[1]-4
     Sub: Group[1]-5
     Sub: Group[1]-6
     Sub: Group[1]-7
     Sub: Group[1]-8
     Sub: Group[1]-9
  Head: Shuffle[1]-HashJoinProbe[2]-p_partkey-lo_partkey-15, node id: 1
     Sub: Group[1]-0
     Sub: Group[1]-1
     Sub: Group[1]-10
     Sub: Group[1]-11
     Sub: Group[1]-12
     Sub: Group[1]-13
     Sub: Group[1]-14
     Sub: Group[1]-15
     Sub: Group[1]-16
     Sub: Group[1]-17
     Sub: Group[1]-18
     Sub: Group[1]-19
     Sub: Group[1]-2
     Sub: Group[1]-3
     Sub: Group[1]-4
     Sub: Group[1]-5
     Sub: Group[1]-6
     Sub: Group[1]-7
     Sub: Group[1]-8
     Sub: Group[1]-9
  Head: Shuffle[1]-HashJoinProbe[2]-p_partkey-lo_partkey-16, node id: 0
     Sub: Group[1]-0
     Sub: Group[1]-1
     Sub: Group[1]-10
     Sub: Group[1]-11
     Sub: Group[1]-12
     Sub: Group[1]-13
     Sub: Group[1]-14
     Sub: Group[1]-15
     Sub: Group[1]-16
     Sub: Group[1]-17
     Sub: Group[1]-18
     Sub: Group[1]-19
     Sub: Group[1]-2
     Sub: Group[1]-3
     Sub: Group[1]-4
     Sub: Group[1]-5
     Sub: Group[1]-6
     Sub: Group[1]-7
     Sub: Group[1]-8
     Sub: Group[1]-9
  Head: Shuffle[1]-HashJoinProbe[2]-p_partkey-lo_partkey-17, node id: 1
     Sub: Group[1]-0
     Sub: Group[1]-1
     Sub: Group[1]-10
     Sub: Group[1]-11
     Sub: Group[1]-12
     Sub: Group[1]-13
     Sub: Group[1]-14
     Sub: Group[1]-15
     Sub: Group[1]-16
     Sub: Group[1]-17
     Sub: Group[1]-18
     Sub: Group[1]-19
     Sub: Group[1]-2
     Sub: Group[1]-3
     Sub: Group[1]-4
     Sub: Group[1]-5
     Sub: Group[1]-6
     Sub: Group[1]-7
     Sub: Group[1]-8
     Sub: Group[1]-9
  Head: Shuffle[1]-HashJoinProbe[2]-p_partkey-lo_partkey-18, node id: 0
     Sub: Group[1]-0
     Sub: Group[1]-1
     Sub: Group[1]-10
     Sub: Group[1]-11
     Sub: Group[1]-12
     Sub: Group[1]-13
     Sub: Group[1]-14
     Sub: Group[1]-15
     Sub: Group[1]-16
     Sub: Group[1]-17
     Sub: Group[1]-18
     Sub: Group[1]-19
     Sub: Group[1]-2
     Sub: Group[1]-3
     Sub: Group[1]-4
     Sub: Group[1]-5
     Sub: Group[1]-6
     Sub: Group[1]-7
     Sub: Group[1]-8
     Sub: Group[1]-9
  Head: Shuffle[1]-HashJoinProbe[2]-p_partkey-lo_partkey-19, node id: 1
     Sub: Group[1]-0
     Sub: Group[1]-1
     Sub: Group[1]-10
     Sub: Group[1]-11
     Sub: Group[1]-12
     Sub: Group[1]-13
     Sub: Group[1]-14
     Sub: Group[1]-15
     Sub: Group[1]-16
     Sub: Group[1]-17
     Sub: Group[1]-18
     Sub: Group[1]-19
     Sub: Group[1]-2
     Sub: Group[1]-3
     Sub: Group[1]-4
     Sub: Group[1]-5
     Sub: Group[1]-6
     Sub: Group[1]-7
     Sub: Group[1]-8
     Sub: Group[1]-9
  Head: Sort[0], node id: 0
     Sub: collate
  Head: collate, node id: 0
  Remote Spawn Op: FileScan_onRemote[8]-lineorder.tbl.6
  Remote Spawn Op: FileScan_onRemote[8]-lineorder.tbl.5
  Remote Spawn Op: FileScan_onRemote[8]-lineorder.tbl.7
  Remote Spawn Op: FileScan_onRemote[8]-lineorder.tbl.4
  Remote Spawn Op: FileScan_onRemote[3]-part.tbl
  Remote Spawn Op: FileScan_onRemote[5]-date.tbl
  Remote Spawn Op: FileScan_onRemote[8]-lineorder.tbl.8
  Remote Spawn Op: FileScan_onRemote[8]-lineorder.tbl.9
  Remote Spawn Op: FileScan_onRemote[7]-supplier.tbl
  ```

  