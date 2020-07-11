/************************************************************
    File Name : 514火柴棒等式.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-01-11 星期六 14:28:51
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

int a[2223] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6},
    b[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int get_num(int n) {
    int ans = 0;
    if (!n) return 6;
    while (n) {
        ans += b[n % 10];
        n /= 10;
    }
    return ans;
}

int main() {
    int n, ans = 0;
    cin >> n;
    if (n < 4) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i <= 2222; i++) {
        a[i] = get_num(i);
    }
    for (int i = 0; i <= 1111; i++) {
        for (int j = 0; j <= 1111; j++) {
            if ((n - 4 - a[i] - a[j]) == a[i + j]) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}