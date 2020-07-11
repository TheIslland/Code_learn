/************************************************************
    File Name : 53最大因子和.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2019-12-27 星期五 18:01:33
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

#define MAX_N 1000000

int prime[MAX_N + 5];
int num[MAX_N + 5];
int fnum[MAX_N + 5];
int ans = -1;
void init() {
    for (int i = 2; i <= MAX_N; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            num[i] = 1 + i;
            fnum[i] = 1 + i;
        }
        for (int j = 1; j <= prime[0] && i * prime[j] <= MAX_N; j++) {
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                num[i * prime[j]] = num[i] * prime[j] + 1;
                fnum[i * prime[j]] = fnum[i] / num[i] * (num[i] * prime[j] + 1);
                fnum[i * prime[j]] > ans && (ans = fnum[i * prime[j]]);
                break;

            } else {
                num[i * prime[j]] = 1 + prime[j];
                fnum[i * prime[j]] = fnum[prime[j]] * fnum[i];
                fnum[i * prime[j]] > ans && (ans = fnum[i * prime[j]]);
            }
        }
    }
}

int main() {
    init();
    cout << ans << endl;
    return 0;
}