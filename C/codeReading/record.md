# notes:  
*  unsigned shot 大端，小端存储问题, 计算机是小端， 相加也是硬件　　
*  存入的补码问题：存到电脑中就是补码，负数第一位不变，后面按位取反，然后最后一位加1。
    HDMI_FAST_MEM宏　定义在CMakeLists中，编译的区别，fast memory的方式其实在内核中进行了mmap, 更快。

*  lseek(int filde, off_t offset, int whence) 
　　修改文件的起始读写位置 
    offset: 偏移量;
    whence: SEEK_SET 将读写位置指向文件头后再增加offset个位移量　　

*  mmap(void* start, size_t length, int prot, int flags, in fd, off_t offset)
   返回：　成功时，返回被映射区域的指针．
   start：　映射区开始地址，　０系统决定．
   length: 
   prot: 内存保护标志　
   flags:
   fd: 文件描述符
   offset:　被映射对象内容的起点

* 因为C语言并没有规定int占多少字节，为了让代码在多个平台上运行，使用＿u32告诉别人，这个变量占４个字节．　　
* mmap返回１.真实的映射地址. 2. 错误;　　

* linux下 df命令，看盘容量  
* sudo fdisk -l 查看分区信息   

###  git flow 使用 
* git flow feature publish name    
push分支  

* git flow feature pull/track origin name  
获取新分支


###  log  
在 main 函数中添加头文件和函数。  
使用log_info() 方法如同printf()  

###  Linux指令  
* sync 
* 强制将缓存中的内容拷贝到磁盘中，确保文件成功保存在SD卡/硬盘中。  
* 关闭前运行两次 sync; 相机用reboot关闭，然后断电  

###  库文件  
.so -> .so.2 
.so.2 -> .so.2.3
* .so       编译时使用  
  .so.2     桌面图标，程序调用这个名称
  .so.2.3   真正的库，真正调用这个。 做demo时，将.so.2.3拷贝为.so.2以使用。
