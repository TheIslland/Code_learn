/************************************************************
    File Name : 21_ 调整数组顺序使奇数位于偶数前面.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-15 星期三 14:09:36
************************************************************/
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            while (l < r && nums[l] & 1) l++;
            while (l < r && nums[r] % 2 == 0) r--;
            if (l < r) {
                int temp = nums[l];
                nums[l] = nums[r];
                nums[r] = temp;
                l++, r--;
            }   
        }
        return nums;
    }
};