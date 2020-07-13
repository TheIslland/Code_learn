/************************************************************
    File Name : 最长公共子序列.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-13 星期一 18:54:57
************************************************************/
int lengthOfLCS(string &str1, string &str2) {
    int dp[1005][1005] = {0};
    int len1 = str1.size(), len2 = str2.size(), ans = 0;
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            dp[i][j] = (dp[i - 1][j] > dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1]);
            if (str1[i - 1] == str2[j - 1]) dp[i][j] = (dp[i - 1][j - 1] + 1 > dp[i][j] ? dp[i - 1][j - 1] + 1 : dp[i][j]);
            ans = (ans > dp[i][j] ? ans : dp[i][j]);
        }
    }
    return ans;
}