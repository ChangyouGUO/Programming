"""测试os.makedirs()中 exist_ok 参数的影响
   详见代码内部实现
"""  
import os
path = "/home/guo/myDisk/Models/YOLOV3"
os.makedirs(path, exist_ok=True)