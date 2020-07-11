/************************************************************
    File Name : 566上网统计.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-01-09 星期四 15:48:55
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
    int n, m, cnt = 0;
    string str1, str2;
    cin >> n >> m;
    map<string, int> map1;
    vector<vector<string>> v(n);
    for (int i = 0; i < m; i++) {
        cin >> str1 >> str2;
        if (!map1.count(str1)) {
            v[cnt].push_back(str1);
            map1[str1] = cnt++;
        }
        v[map1[str1]].push_back(str2);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << (j < v[i].size() - 1 ? " " : "");
        }
        cout << endl;
    }
    return 0;
}