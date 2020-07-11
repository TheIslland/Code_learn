/************************************************************
    File Name : 580明明的随机数.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2019-12-19 星期四 18:44:31
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
    set<int> a;
    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> m;
        a.insert(m);
    }
	cout << a.size() << endl;
    set<int>::iterator it = a.begin();
    //(n) && (cout << *it++);
    for (; it != a.end(); it++) {
        cout << *it << " ";
    }
    return 0;
}