class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        set<int> s;
        for (int i = 0; i < nums.size(); i++) {
            if (s.count(nums[i])) return nums[i];
            else s.insert(nums[i]);
        }
        return -1;
    }
};

//原地置换
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            while (nums[i] != i) {
                if (nums[i] == nums[nums[i]]) return nums[i];
                int temp = nums[i];
                nums[i] = nums[temp];
                nums[temp] = temp;
            }
        }
        return -1;
    }
};