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
/*由数学分析可知，
推论二： 尽可能将绳子以长度 33 等分为多段时，乘积最大。

切分规则：
最优： 3 。把绳子尽可能切为多个长度为 3 的片段，留下的最后一段绳子的长度可能为 0,1,2 三种情况。
次优： 2 。若最后一段绳子长度为 2 ；则保留，不再拆为 1+1 。
最差： 1 。若最后一段绳子长度为 1 ；则应把一份 3 + 1 替换为 2 + 2，因为 2 * 2 > 3 * 1。
算法流程：
当 n≤3 时，按照规则应不切分，但由于题目要求必须剪成 m>1 段，因此必须剪出一段长度为 1 的绳子，即返回 n−1 。
当 n>3 时，求 n 除以 3 的 整数部分 a 和 余数部分 b （即 n=3a+b ），并分为以下三种情况（设求余操作符号为 "⊙" ）：
当 b = 0 时，直接返回 3^a ⊙1000000007；
当 b = 1 时，要将一个 1 + 3 转换为 2+2，因此返回 (3^{a-1} * 4) ⊙ 1000000007；
当 b = 2 时，返回 (3^a * 2) ⊙ 1000000007。
*/
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