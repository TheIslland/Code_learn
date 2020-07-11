/************************************************************
    File Name : 378字符串括号匹配2.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-01-08 星期三 17:17:41
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

int main() {
    string str;
    int flag = 1;
    stack<char> s;
    cin >> str;
    for (int i = 0; str[i]; i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            s.push(str[i]);
        } else if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
            if (s.empty()) {
                flag = 0;
                break;
            }
            if ((str[i] == ')' && s.top() == '(') || (str[i] == ']' && s.top() == '[') || (str[i] == '}' && s.top() == '{')){
                s.pop();
            } else {
                flag = 0;
                break;
            }
        }
    }
    if (!s.empty()) flag = 0;
    cout << (flag ? "YES" : "NO") << endl;
    return 0;
}