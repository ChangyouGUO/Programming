#! /bin/bash

# shell 中的if与Ｃ语言不同，[条件为真时，即返回0], 条件返回0时，进入then的情况

# 1. -n, 字符串非空返回0(true)
if [ -n $(which python) ]; then
    echo "Have python!!!"
fi

# 2. 直接字符串，与-n操作相同
if [ $(which python) ]; then
    echo "Have python!!!"
fi

# 3. -z 字符串为空时, 返回0(true)
if [ -z $(pkg-config opencv) ]; then
    echo "Can't find opencv!!"
fi

# 4. 判断两个字符串是否相等，=
# if 两个判断条件
if [ -n $(pkg-config opencv) ] || [ $(which meld) = "/usr/bin/meld" ]; then
    echo "Have meld"
fi

# reference: https://blog.csdn.net/huangrunqing/article/details/51680164
