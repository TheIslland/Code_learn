/************************************************************
    File Name : 396填充颜色.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-03-17 星期二 20:13:30
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

int num[35][35];
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int n;

void dfs(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int x0 = x + dir[i][0], y0 = y + dir[i][1];
        if (x0 < 0 || x0 > n + 1 || y0 < 0 || y0 > n + 1) continue;
        if (num[x0][y0] == 0) {
            num[x0][y0] = 3;
            dfs(x0, y0);    
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> num[i][j];
        }
    }
    dfs(0, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (num[i][j] == 3)
                cout << 0;
            else if (num[i][j] == 1) 
                cout << 1;
            else
                cout << 2;
            if (j <= n - 1) cout << " ";
        }
        cout << endl;
    }

    return 0;
}