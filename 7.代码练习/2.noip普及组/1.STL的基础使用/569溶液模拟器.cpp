/************************************************************
    File Name : 569溶液模拟器.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-01-09 星期四 19:11:30
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
typedef struct NODE {
    int v;
    double c;
    NODE(int a, double b) : v(a), c(b){};
} Node;

int main() {
    int v0, c0, n, a, b;
    char op;
    cin >> v0 >> c0 >> n;
    stack<Node> s;
    s.push(Node(v0, c0));
    while (n--) {
        cin >> op;
        if (op == 'Z') {
            if (s.size() > 1) s.pop();
            printf("%d %.5lf\n", s.top().v, s.top().c);
        } else {
            cin >> a >> b;
            Node temp = s.top();
            s.push(Node(temp.v + a, (temp.v * temp.c + a * b) * 1.0 / 100.0 / (temp.v + a) * 100));
            printf("%d %.5lf\n", s.top().v, s.top().c);
        }
    }
    return 0;
}