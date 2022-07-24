#!/bin/bash

SF=$1
if [ -z "$SF" ]; then
    SF=1
fi

BASE_DIR="$HOME/Work"
FPDB_DIR="$BASE_DIR/FlexPushdownDB-Dev"
DATA_DIR="$FPDB_DIR/resources/metadata/ssb-sf$SF-sortlineorder/csv/data"

pushd $BASE_DIR
git clone https://github.com/electrum/ssb-dbgen.git
cd ssb-dbgen
make > /dev/null 2>&1
cp $FPDB_DIR/resources/script/ssb-data-gen.py .
echo "Generating data for scale factor $SF"
sudo python3 ./ssb-data-gen.py $SF
rm -rf $DATA_DIR
ln -s $BASE_DIR/ssb-dbgen/data/ssb-sf$SF $DATA_DIR
echo "Copied data to $DATA_DIR"
popd