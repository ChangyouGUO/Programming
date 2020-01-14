# 文件的读写操作  
### I/O文件读写  
* fprintf() 和 fscanf() 第一个参数都是FILE的指针  


* fgets(buf, STLEN, fp) 
读取输入直到第一个换行符的后面，或文件结尾，或者stlen-1个字符。然后在后面加一个空字符。  
fgets()遇到EOF将返回NULL, 可以用于检查。 未遇到EOF则返回传给它的地址。  

* fputs(buf, fp)   
fputs()不会再添加换行符  


## 13.5  
----  
* int fseek(fp, offset, position)  
offset 是long类型，可以是正, 负, 0;  
正常，返回0； 错误，返回-1；
* long ftell(fp) 
返回的是当前位置到文件开头的距离，long类型。第一个字节到文件开始处的距离是0；  
处理范围20亿

* int fgetpos(FILE* , fpos_t *)  
正确0， 错误非0； fpos_t: 文件中的一个位置。 
* int fsetpos(FILE*, const fpos_t *)  
