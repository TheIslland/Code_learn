/************************************************************
    File Name : 587环.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2019-12-19 星期四 15:26:34
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
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    if (a < b) {
        if (c < b && c > a)
            printf("0");
        else
            printf("1");
    } else {
        if (c > b && c < a)
            printf("1");
        else
            printf("0");
    }
    return 0;
}