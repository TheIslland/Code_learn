/************************************************************
    File Name : 382报数.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-01-08 星期三 19:39:46
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

int main() {
    queue<int> q;
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }
    while (q.size() > 1) {
        int cnt = m - 1;
        while (cnt--) {
            q.push(q.front());
            q.pop();
        }
        q.pop();
    }
    cout << q.front() << endl;
    return 0;
}