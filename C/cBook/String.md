sizeof 以字节单位给出对象的大小   
strlen() 函数给出字符串中的字符结果 包含在string.h的头文件中

```bash 
char name[40]; 
scanf("%s", name); 
```
从终端读取输入，保存在name中   

```bash
#define PI 3.14
#define TEE 'T'
#define OOPS "Now you have done it"
```
符号常量 表示数值，字符，字符串

```bash
printf("%2d\n", PAGES);
```   
默认输出为两字段宽度， 如果PAGES大于2字段，输出长度自动拓展   

```bash
printf("%10d\n", PAGES);
printf("%-10d\n", PAGES);
```   
默认输出10字段宽度， 默认PAGES长度不够， 右对齐。 加 - 后，作对齐。  
