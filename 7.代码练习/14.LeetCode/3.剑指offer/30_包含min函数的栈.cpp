/************************************************************
    File Name : 30_包含min函数的栈.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-16 星期四 09:39:56
************************************************************/
//第一版
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> save_stack, min_stack;
    MinStack() {
        while (save_stack.size()) save_stack.pop();
        while (min_stack.size()) min_stack.pop();
    }
    
    void push(int x) {
        save_stack.push(x);
        if (min_stack.empty()) min_stack.push(x);
        else if (min_stack.top() < x) min_stack.push(min_stack.top());
        else min_stack.push(x);
        return ;
    }
    
    void pop() {
        int flag = save_stack.top();
        save_stack.pop();
        min_stack.pop();
        return ;
    }
    
    int top() {
        return save_stack.top();
    }
    
    int min() {
        return min_stack.top();
    }
};


//优化， 对于当前最小栈，只有当栈空或栈顶小于等于新元素时最小栈入栈，对于出栈时只有当两站顶相等时最小栈出栈
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> save_stack, min_stack;
    MinStack() {
        while (save_stack.size()) save_stack.pop();
        while (min_stack.size()) min_stack.pop();
    }
    
    void push(int x) {
        save_stack.push(x);
        if (min_stack.empty() || min_stack.top() >= x) min_stack.push(x);
        return ;
    }
    
    void pop() {
        if (save_stack.top() == min_stack.top()) min_stack.pop();
        save_stack.pop();
        return ;
    }
    
    int top() {
        return save_stack.top();
    }
    
    int min() {
        return min_stack.top();
    }
};