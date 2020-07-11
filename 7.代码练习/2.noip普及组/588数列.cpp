/************************************************************
    File Name : 588数列.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2019-12-19 星期四 14:09:16
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

string ans[35];
int main() {
    int n, i = 2;
    cin >> n;
    ans[0] = "1";
    ans[1] = "11";
    while (i < n) {
        int num = 1, k = 0;
        ans[i] = "";
        string temp = ans[i - 1];
        for (int j = 0; j <= temp.length() - 1; j++) {
            if (temp[j] == temp[j + 1]) {
                num++;
            } else {
                ans[i] += to_string(num) + to_string(temp[j] - '0');
                num = 1;
            }
        }
        i++;
    }
    cout << ans[n - 1] << endl;
    return 0;
}