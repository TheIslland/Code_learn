/************************************************************
    File Name : 9_两个栈实现队列.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-14 星期二 14:27:32
************************************************************/
class CQueue {
private:
    stack<int> s1, s2;
public:
    CQueue() {
        
    }
    
    void appendTail(int value) {
        s1.push(value);
        return ;
    }
    
    int deleteHead() {
        if (s1.empty() && s2.empty()) return -1;
        if (s2.empty()) {
            while (s1.size()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int ret = s2.top();
        s2.pop();
        return ret;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */