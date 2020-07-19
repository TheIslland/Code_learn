/************************************************************
    File Name : 63_股票的最大利润.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-19 星期天 14:46:44
************************************************************/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        int l = 0, ans = 0;
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] - prices[l] > ans) ans = prices[i] - prices[l];
            if (prices[i] < prices[l]) l = i;
        }
        return ans;
    }
};