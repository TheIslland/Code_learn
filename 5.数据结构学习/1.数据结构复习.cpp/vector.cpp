/************************************************************
    File Name : vector.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-19 星期天 20:26:30
************************************************************/
#include <iostream>

using namespace std;
template <typename Type>
class Vector {
   public:
    Node() {
        SIZE = 1;
        len = 0;
        data = (Type*)malloc(sizeof(Type));
    }
    Node(int val) {
        SIZE = val;
        len = 0;
        data = (Type*)malloc(sizeof(Type) * SIZE);
    }
    bool empty() { return len == 0; }
    bool expand() {
        Type* old = data;
        SIZE *= 2;
        data = (Type*)malloc(sizeof(Type) * SIZE);
        if (data == NULL) {
            data = old;
            return false;
        }
        for (int i = 0; i < len; i++) {
            data[i] = old[i];
        }
        return true;
    }
    bool push_back(Type val) {
        if (len == SIZE) {
            if (expand() == false) return false;
        }
        data[len++] = val;
        return true;
    }
    bool insert(Type val, int ind) {
        if (ind < 0 || ind > SIZE) return false;
        if (len == SIZE) {
            if (expand() == false) return false;
        }
        for (int i = len; i > ind; i--) {
            data[i] = data[i - 1];
        }
        data[ind] = val;
        len++;
        return true;
    }

    int search(Type val) {
        for (int i = 0; i < len; i++) {
            if (data[i] == val) return i;
        }
        return -1;
    }

    bool delete_node(int ind) {
        if (ind < 0 || ind >= len) return false;
        for (int i = ind + 1; i < len; i++) {
            data[i - 1] = data[i];
        }
        len--;
        return 
    }
    ~Node() { if (data) free(data); }
   private:
    Type* data;
    int len, SIZE;
};
int main() {
}