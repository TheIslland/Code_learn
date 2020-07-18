/************************************************************
    File Name : 39_数组中出现次数超过一半的数字.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-17 星期五 09:27:13
************************************************************/
//排序取中法
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        return nums[nums.size() >> 1];
    }
};
//哈希法
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int len = nums.size();
        map<int, int> m;
        for (int i = 0; i < len; i++) {
            m[nums[i]]++;
            if (m[nums[i]] > len >> 1) return nums[i];
        }
        return -1;
    }
};
//o（n）一次遍历法
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ret = nums[0], cnt = 1, len = nums.size();
        for (int i = 1; i < len; i++) {
            if (!cnt) ret = nums[i], cnt = 1;
            else if (ret != nums[i]) cnt--;
            else cnt++;
        }
        return ret;
    }
};