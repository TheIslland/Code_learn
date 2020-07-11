/************************************************************
    File Name : 386.吃瓜群众.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-01-10 星期五 15:21:08
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
    int m, n, x;
    map<int, int> map1;
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        cin >> x;
        map1[x] = i;
    }
    for (int i = 1; i <= n; i++) {
        cin >> x;
        cout << map1[x] << endl;
    }
    return 0;
}