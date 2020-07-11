/************************************************************
    File Name : 579相似的数集.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2019-12-19 星期四 19:19:40
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
    int n, m;
    cin >> n;
    vector<int> num[n];
    for (int i = 0; i < n; i++) {
        cin >> m;
        int temp;
        for (int j = 0; j < m; j++) {
            cin >> temp;
            num[i].push_back(temp);
        }
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b, sum = 0;
        cin >> a >> b;
        set<int> s, note;
        a--, b--;
        for (int j = 0; j < num[a].size(); j++) {
            if (s.find(num[a][j]) == s.end()) {
                s.insert(num[a][j]);
            } else {
                if (note.find(num[a][j]) == note.end()) note.insert(num[a][j]);
            }
        }
        for (int j = 0; j < num[b].size(); j++) {
            if (s.find(num[b][j]) == s.end()) {
                s.insert(num[b][j]);
            } else {
                if (note.find(num[a][j]) == note.end()) note.insert(num[a][j]);
            }
        }
        cout << s.size() << " " << note.size() << endl;

        cout << s.size() * 100.0 / (s.size() - sum) << "%" << endl; 
    }
    return 0;
}