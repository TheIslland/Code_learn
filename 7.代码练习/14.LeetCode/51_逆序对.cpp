/************************************************************
    File Name : 51_逆序对.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-15 星期三 10:58:14
************************************************************/
class Solution {
public:
    int rev_Pairs(vector<int>& nums, int left, int right) {
        if (left >= right) return 0;
        int l1 = left, r1 = (left + right) / 2;
        int l2 = r1 + 1, r2 = right, ans = 0;
        ans += rev_Pairs(nums, l1, r1) + rev_Pairs(nums, l2, r2);
        if (nums[r1] <= nums[l2]) return ans;  
        vector<int> temp;
        while (l1 <= r1 && l2 <= r2) {
            if (nums[l1] <= nums[l2]) temp.push_back(nums[l1++]);
            else {
                ans += r1 - l1 + 1;
                temp.push_back(nums[l2++]);
            }
        }
        while (l1 <= r1) temp.push_back(nums[l1++]);
        while (l2 <= r2) temp.push_back(nums[l2++]);
        for (int i = 0; i < temp.size(); i++) {
            nums[left + i] = temp[i];
        }
        return ans;
    }
    int reversePairs(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        return rev_Pairs(nums, 0, nums.size() - 1);
    }
};