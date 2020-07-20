/************************************************************
    File Name : queue.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-19 星期天 20:42:23
************************************************************/
#include <iostream>

using namespace std;

template <typename Type>
class queue {
   public:
    queue() {
        data = (Type *)malloc(sizeof(Type));
        head = 0;
        tail = 0;
        length = 0;
        size = 1;
    }
    queue(int num) {
        data = (Type *)malloc(sizeof(Type) * num);
        head = 0;
        tail = 0;
        length = 0;
        size = num;
    }
    ~queue() { free(data); }
    void expand() {
        Type *old = data;
        size *= 2;
        data = (Type *)malloc(sizeof(Type) * size);
        if (head <= tail) {
            for (int i = 0; i < length; i++) {
                data[i] = old[(head + i) % size];
            }
        } else {
            for (int i = 0; i < length; i++) {
                data[i] = old[(head + i) % size];
            }
        }
        head = 0;
        tail = length;
    }
    bool empty() { return length == 0; }
    bool push(Type val) {
        if (length == size) {
            expand();
        }
        data[tail] = val;
        tail = (tail + 1) % size;
        length++;
        return true;
    }

    bool pop() {
        if (empty()) return false;
        head++;
        head %= size;
        return true;
    }

   private:
    Type *data;
    int head, tail, length, size;
};

int main() { return 0; }