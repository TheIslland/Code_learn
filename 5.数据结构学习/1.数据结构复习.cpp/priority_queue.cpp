/************************************************************
    File Name : priority_queue.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-22 星期三 09:38:05
************************************************************/
#include <ctime>
#include <iostream>

using namespace std;
//采用数组逻辑堆实现优先队列
class priority_queue {
   public:
    priority_queue() {
        data = (int *)malloc(sizeof(int) * 2);
        cnt = 1;
        size = 2;
    }
    priority_queue(int num) {
        if (num < 2) size = 2;
        else size = num + 1;
        data = (int *)malloc(sizeof(int) * size);
        cnt = 1;
    }
    void expand() {
        int *old = data;
        size *= 2;
        data = (int *)malloc(sizeof(int) * size);
        for (int i = 1; i <= cnt; i++) {
            data[i] = old[i];
        }
        return;
    }
    void push(int val) {
        if (cnt + 1 >= size) {
            expand();
        }
        data[++cnt] = val;
        int ind = cnt;
        while (ind >> 1 && data[ind] > data[ind >> 1]) {
            swap(data[ind], data[ind >> 1]);
            ind >>= 1;
        }
        return;
    }
    bool empty() { return cnt == 0; }
    int front() {
        if (empty()) return -1;
        return data[1];
    }
    void pop() {
        if (empty()) return;
        swap(data[1], data[cnt]);
        cnt--;
        int ind = 1;
        while ((ind << 1) <= cnt) {
            int temp = ind, l = ind << 1, r = ind << 1 | 1;
            if (data[temp] < data[l]) temp = l;
            if (r <= cnt && data[temp] < data[r]) temp = r;
            if (temp == ind) break;
            swap(data[ind], data[temp]);
            ind = temp;
        }
        return;
    }
   public:
    int *data;
    int cnt, size;
};
int main() {
    srand(time(0));
    priority_queue q = priority_queue();
    #define MAX_OP 20
    for (int i = 0; i < MAX_OP; i++) {
        q.push(rand() % 100);
    }
    for (int i = 0; i < MAX_OP; i++) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    return 0;
}