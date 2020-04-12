#!/bin/bash

cd /home/guo/moDisk/backup/special-libs/Aarch64Libs

path=`pwd`
filelist=`ls ${path}`

for file in ${filelist}
do
    suffix='.so'
    filename=$(echo ${file} |awk -F ${suffix} '{print $1}')${suffix}

    echo ${filename}
    echo ${file}
    echo `ln -s ${file} ${filename}`
done
