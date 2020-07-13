/************************************************************
    File Name : 维护栈的最小值.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-13 星期一 11:21:59
************************************************************/

vector<int> stackMinimumValues(vector<string> &operation,
                                   vector<int> &value) {
    vector<int> ret;
    stack<int> s[2];
    for (int i = 0; i < operation.size(); i++) {
        if (operation[i] == "push") {
            s[1].push(value[i]);
            if (s[0].size() == 0) {
                ret.push_back(value[i]);                   
                s[0].push(value[i]);
            } else if (value[i] < s[0].top()) {
                ret.push_back(value[i]);                   
                s[0].push(value[i]);
            } else {
                ret.push_back(s[0].top());                   
                s[0].push(s[0].top()); 
            }
        } else {
            while (s[0].top() == s[1].top()) s[0].pop(); 
            ret.push_back(s[0].top());
            s[1].pop();
        }
    }
    return ret;
    
}