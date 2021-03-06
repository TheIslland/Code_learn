/*************************************************************************
	> File Name: 二进制中1的个数.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年03月26日 星期二 20时03分03秒
 ************************************************************************/
class Solution {
public:
    int NumberOf1(int n) {
        unsigned int x = n;
        //以1位单位提取奇偶性,提取奇偶性，提取后把偶数位为右移与奇数位相加，相当于我们以1位为单位统计每2位中1的个数
        x = ((x & 0xAAAAAAAA) >> 1) + (x & 0x55555555);
        //以2位为单位提取奇偶性，在上一步的基础上，以2为基础单位，统计每4位中1的个数
        x = ((x & 0xcccccccc) >> 2) + (x & 0x33333333);
        //以4位为单位提取奇偶性，在上一步的基础上，以4为基础单位，统计每8位中1的个数
        x = ((x & 0xF0F0F0F0) >> 4) + (x & 0x0F0F0F0F);
        //以8位为单位提取奇偶性，在上一步的基础上，以8为基础单位，统计每16位中1的个数
        x = ((x & 0xFF00FF00) >> 8) + (x & 0x00FF00FF);
        //以16位为单位提取奇偶性，在上一步的基础上，以16为基础单位，统计每32位中1的个数
        x = ((x & 0xFFFF0000) >> 16) + (x & 0x0000FFFF);
        return x;
    }
};
/*
0xAAAAAAAA=10101010101010101010101010101010 (以1为单位提取偶数位)

0x55555555 = 1010101010101010101010101010101（以1为单位提取奇数位）

 

0xCCCCCCCC = 11001100110011001100110011001100 （以2为单位提取偶数位）

0x33333333 = 110011001100110011001100110011（以2为单位提取奇数位）

 

0xF0F0F0F0 = 11110000111100001111000011110000 （以4为单位提取偶数为）

0x0F0F0F0F = 1111000011110000111100001111（以4为单位提取奇数位）



0xFFFF0000 =11111111111111110000000000000000 （以16为单位提取偶数位）

0x0000FFFF = 1111111111111111（以16为单位提取奇数位）
*/


/*以211为例，将211转化为8位二进制数
n = 11010011

计算n = ((n & 0xAAAAAAAA) >> 1) + (n & 0x55555555);

得到 n = 10010010，划分为以2位为单位的格式来看10 01 00 10 总计5个1

计算n = ((n & 0xCCCCCCCC) >> 2) + (n & 0x33333333);

得到 n = 00110010，换分为以4位为单位的格式来看0011 0010前4为3个1后4位2个1，总计5个1

计算n = ((n & 0xF0F0F0F0) >> 4) + (n & 0x0F0F0F0F);

得到 n = 00000101，划分为以8为单位的格式来看总计5个1，那么5就是答案了。
*/
