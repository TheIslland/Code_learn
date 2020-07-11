/************************************************************
    File Name : 446回型方阵.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2019-12-05 星期四 19:42:00
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
    int n;
    int num[15][15] = {0};
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n - i; j++) {
            for (int k = i; k < n - i; k++) {
                num[j][k] = i + 1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << num[i][j];
            if (j < n - 1) cout << " ";
        }
        cout << endl;
    }
    return 0;
}
/*
int main() {
    int n, m, i, j, k;
    char a[15][15];
        cin >> n;
    for (i = 1; i <= n; i++) {
        for (j = i; j <= n - i + 1; j++) {
            for (k = i; k <= n - i + 1; k++) {
                a[j][k] = i;
            }
        }
    }
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (j - 1) cout << " ";
            printf("%d", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}*/