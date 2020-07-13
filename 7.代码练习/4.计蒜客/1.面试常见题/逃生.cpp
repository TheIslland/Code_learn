/************************************************************
    File Name : 逃生.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-13 星期一 17:17:53
************************************************************/
int escape(vector<vector<int> > &maze, int n, int m,
				int initialHP, int maximumHP) {
    int dp[1005][1005] = {0};
    dp[0][1] = dp[1][0] = dp[0][0] = initialHP;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = (dp[i][j - 1] > dp[i - 1][j] ? dp[i][j - 1] : dp[i - 1][j]) + maze[i][j];
            dp[i][j] = (dp[i][j] > maximumHP ? maximumHP : dp[i][j]);
        }
    }
    return dp[n][m] > 0 ? dp[n][m] : -1;
}