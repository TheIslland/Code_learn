/************************************************************
    File Name : 449杨辉三角形.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-01-08 星期三 17:04:03
************************************************************/

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <string>
typedef long long ll;
using namespace std;
#define SWAP(a, b)         \
    {                      \
        __typeof(a) c = a; \
        a = b;             \
        b = c;             \
    }
int main() {
    int n;
    int a[21][21] = {0};
    a[0][0] = 1;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (j - 1) cout << " ";
            a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
            cout << a[i][j];
        }
        cout << endl;
    }
    return 0;
}
