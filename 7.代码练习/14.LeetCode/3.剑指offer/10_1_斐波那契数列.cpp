/************************************************************
    File Name : 10_1_斐波那契数列.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-14 星期二 14:39:52
************************************************************/
class Solution {
public:
    typedef long long ll;
    int fib(int n) {
        if (n < 2) return n;
        ll ans[105] = {0};
        ans[0] = 0, ans[1] = 1;
        for (int i = 2; i <= n; i++) {
            ans[i] = (ans[i - 1] + ans[i - 2]) % 1000000007;
        }
        return ans[n];
    }
};