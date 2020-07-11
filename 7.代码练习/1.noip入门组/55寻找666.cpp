/************************************************************
    File Name : 55寻找666.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2019-12-27 星期五 19:34:00
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
    int y1, y2, m1, m2, d1, d2, ans = 0;
    cin >> y1 >> m1 >> d1;
    cin >> y2 >> m2 >> d2;
    if (m1 < 6) y1++;
    else if (d1 < 6) y1++;
    if (m2 < 6) y2--;
    else if (d2 < 6) y2--;
    for (int i = y1; i <= y2; i++) {
        if (((22 + i + i / 4 - i / 100 + i / 400) % 7 + 1) == 6) ans++;
    }
    cout << ans << endl;
    return 0;
}