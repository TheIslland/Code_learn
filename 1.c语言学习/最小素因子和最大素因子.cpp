/************************************************************
    File Name : 最小素因子和最大素因子.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2019-12-17 星期二 19:56:47
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

#define MAX_N 10000

int prime[MAX_N + 5];
int min_prime[MAX_N + 5];
int max_prime[MAX_N + 5];
void init() {
    for (int i = 2; i <= MAX_N; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            min_prime[i] = i;
        }
        for (int j = 1; j <= prime[0] && i * prime[j] <= MAX_N; j++) {
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                if (min_prime[i] == 0) min_prime[i] = prime[j];
                // max_prime[i] = prime[j];
                break;
            }
        }
    }
}
void init_1() {
    for (int i = 2; i <= MAX_N; i++) {
        if (prime[i]) continue;
        for (int j = i; j <= MAX_N; j += i) {
            if (min_prime[j]) continue;
            min_prime[j] = i;
        }   
}


void init_2() {
    for (int i = 2; i <= MAX_N; i++) {
        if (prime[i]) continue;
        for (int j = i; j <= MAX_N; j += i) {
            max_prime[j] = i;
        }   
}
int main() {
    init();
    for (int i = 2; i <= 15; i++) {
        cout << i << " min prime is " << min_prime[i] << endl;
    } return 0;
}