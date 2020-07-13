/************************************************************
    File Name : 1.规范化名字.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-02-10 星期一 10:54:13
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
    int n;
    cin >> n;
    string str[105];
    for (int i = 0; i < n; i++) {
        cin >> str[i];
        transform(str[i].begin(), str[i].begin() + 1, str[i].begin(), ::toupper);
        transform(str[i].begin() + 1, str[i].end(), str[i].begin() + 1, ::tolower);
    }
    sort(str, str + n);
    for (int i = 0; i < n; i++) {
        cout << str[i] << endl;
    }
    return 0;
}