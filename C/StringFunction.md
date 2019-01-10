#   Chapter 11 String and String function   
## string -- char array  

* char words[MAXLENGTH] = "I am a string in an array";
* const char *pt1 = "Something is pointing at me.";

* puts("Here are some strings");
* puts(MSG); // #define MSG "I am a symbolic string constant"  
* puts(words);  
* puts(pt1);  
puts() 函数属于stdio.h系列的输入/输出函数。与printf()不同, pusts()函数只显示字符串，并自动在显示的字符串末尾加上换行符。  

-----
* 双引号中的字符和编译器自动加入末尾的\0字符, 都作为字符串存储在内存中。
* 字符串间的空隔，忽略；内部使用双引号，要用\ 反斜杠。  

----
* 初始化 const char ml[40] = "Limit yourself to one line's worth.";  
* 数组名是这个数组开头地址的常量。而指针是变量。  
*  数组拿到的是字符串的副本，指针指向字符串(可能是原本)的头地址.    
-----
* 11.2  
* 字符串输入前第一件事是 分配空间。char name[81]
* 读取： scanf("%s", name);  printf("%s", name)   只能读取一个单词。
* gets() 读取整行输入，遇到换行符，弃掉换行符，保存其余字符并添加空字符。puts()显示字符串在结尾添加换行符。

*      758  
* gets()的严重缺点是： 只要一个字符数组指针，并不知道输入的长度，这就导致容易缓冲区溢出。 buffer overflow 出现 segmentation fault 说明程序试图访问未分配的内存。
* gets()已经被C11标准抛弃。

* fgets() / gets_s() 后者是stdio.h的可选扩展，C11的编译器不一定支持。

* fgets()/fputs()  专门用于处理文件输入  

1.9  
* 空字符'\0' 标记C字符串末尾的字符，对应的ascii码为0;
* 空指针NULL 返回一个有效地址表示某些特殊情况发生。
* 两者都可以用0值表示，但是空字符是一个字符，1字节；空指针一个地址，4字节。  

* C库提供了处理字符串的函数，C把这些函数的原型放在string.h头文件中。  
* strlen() 返回字节长度  
* strcat() 拼接两个字符串，将第二个接在第一个字符串上，返回指向第一个字符串的指针。 长度空间不够，会溢出。
* strncat() 最后一位指定添加的最大长度，在末尾后再加上'\0'
* strcmp()函数比较的是字符串，不是字符。char类型实际上是整数类型。 
* strncmp()  多一个参数，比较前几个字符。 strncmp(char* , char* , n)  
* strcpy(dest, src), 将第二个拷贝到第一个中，记忆： 赋值语句。  
* strncpy

* sprintf()函数 声明在stdio.h中。 该函数第一个是字符串地址，其余与printf非常相似，只是将打印的保存为字符串。  
* P819 中总结了C库中的函数