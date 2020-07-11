/************************************************************
    File Name : 70丑数.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2019-12-06 星期五 17:52:59
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

int prime[1005];

void init() {
    for (int i = 2; i <= 1000; i++) {
        if (prime[i]) continue;
        for (int j = i; j <= 1000; j += i) {
            prime[j] = i;
        } }
}

int main() {
    init();
    int n;
    cin >> n;
    cout << "1" << endl;
    for (int i = 2; i <= n; i++) {
        (prime[i] == 2 || prime[i] == 3 || prime[i] == 5) &&
            (cout << i << endl);
    }
    return 0;
}

/*//方法一
int judg(int i, int a) {
    while (i % a == 0) i /= a;
    return i;
}

int main() {
    int n;
    cin >> n;
    cout << 1 << endl;
    int a[3] = {2, 3, 5};
    for (int i = 2; i <= n; i++) {
        int temp = i;
        for (int j = 0; j < 3; j++) {
            temp = judg(temp, a[j]);
            if(temp == 1) {
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}
*/
/*//方法二：
int prime[1005];

void init() {
    for (int i = 2; i * i < 1005; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
        }
        for (int j = 1; j <= prime[0] && i * prime[j] < 1005; j++) {
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}

int main() {
    init();
    int n;
    cin >> n;
    //cout << prime[4] << endl;
    n >= 1 && cout << 1 << endl;
    for (int i = 2; i <= n; i++) {
        int flag = 1;
        for (int j = 4; j <= prime[0] && flag; j++) {
            if (i % prime[j] == 0) flag = 0;
        }
        if (!flag) continue;
        if (i % 2 == 0 || i % 3 == 0 || i % 5 == 0) {
            cout << i << endl;
        }
    }
    return 0;
}
*/