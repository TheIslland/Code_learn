/************************************************************
    File Name : 380大统领投票.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-01-10 星期五 16:02:02
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

typedef struct Node {
    int id;
    string name;
    Node(){};
    Node(int val, string str) : id(val), name(str){};
} Node;

bool cmp(const Node &a, const Node &b) {
    if (a.name.length() == b.name.length()) {
        return a.name > b.name;
    }
    return a.name.length() > b.name.length();
}
int main() {
    int n;
    string str;
    cin >> n;
    vector<Node> v;
    for (int i = 1; i <= n; i++) {
        cin >> str;
        v.push_back(Node(i, str));
    }
    sort(v.begin(), v.end(), cmp);
    cout << v[0].id << endl << v[0].name;
    return 0;
}