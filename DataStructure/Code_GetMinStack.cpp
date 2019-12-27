#include <iostream>
#include <stdio.h>
#include <stack>
#include <limits.h>

using namespace std;
class Stack {
private:
    stack<int> stackData;
    stack<int> stackMin;
public:
    void push(int value) {
        stackData.push(value);
        if(stackMin.empty()) {
            stackMin.push(value);
        } else {
            stackMin.push(value < stackMin.top() ? value : stackMin.top());
        }
    }  //push过程中，stackMin()可以只压入value <= stackMin.top()的值。弹出时，可以以stackData.top() == stackMin.top 进行stackMin的弹出

    void pop() { 
        if(stackData.empty()) {
            printf("stack is empty\n");
            return;
        }
        stackMin.pop();
        stackData.pop();  //STL中 pop()是不返回数值的
}

    int getMin() {
        if(stackMin.empty()) {
            printf("stack is empty\n");
            return INT_MIN;
        }
        return stackMin.top();
    }
};

int main(int argc, char** argv) {
    Stack s;
    s.push(25);
    s.push(20);
    s.push(15);
    s.push(25);
    s.push(5);
    s.push(26);
    int a;
    for(int i=0; i<5; i++) {
        a = s.getMin();
        s.pop();
        printf("Min number = %d\n", a);
    }
    return 0;
}