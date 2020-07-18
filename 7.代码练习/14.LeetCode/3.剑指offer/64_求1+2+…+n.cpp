/************************************************************
    File Name : 64_求1+2+…+n.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-18 星期六 10:35:25
************************************************************/
//等差求和
class Solution {
public:
    int sumNums(int n) {
        return (1 + n) * n / 2;
    }
};

//递归逻辑符号短路

class Solution {
public:
    int sumNums(int n) {
        n && (n = n + sumNums(n - 1));
        return n;
    }
};