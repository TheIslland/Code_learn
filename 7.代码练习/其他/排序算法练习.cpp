/************************************************************
    File Name : 排序算法练习.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-03-11 星期三 15:33:10
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

#define SWAP(a, b)              \
    {                           \
        __typeof(a) __temp = a; \
        a = b;                  \
        b = __temp;             \
    }

void insert_sort(int *a, int n) {
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0 && a[j] < a[j - 1]; j--) {
            SWAP(a[j], a[j - 1]);
        }
    }
}

void buble_sort(int *a, int n) {
    int judg = 1;
    for (int i = 1; i < n && judg; i++) {
        judg = 0;
        for (int j = 0; j < n - i; j++) {
            if (a[j] > a[j + 1]) {
                SWAP(a[j], a[j + 1]);
                judg = 1;
            }
        }
    }
}

void select_sort(int *a, int n) {
    for (int i = 0; i < n; i++) {
        int low = i;
        for (int j = i; j < n; j++) {
            if (a[j] < a[low]) low = j;
        }
        SWAP(a[i], a[low]);
    }
}

void shell_sort(int *a, int n) {
    int ind = 2;
    for (int icnr = n / ind; icnr > 0; icnr /= ind) {
        for (int i = 0; i < icnr; i++) {
            for (int j = i + icnr; j < n; j += icnr) {
                for (int k = j; k > i && a[k] < a[k - icnr]; k -= icnr) {
                    SWAP(a[k], a[k - icnr]);
                }
            }
        }
    }
}

int pattern(int *a, int L, int R) {
    int l = L, r = R;
    while (l < r) {
        while (l < r && a[l] <= a[r]) l++;
        SWAP(a[l], a[r]);
        while (l < r && a[l] <= a[r]) r--;
        SWAP(a[l], a[r]);
    }
    return r;
}

void quick_sort(int *a, int l, int r) {
    if (l >= r) return;
    int mid = pattern(a, l, r);
    quick_sort(a, l, mid - 1);
    quick_sort(a, mid + 1, r);
    return;
}

int main() {
    srand(time(0));
    int num[21];
    for (int i = 0; i < 21; i++) {
        num[i] = rand() % 100;
    }
    quick_sort(num, 0, 21);
    for (int i = 0; i < 21; i++) {
        cout << num[i] << " ";
    }
    cout << endl;
    return 0;
}