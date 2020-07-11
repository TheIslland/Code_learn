/************************************************************
    File Name : 56第n组排列.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2019-12-27 星期五 19:38:14
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
int a[10];
int main() {
    int n = 0, x, y;
    cin >> x >> y;
    for (int i = 0; i < x; i++) {
        a[i] = i + 1;
    }
    do {
        n++;
        if (n == y) break;
    } while (next_permutation(a, a + x));
    for (int i = 0; i < x; i++) {
        cout << a[i];
    } return 0;
}