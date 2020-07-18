/************************************************************
    File Name : 42_连续子数组的最大和.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-17 星期五 16:45:39
************************************************************/
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>

using namespace std;

int main() {
    
    return 0;
}class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            nums[i] += max(nums[i - 1], 0);
            res = max(nums[i], res);
        }
        return res;
    }
};