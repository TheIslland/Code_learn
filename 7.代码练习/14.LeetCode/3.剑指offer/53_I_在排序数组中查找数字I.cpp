/************************************************************
    File Name : 53_I_在排序数组中查找数字I.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-17 星期五 17:26:39
************************************************************/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) sum++;
        }
        return sum;
    }
};

//二分答案
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int sum = 0, l = 0, r = nums.size(), mid;
        while (l < r) {
            mid = (l + r) >> 1;
            if (nums[mid] >= target) r = mid;
            else l = mid + 1;
        }
        for (int i = r; i < nums.size(); i++) if (nums[i] == target) sum++;
        return sum;
    }
};