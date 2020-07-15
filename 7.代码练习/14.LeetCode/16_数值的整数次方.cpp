/************************************************************
    File Name : 16_数值的整数次方.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-15 星期三 10:07:45
************************************************************/
class Solution {
public:
    typedef long long ll;
    double myPow(double x, int y) {
        if (x == 0 || x == 1) return x; 
        ll n = y;
        if (n < 0) x = 1 / x, n = -n;
        double res = 1.0;
        while (n) {
            if(n & 1) res *= x;
            x *= x;
            n >>= 1;
        }
        return res;
    }
};