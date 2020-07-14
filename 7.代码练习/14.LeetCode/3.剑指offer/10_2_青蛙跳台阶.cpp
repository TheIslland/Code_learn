/************************************************************
    File Name : 10_2_青蛙跳台阶.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-14 星期二 14:45:58
************************************************************/
class Solution {
public:
    typedef long long ll;
    int numWays(int n) {
        ll ans[105] = {0};
        ans[0] = 1, ans[1] = 1, ans[2] = 2;
        for (ll i = 3; i <= n; i++) {
            ans[i] = (ans[i - 1] + ans[i - 2]) % 1000000007;
        }
        return ans[n];
    }
};