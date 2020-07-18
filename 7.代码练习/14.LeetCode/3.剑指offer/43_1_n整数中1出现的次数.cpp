/************************************************************
    File Name : 43_1_n整数中1出现的次数.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-18 星期六 19:04:44
************************************************************/
class Solution {
public:
    typedef long long ll;
    int get_high_digit(string str, int len, int index) {
        string x = str.substr(0, len - index);
        if (x != "\0") return stoi(x);
        else return 0;
    }
    int get_low_digit(string str, int len, int index) {
        string x = str.substr(len - index + 1);
        if (x != "\0") return stoi(x);
        else return 0;
    }
    int countDigitOne(int n) {
        string str = to_string(n);
        int index = 1, ans = 0, len = str.length();
        while (index <= len) {
            int judg = str[len - index] - '0';
            if (judg > 1) {
                ans += (get_high_digit(str, len, index) + 1) * pow(10, index - 1);
            } else if (judg == 1) {
                ans += get_high_digit(str, len, index) * pow(10, index - 1) + get_low_digit(str, len, index) + 1;
            } else {
                ans += get_high_digit(str, len, index) * pow(10, index - 1);
            }
            index++;
        }
        return ans;
    }
};
/*具体思路：
因为是要求所有情况下1出现的次数，所以可以将该问题分解成每个位置上1出现的次数，最后将每个位置上出现的次数求和。
假设i为数字n从低到高的第i位，比第i位高的称为高位，比第i位低的称为低位。分情况讨论第i位置上的数。

当i位置上的数字大于1时
第i位置1，此时低位部分的每一个位置都可以取到0-9，所以次数为
(高位数字大小+1)*10^(i-1)
上述公式中加1是高位全0的情况

当i位置上的数字等于1时
此时分成两种情况讨论

高位取最大值数值。这时低位部分的每个位置不能取到0-9，低位的个数为 低位数字大小+1. 因此1出现的次数为 1*（低位数字大小+1）。加1也是全为0的情况。
高位不取最大值。这时低位部分是可取到0-9的，所以1出现的次数为 （高位数字大小-1+1)*10^(i-1)
综上，当i位置上的数字为1时，出现的总次数为：
高位数字大小 *10^(i-1)+低位数字大小+1
当i位置上的数字为0时
这时i位置要想为1，就必须向高位借1，因此此时低位部分是都可以取到0-9的。所以次数为：
(高位数字大小-1+1) * 10^(i-1)=高位数字大小*10^(i-1)
*/