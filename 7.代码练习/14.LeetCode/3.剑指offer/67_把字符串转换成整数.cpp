/************************************************************
    File Name : 67_把字符串转换成整数.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-18 星期六 11:24:48
************************************************************/
class Solution {
public:
    int strToInt(string s) {
        int flag = 1, i = 0;
        long long num = 0;
        while (s[i] == ' ') i++;
        if (s[i] == '+' ) i++;
        else if (s[i] == '-') {
            flag = -1;
            i++;
        }
        while (i < s.length()) {
            if (s[i] < '0' || s[i] > '9') break;
            num = num * 10 + s[i++] - '0';
            if (num > INT_MAX) {
                num = INT_MAX;
                return flag == 1 ? INT_MAX : INT_MIN;
            }
        }
        return flag * num;
    }
};