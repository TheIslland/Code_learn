/************************************************************
    File Name : 取数字.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-13 星期一 15:44:09
************************************************************/
int pickMaxSum(vector<vector<int> > &nums) {
    int len = nums.size();
	int dp[102][102] = {0};
    dp[1][1] = nums[0][0];
    for (int i = 2; i <= len; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = (dp[i - 1][j] > dp[i - 1][j - 1] ? dp[i - 1][j] : dp[i - 1][j - 1]) + nums[i - 1][j - 1];
        }
    }
    int max = -0x3f3f3f3f;
    for (int i = 1; i <= len; i++) {
        if (dp[len][i] > max) max = dp[len][i];
    }
    return max;
}