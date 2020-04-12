#!/bin/bash  

"https://blog.csdn.net/shenhuxi_yu/article/details/79788760"

# 1,首先从源代码生成目标文件(预处理,编译,汇编)，"-c"选项表示不执行链接步骤。
# $(CC) $(CPPFLAGS) $(CFLAGS) example.c   -c   -o example.o
# 2,然后将目标文件连接为最终的结果(连接)，"-o"选项用于指定输出文件的名字。
# $(CC) $(LDFLAGS) example.o   -o example
# 有一些软件包一次完成四个步骤：
# $(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) example.c   -o example

# CFLAGS与CPPFLAGS
# https://www.orcode.com/question/642550_k439e9.html

# LDFLAGS, LIBS区别
# LDFLAGS告诉链接器去哪里吃，LIBS告诉链接器吃什么  
# https://blog.csdn.net/jfkidear/article/details/8262260


# 交叉编译时，可以指明lib的搜索路径，不混用本机的lib。路径用：分割
# 终端运行，只在本终端窗口中生效  
# 指明路径
export LD_LIBRARY_PATH="/opt/env/lib"
# 添加路径
export LD_LIBRARY_PATH="${LD_LIBRARY_PATH}:/opt/env/lib"
# 生效
sudo ldconfig

# 删除之前编译的所有文件
make distclean

# 进入编译的文件夹, 绝对路径
cd /home/guo/..

# 某些库需要进行文件生成  
./autogen.sh


# configure 检查配置，配置makefile.
# 预处理，编译，汇编,链接(LDFLAGS)

# --prefix 指定install的路径, 注意shell的书写要求，\后不能有空格. 一定要有统一的安装路径，减少后期库之间的依赖报错
# --host 交叉编译时使用，指明执行代码工作的平台, --build 编译环境默认是本机x86_64.只有指明--host,使得host与build不同时，是交叉编译

# CC c语言编译器
# CXX c++编译器

# CPPFLAGS 预处理器参数,头文件位置. 预处理阶段(#include).

# CFLAGS C编译器选项参数，头文件位置. 编译，汇编阶段.
# CXXFLAGS C++编译器选项参数，头文件位置. 编译，汇编阶段.

# LDFLAGS 链接参数，指明lib路径.
# LIBS 链接参数，表示链接什么库

# 其他请参考configure --help

./configure --prefix=/opt/... \
--host=arm-linux-gnu \
CC=/home/guo/...../arm-linux-gnu-gcc \
CXX=/home/guo/....../arm-linux-gnu-g++ \
CPPFLAGS="-I/opt/env/include" \
LDFLAGS="-L/opt/env/lib -L/opt/env/lib64 -WL,R/opt/env/lib64"
LIBS+="-lpthread -lglib"
CFLAGS="-I/opt/env/include" \
CXXFLAGS="-I/opt/env/include"

make
# 注意之间必须的空格
if [ $? -eq 0 ]; then
# 安装在某些路径上时，需要权限
    make install
else
    echo -e "\n\t make fail \n"
fi



