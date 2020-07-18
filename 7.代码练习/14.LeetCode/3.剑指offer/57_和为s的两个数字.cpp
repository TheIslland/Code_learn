/************************************************************
    File Name : 57_和为s的两个数字.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-17 星期五 18:49:09
************************************************************/
//双指针
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int temp = nums[l] + nums[r];
            if (temp == target) return vector<int> {nums[l], nums[r]};
            if (temp > target) r--;
            else l++;
        }
        return vector<int> {};
    }
};
//哈希
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        set<int> s;
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            if (s.count(target - nums[i])) return vector<int> {nums[i], target - nums[i]};
            else s.insert(nums[i]);
        }
        return vector<int> {};
    }
};