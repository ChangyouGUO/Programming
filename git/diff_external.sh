#! /bin/bash

# 配置客户端git diff使用的对比工具为meld
path=$(dirname "${BASH_SOURCE[0]}")

if [ -n "$(which meld)" ]; then
    git config --global diff.external ${path}/git_meld.sh
fi

#reference https://blog.csdn.net/iteye_4474/article/details/82479547
