/************************************************************
    File Name : 577讲话模式.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-01-09 星期四 19:43:54
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
#include <sstream>
#include <stack>
#include <string>

using namespace std;

typedef struct Node {
    string name;
    int val;
    Node() {};
    Node(string str, int v) : name(str), val(v){};
} Node;

bool cmp (const Node &a, const Node &b) {
    if (a.val == b.val) return a.name < b.name;
    return a.val > b.val;
}

int main() {
    string str;
    vector<Node> v;
    int i = 0;
    map<string, int> map1;
    getline(cin, str);
    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 32;
        } else if (str[i] < 'a' || str[i] > 'z') {
            str[i] = ' ';
        }
    }
    stringstream linestream(str);
    string sub;
    while (linestream >> sub) {
        if (map1.count(sub))
            map1[sub]++;
        else
            map1[sub] = 1;
    }
    map<string, int> :: iterator it; 
    for (it = map1.begin(); it != map1.end(); it++) {
        v.push_back(Node(it->first, it->second));
    }
    sort(v.begin(), v.end(), cmp);
    cout << v[i].name << " " << v[i].val << endl;
    return 0;
}