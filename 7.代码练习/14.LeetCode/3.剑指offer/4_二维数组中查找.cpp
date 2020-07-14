//二分查找
class Solution {
public:
    bool binary_search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, mid;
        while (l <= r) {
            mid = (l + r) >> 1;
            if (nums[mid] == target) return true;
            if (nums[mid] > target) r = mid - 1;
            else l = mid + 1;
        }
        return false;
    }
    bool findNumberIn2DArray(vector<vector<int>>& nums, int target) {
        if (nums.size() == 0 || nums[0].size() == 0) return false;
        for (int i = 0; i < nums.size(); i++) {
            if (binary_search(nums[i], target)) return true;
        }
        return false;
    }
};
//线性查找
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& nums, int target) {
        if (nums.size() == 0 || nums[0].size() == 0) return false;
        int j = 0, i = nums.size() - 1; 
        while (i >= 0 && j < nums[0].size()) {
            if (nums[i][j] == target) return true;
            if (nums[i][j] > target) i--;
            else j++;
        }
        return false;
    }
};