/************************************************************
    File Name : 最长不上升子序列.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-13 星期一 17:47:45
************************************************************/
int lengthOfLNIS(vector<int> &nums) {
    int dp[1005] = {0};
	int sum = -1;
    for (int i = 0; i < nums.size(); i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (nums[i] <= nums[j]) dp[i] = (dp[i] > dp[j] + 1 ? dp[i] : dp[j] + 1);
        }
        sum = (sum > dp[i] ? sum : dp[i]);
    }
    return sum;
}