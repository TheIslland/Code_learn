/************************************************************
    File Name : 379仓库日志.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-01-08 星期三 19:02:23
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
typedef long long ll;
using namespace std;

int main() {
    int n, x, y;
    cin >> n;
    stack<ll> stack1;
    set<ll> set1;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (!x) {
            cin >> y;
            stack1.push(y);
            set1.insert(y);
        } else if (x == 1) {
            if (stack1.empty() || !set1.size()) continue;
            set1.erase(stack1.top());
            stack1.pop();
        } else {
            cout << (!set1.size() ? 0 : *(--set1.end())) << endl;
        }
    }
    return 0;
}