/************************************************************
    File Name : 384敲七.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-01-08 星期三 19:53:32
************************************************************/
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>

using namespace std;

void init(queue<int> &q, int n) {
    while (n--) {
        q.push(q.front());
        q.pop();
    }
}

bool check(int x) {
    if (x % 7 == 0) return true;
    while (x) {
        if (x % 10 == 7) return true;
        x /= 10;
    }
    return false;
}
int main() {
    queue<int> q;
    int n, x, t;
    cin >> n >> x >> t;
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }
    init(q, x - 1);
    while (q.size() > 1) {
        if (!check(t++)) q.push(q.front());
        q.pop();
    }
    cout << q.front() << endl;
    return 0;
}