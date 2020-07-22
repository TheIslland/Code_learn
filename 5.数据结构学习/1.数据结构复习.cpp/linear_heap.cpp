/************************************************************
    File Name : linear_heap.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-22 星期三 14:07:53
************************************************************/
#include <ctime>
#include <iostream>

using namespace std;

class Heap {
   public:
    Heap() {
        data = (int *)malloc(sizeof(int) * 2);
        cnt = 1;
        size = 2;
        reject = false;
    }
    Heap(int num) {
        if (num < 2)
            size = 2;
        else
            size = num + 2;
        data = (int *)malloc(sizeof(int) * size);
        cnt = 1;
        reject = false;
    }
    void expand() {
        int *old = data;
        size *= 2;
        data = (int *)malloc(sizeof(int) * size);
        for (int i = 1; i <= cnt; i++) {
            data[i] = old[i];
        }
    }
    void downUPdata(int ind) {
        while ((ind << 1) <= cnt) {
            int temp = ind, l = ind << 1, r = ind << 1 | 1;
            if (data[temp] < data[l]) temp = l;
            if (r <= cnt && data[temp] < data[r]) temp = r;
            if (temp == ind) break;
            swap(data[temp], data[ind]);
            ind = temp;
        }
        return;
    }
    void push(int val) {
        if (cnt + 1 >= size) {
            expand();
        }
        data[++cnt] = val;
        reject = true;
        //在有必要返回front,或者删除堆顶元素之前，不会进行线性建堆
        //只有在需要返回front,或者删除堆顶元素，建堆或调整后再次压入元素之后会进行线性建堆
    }
    void build_heap() {
        for (int i = cnt >> 1; i > 0; i--) {
            downUPdata(i);
        }
    }
    bool empty() { return cnt == 0; }
    int front() {
        if (empty()) return -1;
        //build_node 如果用线性建堆实现优先队列，可以在front之前进行线性建堆，每次的
        if (reject) build_heap(),reject = false;
        return data[1];
    }
    void pop() {
        if (empty()) return;
        if (reject) build_heap(), reject = false;
        swap(data[1], data[cnt]);
        cnt--;
        downUPdata(1);
        return;
    }
   public:
    int *data;
    int cnt, size;
    bool reject;
};

int main() {
    srand(time(0));
    Heap q = Heap();
    #define MAX_OP 20
    for (int i = 0; i < MAX_OP; i++) {
        q.push(rand() % 100);
    }
    //q.build_heap();
    for (int i = 0; i < MAX_OP; i++) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    return 0;
}