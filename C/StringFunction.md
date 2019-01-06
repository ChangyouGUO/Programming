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