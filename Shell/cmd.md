# command

## 字符串操作

1. %  


> % 截取指定字符的左边的字符串  
> ${file}  ->  /filepath/coco.data.relative  
> ${file%.relative}  ->  /filepath/coco.data  

## 替换替换操作  

1. sed

<https://www.cnblogs.com/chismi/p/10055792.html>  

<http://c.biancheng.net/linux/sed.html>  

sed 的修改不会直接写入文件， 写入文件需要使用 > 重定向到文件中。  

sed -e 使得sed后可以接多个命令，顺序执行  
> $ sed -e ‘s/Beijing/London/g’ -e ‘/Beijing/d’ mysed.txt  

> sed “s/原始/现在” filename  
分割符号可以使用"/","^","?"  
s部分添加参数控制替换的位置, 结尾后添加处理整个文件   
特殊符号需要使用反斜杠\  

```shell
sed 's/^/添加的头部&/g' //在所有行首添加
sed 's/$/&添加的尾部/g' //在所有行末添加
sed '2s/原字符串/替换字符串/g' //替换第2行
sed '$s/原字符串/替换字符串/g' //替换最后一行
sed '2,5s/原字符串/替换字符串/g' //替换2到5行
sed '2,$s/原字符串/替换字符串/g' //替换2到最后一行
```

测试  
```sh
$ sed "s/\/home\/guo/\/home\/whowho/g" ./coco.data
classes = 80

valid = /home/whowho/moDisk/gCode/Programming/Shell/example_yolov3/5_file_for_test/image.txt
names = /home/whowho/moDisk/gCode/Programming/Shell/example_yolov3/5_file_for_test/coco.names

```
