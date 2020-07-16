/************************************************************
    File Name : 31_栈的压入弹出序列.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-16 星期四 10:42:58
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
    
    return 0;
}class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int l2 = 0, r1 = pushed.size() - 1, r2 = popped.size() - 1;
        for (int i = 0; i <= r1; i++) {
            s.push(pushed[i]);
            while (l2 <= r2 && s.size() && s.top() == popped[l2]) {
                s.pop();
                l2++;
            }
        }
        return s.empty();
    }
};