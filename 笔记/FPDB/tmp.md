+ 先将S3换成server，再换成smartNIC
+ **AVX2**：intel cpu 的SIMD
+ **NEON**：ARM的SIMD，smartNIC
+ TODO：
  + CSV to apache arrow(AVX2加速了这玩意，移除所有AVX2，与硬件无关)
  + NEON怎么加速上述流程？
+ VSCode可以远程连接server，直接用C++(VSCode remote debug)
+ main：入口
+ 可以参口S3GetPOp的ifdef的else的流程，去捋一下代码，但是有bug
+ executor：filescanpop.cpp
+ 先理清楚总体代码流程，再看operator，最后CSV转化
+ physical脱离了S3(本次工作环境)，S3没脱离

+ Yifei Yang与源码是一样的

# 踩过的坑

+ vscode remote无法创建文件
  + chmod给权限即可。一般是爆无法mkdir \.vscode-server，直接创建然后chmod 777给权限即可
+ source: not found
  + 执行`ls -l /bin/sh`命令，若得到结果`/bin/sh -> dash`，则说明shell的解释器为dash。此时，需要执行`sudo dpkg-reconfigure dash`命令，然后选择no。再次执行`ls -l /bin/sh`命令，若得到结果`/bin/sh -> bash`，则说明成功更改shell的解释器为bash。
+ make的时候无法运行可能原因
  + copy的时候忘记把build给删了
+ 无法读取到文件
  + 权限问题，移到test下即可
+ read()时报Error reading zstream，溯源：
  + ArrowAWSGZIPInputStream2.cpp的Read()
+ /usr/bin/cmake -E copy\_directory无法复制
  + 对于新的metadata，不能直接复制原有的，最好重新生成文件夹、文件，否则就可能爆这个错误，而且非常难以定位

# 部署

+ client：hefei，server：tianjin

+ 在client端开始编译，`sudo ./resources/script/setup.sh`
+ 在client端启动system，`sudo ./resources/script/start.sh`
+ 在server端开启server，进入到`FPDB-build/fpdb-main/fpdb-main`下调用`sudo ./fpdb-main-server`。如果已经被占用，需要kill掉。

+ 在client端开启测试，`sudo ./fpdb-main-test -ts=tpch-sf1-distributed`

# gitlab

+ http://47.95.115.215/database-group/flexpushdown-db，zhikang，zhikang123456

# 登录

+ root@47.95.115.215，boss@g410
+ huazhang@128.105.146.58，123456
+ huazhang@archon.cs.washington.edu，huazhang0119
+ server：partho@tianjin.cs.washington.edu，123456
+ client：
  + partho@hefei.cs.washington.edu，123456
  + partho@fujian.cs.washington.edu，123456