#include <stdio.h>
#include <iostream>
#include <limits.h>

using namespace std;

/*
    报错怎么输出？
*/

class Stack {
private:
    int* array;  //数组
    int size;    //数组尺寸
    int index;   //等待填写位置，push直接使用，pop使用index下一位置

public:
    Stack(int num) {
        if(num <= 0) {
            printf("stack size should larger than 0!!!");
            return;
        }
        size = num;
        index = 0;
        array = (int*)malloc(size*sizeof(int));
    }

    void push(int value) {
        if(index >= size) {
            printf("stack is full");
            return;
        }
        array[index++] = value; 
    }
    int pop() {
        if(index <= 0) {
            printf("stack is empty!!!\n");
            return NULL;
        }
        return array[--index];
    }

    int top() {
        if(index <= 0) {
            printf("stack is empty!!!\n");
            return NULL;
        }
        return array[index-1];
    }
    int stacksize() {
        return index;
    }
};

class Queue {
private: 
    int* array;
    int size;
    int first;
    int last;
    int signal;  //signal用于记录现在队列中的数值数量，省去循环时的纠结
public:
    Queue(int num) {
        if(num <= 0) {
            printf("stack size should larger than 0!!!\n");
            return;
        }
        size = num;
        first = 0;
        last = 0;
        signal = 0;
        array = (int*)malloc(size*sizeof(int));
    }
    void push(int value) {
        if(signal == size) {
            printf("Queue is full\n");
            return;
        }
        signal++;   //第一步，先把数组内数量的多少记录下来
        array[last] = value;
        last = last == size-1 ? 0 : last+1;    //这样写 push和pop的写法相似； 不能用last++， ++last可以但是不好
    }   
    int pop() {
        if(signal == 0) {
            printf("Error: queue is empty\n");
            return NULL;
        }
        signal--;
        int tmp = array[first];
        first = first == size-1? 0: first+1;
        return tmp;
    }
    int top() {
        if(signal == 0) {
            printf("Error: queue is empty\n");
            return NULL;
        }
        return array[first];
    }
};

int main(int argc, char** argv) {
    Stack s(10);
    s.push(100);
    int a = s.pop();
    int b = s.top();
    int c = s.stacksize();
    Queue q(10);
    q.push(1);
    q.push(2);
    a = q.top();
    b = q.pop();

    return 0;
}