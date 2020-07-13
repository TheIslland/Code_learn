/************************************************************
    File Name : 括号匹配.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-13 星期一 09:31:11
************************************************************/
vector<pair<int, int> > bracketsPairs(string &str) {
    stack<int> s;
    vector<pair<int, int>> ret;
    int i = 0;
    while (str[i]) {
        if (str[i] == '(') s.push(i);
        else {
            if (s.size() == 0) return vector<pair<int, int>> {};
            ret.push_back(pair<int, int> (s.top() + 1, i + 1));
            s.pop();
        }
        i++;
    }
    if (s.size() != 0) return vector<pair<int, int>> {};
    return ret;
}