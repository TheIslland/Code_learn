/************************************************************
    File Name : 14_1_剪绳子.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-14 星期二 20:10:28
************************************************************/
//由于绳子至少分为两段，所以递推相当于在max(max(dp[i][n - i], i * n - i), dp[i])
class Solution {
public:
    int cuttingRope(int n) {
        int dp[60] = {0};
        if (n < 2) return 0;
        dp[2] = 1;
        for (int i = 3; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                dp[i] = max(max(j * (i - j), j * dp[i - j]), dp[i]);
            }
        }
        return dp[n];
    }
};

//快速幂
class Solution {
public:
    typedef long long ll;
    ll quick_pow(ll a, ll b) {
        long long res = 1;
        while(b > 0){
            if(b & 1)
                res = res * a;
            a = a * a;
            b >>= 1;
        }
        return res;
    }
    int cuttingRope(int n) {
        if (n <= 3) return n - 1;
        int a = n % 3, b = n / 3;
        if (a == 0) {
            return quick_pow(3, b);
        } else if (a == 2) {
            return quick_pow(3, b) * 2;
        } else {
            return quick_pow(3, b - 1) * 4;
        }
    }
};