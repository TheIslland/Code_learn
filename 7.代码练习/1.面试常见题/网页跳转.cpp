/************************************************************
    File Name : 网页跳转.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-13 星期一 10:02:14
************************************************************/

stack<string> s[2];
string visitPage(string &url) {
    s[0].push(url);
    while (s[1].size() != 0) s[1].pop();
    return url;
}
string back() {
    if (s[0].size() <= 1) return "Ignore";
    s[1].push(s[0].top());
    s[0].pop();
    return s[0].top();
}
string forward() {
    if (s[1].size() == 0) return "Ignore";
    s[0].push(s[1].top());
    s[1].pop();
    return s[0].top();
}