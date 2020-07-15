/************************************************************
    File Name : 15_二进制中1的个数.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-15 星期三 09:16:52
************************************************************/
//普通位运算
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while (n) {
            if (n & 1) ans++;
            n >>= 1;
        }
        return ans;
    }
};

//借位位运算 n & n - 1
//n - 1相当于向二进制左侧借一位n & n - 1后就减少了原二进制中的一位1，故有多少个1循环几次
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while (n) {
            ans++;
            n &= (m - 1);
        }
        return ans;
    }
};