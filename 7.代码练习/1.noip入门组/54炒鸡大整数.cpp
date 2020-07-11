/************************************************************
    File Name : 54炒鸡大整数.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2019-12-21 星期六 18:19:53
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
int ans[3000];
int ans1[3000];
void mul(int x) {
    memset(ans, 0, sizeof(int) * 3000);
    ans[0] = 1;
    ans[1] = 1;
    for (int i = 1; i <= x; i++) {
        for (int j = 1; j <= ans[0]; j++) {
            ans[j] *= i;
        }
        for (int j = 1; j <= ans[0]; j++) {
            if (ans[j] < 10) continue;
            ans[j + 1] += ans[j] / 10;
            ans[j] = ans[j] % 10;
            ans[0] += (j == ans[0]);
        }
    }
    memset(ans1, 0, sizeof(int) * 3000);
    ans1[0] = 1;
    ans1[1] = 1;
    for (int i = 1; i <= ans[0]; i++) {
        if (!ans[i]) continue;
        for (int j = 1; j <= ans1[0]; j++) {
            ans1[j] *= ans[i];
        }
        for (int j = 1; j <= ans1[0]; j++) {
            if (ans1[j] < 10) continue;
            ans1[j + 1] += ans1[j] / 10;
            ans1[j] = ans1[j] % 10;
            ans1[0] += (j == ans1[0]);
        }
    }
    for (int i = ans1[0]; i >= 1; i--) {
        cout << ans1[i];
    }
}

int main() {
    int x;
    while (scanf("%d", &x) != EOF) {
        mul(x);
        cout << endl;
    }
    return 0;
}