#! /bin/bash

# -n     do not output the trailing newline
# -e     enable interpretation of backslash escapes

echo -en "Please pay attention\n"
echo -en "Be care!!!\n"

# reference: man echo

PY_PARAMS=--proxy=${http_proxy} -i https://pypi.mirrors.ustc.edu.cn/simple/ --root /

echo ${PY_PARAMS}