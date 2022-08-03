
## Steps:
### On each node:
1. Install Prerequisites - `sudo ./tools/project/bin/ubuntu-prerequisites.sh`.

### On master node:
Ensure master node has access to other nodes using ssh.
1. Generate Data:
+ For tpch, `./resources/script/tpch-data-gen.sh <scale-factor>`
+ For ssb, `./resources/script/tpch-data-gen.sh <scale-factor>`, and then enter `tpch-dbgen`, edit function `tbl_open` in `bm_utils.c`: append `0777` after O\_CREAT as the third param of open. Edit definition `MAXAGG_LEN` in `shared.h`: change `10` to `20`. Then run ssb again.
2. Edit `./resources/config/cluster_ips` (Make sure `127.0.0.1` is put for the master node).
3. Edit `RESOURCE_PATH` in `./fpdb-calcite/java/main/resources/config/exec.conf`.
4. Edit `deploy_dir_name` and `username` in `./resources/script/util.sh`.
5. Set up the system `./resources/script/setup.sh`. If all required dependencies are already installed, the system can also be set up by `./resources/script/build.sh -d`, `./resources/script/deploy.sh`.

#### Run:
1. `cd <deploy_dir_name>`.
2. Start the system `./resources/script/start.sh`.
3. `cd fpdb-main`.
4. Run tests. For tpch: `./fpdb-main-test -ts=tpch-sf1-distributed`. For ssb: `./fpdb-main-test -ts=ssb-sf1-single_node-no-parallells`
5. When finished, stop the system `./resources/script/stop.sh`.