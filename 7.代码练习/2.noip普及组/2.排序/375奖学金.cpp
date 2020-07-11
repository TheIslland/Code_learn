/************************************************************
    File Name : 375奖学金.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-01-10 星期五 18:24:12
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

typedef struct Student {
    int id, code, sum;
    Student(){};
    Student(int a, int b, int c) : id(a), code(b), sum(c){};
} Stu;

bool cmp(const Stu &a, const Stu &b) {
    if (a.sum == b.sum) {
        if (a.code == b.code) {
            return a.id < b.id;
        }
        return a.code > b.code;
    }
    return a.sum > b.sum;
}

int main() {
    int n, m, code, sum;
    cin >> n;
    vector<Stu> arr;
    for (int i = 1; i <= n; i++) {
        cin >> code;
        sum = code;
        for (int i = 0; i < 2; i++) {
            cin >> m;
            sum += m;
        }
        arr.push_back(Stu(i, code, sum));
    }
    sort(arr.begin(), arr.end(), cmp);
    for (int i = 0; i < 5; i++) {
        cout << arr[i].id << " " << arr[i].sum << endl;
    }
    return 0;
}