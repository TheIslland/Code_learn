/************************************************************
    File Name : 513楼层编号.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-01-10 星期五 20:37:03
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
int n, t, ans;

int check(int x) {
    while (x) {
        if (x % 10 == t) {
            return 1;
        }
        x /= 10;
    }
    return 0;
}

int main() {
    cin >> n >> t;
    ans = n;
    for (int i = 1; i <= n; i++) {
        ans -= check(i);
    }
    cout << ans << endl;
    return 0;
}