/************************************************************
    File Name : 56_I_数组中数字出现的次数.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-21 星期二 16:22:20
************************************************************/
/*先对所有数字进行一次异或，得到两个出现一次的数字的异或值。

在异或结果中找到任意为 1 的位。

根据这一位对所有的数字进行分组。所有包含这一位的一组，不包含这意味的一组。
故根据异或运算和与运算的性质这两组具有一下性质：
1.两个只出现一次的数字分别在两个组
2.相同的数字在一个组
在每个组内进行异或操作，得到两个数字。
*/
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int temp = 0;
        for (int x : nums) {
            temp ^= x;
        }
        int div = 1;
        while ((div & temp) == 0) {
            div <<= 1;
        }
        int a = 0, b = 0;
        for (int x : nums) {
            if (div & x) {
                a ^= x;
            } else {
                b ^= x;
            }
        }
        return vector<int> {a, b};
    }
};