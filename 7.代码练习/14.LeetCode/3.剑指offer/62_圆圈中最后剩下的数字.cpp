/************************************************************
    File Name : 62_圆圈中最后剩下的数字.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-19 星期天 11:57:58
************************************************************/
class Solution {
public:
    int lastRemaining(int n, int m) {
        int pos = 0;
        for (int i = 2; i <= n; i++) {
            pos = (pos + m) % i; //我们先把被杀掉的C补充回来，然后右移m个人，发现溢出了，再把溢出的补充在最前面
        }
        return pos;
    }
};