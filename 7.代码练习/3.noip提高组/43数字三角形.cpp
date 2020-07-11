/************************************************************
    File Name : 43数字三角形.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2019-12-28 星期六 18:05:42
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

int n;
int a[1005][1005];
int b[1005][1005];
int dfs(int i, int j) {
    if (b[i][j]) return b[i][j];
    if (i + 1 == n) return a[i][j];
    int x = dfs(i + 1, j);
    int y = dfs(i + 1, j + 1);
    b[i][j] = max(x, y) + a[i][j];
    return b[i][j];
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            cin >> a[i][j];
        }
    }
    cout << dfs(0, 0) << endl;
    return 0;
}