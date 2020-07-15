/************************************************************
    File Name : 17_打印从1到n的最大n位数.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-15 星期三 11:05:29
************************************************************/
class Solution {
public:
    vector<int> printNumbers(int n) {
        if(n < 1) return vector<int> {};
        vector<int> ans;
        int temp = 10;
        while (--n) {
            temp *= 10;
        }
        for (int i = 1; i < temp; i++) ans.push_back(i);
        return ans;
    }
};