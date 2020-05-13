#! /bin/bash

# BASH_SOURCE[0] 自身文件名
# dirname 文件路径
# $()命令替换，拿到命令的输出
# ${} 变量替换
# >/dev/null 忽略标准输出
# 进入文件上一层目录，
ML_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null && pwd )"

# 定义环境变量
export ML_DIR 
# 输出信息
echo ML_DIR is $ML_DIR

if [ ! -d $ML_DIR/caffe-master/ ]; then

    # Uncompress all the ```*.tar.gz``` files in the repository, 
    tar -xvf caffe-master.tar.gz 
    tar -xvf darknet_origin.tar.gz
    #split yolov3_deploy.tar.gz yolov3.tar.gz.parta -b 24MB    
    cat yolov3_deploy.tar.gz.partaa* > yolov3_deploy.tar.gz
    tar -xvf yolov3_deploy.tar.gz
    rm yolov3_deploy.tar.gz.*
    cd example_yolov3/5_file_for_test/
    tar -xvf calib_data.tar 
    cd ../../

# Run the following commands from the working directory:
    # find -type 文件类型， -name/-iname 匹配
    # xargs 将输入切段，重复执行
    find . -type f -name "*.txt"   -print0 | xargs -0 dos2unix
    find . -type f -name "*.data"  -print0 | xargs -0 dos2unix
    find . -type f -name "*.cfg"   -print0 | xargs -0 dos2unix
    find . -type f -name "*.names" -print0 | xargs -0 dos2unix

# Set the path in the coco.data.relative  file, placed in the example_yolov3/5_file_for_test/ folder
# Set the test images path in the image.txt.relative file, placed in the example_yolov3/5_file_for_test/) folder
    # sed -e 单行替换， 用 > 将结果写入到文件
    for file in $(find $ML_DIR -iname "*.relative"); do
	sed -e "s^PATH_TO^$ML_DIR^" ${file} > ${file%.relative}
    done

else
    echo "ALREADy DONE"