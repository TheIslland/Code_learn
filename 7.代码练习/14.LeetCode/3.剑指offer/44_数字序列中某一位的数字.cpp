/************************************************************
    File Name : 44_数字序列中某一位的数字.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-18 星期六 19:46:53
************************************************************/
class Solution {
public:
    int findNthDigit(int n) {
        int i = 1;
        while (n > i * 0.9 * pow(10, i)) n -= i * 0.9 * pow(10, i), i++;
        string ret = to_string(pow(10, i - 1) + (n - 1) / i);
        return ret[(n - 1) % i] - '0'; 
    }
};