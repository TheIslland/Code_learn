/************************************************************
    File Name : 两数之和_双指针.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-12 星期天 08:52:20
************************************************************/
vector<int> two_sum(vector<int> &nums, int length, int target) {
    int l = 0, r = length - 1;
    while (l < r) {
        if (nums[l] + nums[r] == target) return vector<int> {l ,r};
        if (nums[l] + nums[r] > target) r--;
        else l++;
    }
    return vector<int> {};
}