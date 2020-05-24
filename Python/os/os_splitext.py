#! /usr/bin/python
#-*- coding:utf-8 -*-

import os

# 按照.切除文件名称
# 适合同路径下，文件尾缀相关替换

path = "/home/guo/moDisk/model_weight/yolov3_official/yolov3.weights"
print(os.path.splitext(path))
print("save model predict to {}.png".format(os.path.splitext(path)[0]))