#   Chapter 11 String and String function   
## string -- char array  

* char words[MAXLENGTH] = "I am a string in an array";
* const char *pt1 = "Something is pointing at me.";
*  
* puts("Here are some strings");
* puts(MSG); // #define MSG "I am a symbolic string constant"  
* puts(words);  
* puts(pt1);  
puts() 函数属于stdio.h系列的输入/输出函数。与printf()不同, pusts()函数只显示字符串，并自动在显示的字符串末尾加上换行符。  

* 双引号中的字符和编译器自动加入末尾的\0字符, 都作为字符串存储在内存中。
* 字符串间的空隔，忽略；内部使用双引号，要用\ 反斜杠。  
