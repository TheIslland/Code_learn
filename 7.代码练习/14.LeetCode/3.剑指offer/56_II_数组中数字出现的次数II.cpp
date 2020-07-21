/************************************************************
    File Name : 56_II_数组中数字出现的次数II.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-21 星期二 17:44:59
************************************************************/
//位运算
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one = 0, two = 0;
        for (int x : nums) {
            one ^= (x & ~two);
            two ^= (x & ~one);
        }
        return one;
    } 
};
//按位统计
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int flag[32] = {0};
        for (int i = 0 ; i < nums.size(); i++) {
            unsigned int dig = 1;
            for (int j = 0; j < 32; j++) {
                if (dig & nums[i]) {
                    flag[j]++;
                }
                dig <<= 1;
            }
        }
        unsigned int dig = 1, ret = 0;
        for (int i = 0; i < 32; i++) {
            if (flag[i] % 3) {
                ret += dig;
            }
            dig <<= 1;
        }
        return ret;
    } 
};