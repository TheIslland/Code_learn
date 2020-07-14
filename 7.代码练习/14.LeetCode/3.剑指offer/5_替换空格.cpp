/************************************************************
    File Name : 5_替换空格.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-14 星期二 10:33:06
************************************************************/
class Solution {
public:
    string replaceSpace(string s) {
        int i = 0, j = 0;
        string ans = "";
        while (s[i]) {
            if (s[i] == ' ') ans += "%20";
            else ans += s[i];
            i++;
        }
        return ans;
    }
};