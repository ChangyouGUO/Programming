###  Chapter 14

> 结构名并不是结构的地址，要在结构名前面加上&运算符(非常重要)  
> 结构体数组，在用指针的时候应该：  
> - struct guy * him  
> - him = &fellow[0];    

> .运算符比*运算符的优先级高    

> 如果结构中存在 指针变量，在初始化结构时，要确保指针所指的变量是初始化完成的，其在内存中是被安全存放的。  
> 所以这里首先使用malloc() 分配一块内存， 将指针赋给结构体中。使用结束后，使用free()函数直接释放指针即刻。  

> 读写使用fprintf(),scanf()不方便，使用fwrite() 或 fread()  

> typedef 有些地方与define相似，但是typedef只能用于类型定义。  
> 特殊的是 typedef char* Char 将是指针类型， define 只是简单替换, 非常重要。
> - STRING name, sign;

> - typedef char * STRING;  
> - == char* name, *sign;  

> - #define STRING char*
> - == char* name, sign;  

> typedef 命名一个结构类型时，可以省略该结构的标签：
> - type struct {  
    double x;  
    double y;  
    } rect;  
> 可以直接使用rect定义结构体变量   

> 14.13节 展示了很多复杂的声明，值得回顾  

> 14.14节 函数指针，指向函数的指针