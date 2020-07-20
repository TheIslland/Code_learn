/************************************************************
    File Name : stack.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-19 星期天 21:17:18
************************************************************/
#include <iostream>

using namespace std;

template <typename Type>
class stack {
   public:
    stack() {
        data = (Type *)malloc(sizeof(Type));
        top = -1;
        SIZE = 1;
    }
    stack(int num) {
        SIZE = num;
        data = (Type *)malloc(sizeof(Type) * SIZE);
        top = -1;
    }
    ~stack() { free(data); }
    bool empty() { return top == -1; }
    int size() { return SIZE; }
    void expand() {
        Type *old = data;
        SIZE *= 2;
        data = (Type *)malloc(sizeof(Type) * SIZE);
        for (int i = 0; i <= top; i++) {
            data[i] == old[i];
        }
    }
    bool push(Type val) {
        if (top + 1 == SIZE) {
            expand();
        }
        data[++top] = val;
        return true;
    }
    bool pop() {
        if (empty()) return false;
        top--;
    }

   private:
    Type *data;
    int top, SIZE;
};
int main() { return 0; }