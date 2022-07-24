#!/bin/bash

SF=$1
if [ -z "$SF" ]; then
    SF=1
fi

BASE_DIR="$HOME/Work"
FPDB_DIR="$BASE_DIR/FlexPushdownDB-Dev"
DATA_DIR="$FPDB_DIR/resources/metadata/tpch-sf$SF/csv/data"

pushd $BASE_DIR
git clone https://github.com/electrum/tpch-dbgen.git
cd tpch-dbgen
make > /dev/null 2>&1
cp $FPDB_DIR/resources/script/tpch-data-gen.py .
echo "Generating data for scale factor $SF"
sudo python3 ./tpch-data-gen.py $SF
rm -rf $DATA_DIR
ln -s $BASE_DIR/tpch-dbgen/data/tpch-sf$SF $DATA_DIR
echo "Copied data to $DATA_DIR"
popd