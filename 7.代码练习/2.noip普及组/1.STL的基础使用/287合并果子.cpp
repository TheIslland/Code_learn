/************************************************************
    File Name : 287合并果子.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-01-09 星期四 15:04:46
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
typedef long long ll;

struct cmp {
    bool operator()(const ll &a, const ll &b) { return a > b; }
};
int main() {
    priority_queue<ll, vector<ll>, cmp> q;
    ll n, m, sum, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> m;
        q.push(m);
    }
    while (q.size() > 1) {
        sum = q.top();
        q.pop();
        sum += q.top();
        q.pop();
        q.push(sum);
        ans += sum;
    }
    cout << ans << endl; 
    return 0;
}