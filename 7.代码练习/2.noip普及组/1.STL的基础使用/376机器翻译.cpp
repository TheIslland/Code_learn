/************************************************************
    File Name : 376机器翻译.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-01-08 星期三 20:33:40
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

using namespace std;

int main() {
    int m, n, x, ans = 0;
    cin >> m >> n;
    queue<int> q;
    set<int> set1;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (!set1.count(x)) {
            ans++;
            if (set1.size() > m - 1) {
                set1.erase(q.front());
                q.pop();
            } 
            q.push(x);
            set1.insert(x);
        } 
    }
    cout << ans << endl;
    return 0;
}