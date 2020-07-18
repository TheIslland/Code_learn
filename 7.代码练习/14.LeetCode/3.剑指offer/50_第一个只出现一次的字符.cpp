/************************************************************
    File Name : 50_第一个只出现一次的字符.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-17 星期五 17:04:11
************************************************************/
class Solution {
public:
    char firstUniqChar(string s) {
        if (s.empty()) return ' ';
        int flag[26] = {0};
        for (int i = 0; i < s.length(); i++) {
            flag[s[i] - 'a']++;
        }
        for (int i = 0; i < s.length(); i++) {
            if (flag[s[i] - 'a'] == 1) return s[i];
        }
        return ' ';
    }
};