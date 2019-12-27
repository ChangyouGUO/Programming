#include <stdio.h>
#include <iostream>
#include <stack>
#include <queue>
#include <limits.h>

using namespace std;

class  TwoStackQueue {
private:
    stack<int> stackpush;
    stack<int> stackpop;
public:
    void push(int value) {
        stackpush.push(value);
    }

    void pop() {
        if(stackpush.empty() && stackpop.empty()) {
            printf("stack is empty!!!\n");
            return;
        }
        if(stackpop.empty()) {
            while(stackpush.size() > 0) {
                stackpop.push(stackpush.top());
                stackpush.pop();
            }
        }
        stackpop.pop();
    }

    int top() {
        if(stackpush.empty() && stackpop.empty()) {
            printf("stack is empty!!!\n");
            return INT_MIN;
        }
        if(stackpop.empty()) {
            while(stackpush.size() > 0) {
                stackpop.push(stackpush.top());
                stackpush.pop();
            }
        }
        return stackpop.top();
    }
};

class TwoQueueStack {     
private: 
    queue<int> Queue;
    queue<int> help;
public: 
    void push(int value) {
        Queue.push(value);
    }

    void pop() {
        if(Queue.empty()) {
            printf("stack is empty!!!\n");
            return;
        }
        while(Queue.size() > 1) {
            help.push(Queue.front());
            Queue.pop();
        }
        Queue.pop();
        swap();
    }

    int top() {
        if(Queue.empty()) {
            printf("stack is empty!!!\n");
            return INT_MIN;
        }
        while(Queue.size() > 1) {
            help.push(Queue.front());
            Queue.pop();
        }
        int res = Queue.front();
        Queue.pop();
        swap();
        Queue.push(res);  //top还要把缺的补上
        return res;
    }

    void swap() {
        queue<int> tmp;
        tmp = Queue;
        Queue = help;
        help = tmp;
    }
};

int main(int argc, char** argv) {
    TwoStackQueue q;
    TwoQueueStack s;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    int a, b;
    for(int i=0; i<5; i++) {
        a = q.top();
        q.pop();
        b = s.top();
        s.pop();
        printf("queue top is %d, stack top is %d\n", a, b);
    }
    return 0;
}
