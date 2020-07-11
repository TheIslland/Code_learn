/************************************************************
    File Name : 207评奖2.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2019-12-14 星期六 15:25:53
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

struct Stu {
    string name;
    int sum;
};

bool cmp(struct Stu a, struct Stu b) { return a.sum > b.sum; }

int main() {
    int n, m, max = 0, min = 101;
    string name;
    struct Stu a[40];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> name;
        int temp = 0;
        for (int j = 0; j < 4; j++) {
            cin >> m;
            temp += m;
            m > max && (max = m);
            m < min && (min = m);
        }
        cout << temp << endl;
        struct Stu b = {name, temp};
        a[i] = b;
    }
    sort(a, a + n, cmp);
    cout << a[0].name << endl;
    cout << max << " " << min << endl;
    return 0;
}