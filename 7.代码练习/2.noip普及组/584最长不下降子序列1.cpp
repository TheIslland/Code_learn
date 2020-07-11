/************************************************************
    File Name : 584最长不下降子序列1.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2019-12-19 星期四 15:30:02
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
    int n, m, ans = 0, sum = 0;
    stack<int> a;
    cin >> n;
    (n) && (cin >> m, a.push(m), ans++, sum++);
    for (int i = 1; i < n; i++) {
        cin >> m;
        if (a.top() > m) {
            ans = (sum > ans ? sum : ans);
            sum = 0;
        } else sum++;
        cout << "i = " << i << " sum = " << sum << endl;
        a.push(m);
    }
    cout << ans << endl;
    return 0;
}