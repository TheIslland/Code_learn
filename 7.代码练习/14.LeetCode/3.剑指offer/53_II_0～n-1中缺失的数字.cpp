/************************************************************
    File Name : 53_II_0～n-1中缺失的数字.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-17 星期五 17:43:56
************************************************************/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int l = 0, r = nums.size(), mid;
        while (l < r) {
            mid = (l + r) >> 1;
            if (nums[mid] > mid) r = mid;
            else l = mid + 1;
        } 
        return r;
    }
};