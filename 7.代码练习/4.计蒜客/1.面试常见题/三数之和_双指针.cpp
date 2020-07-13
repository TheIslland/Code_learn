/************************************************************
    File Name : 三数之和_双指针.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-12 星期天 09:07:04
************************************************************/
vector<int> three_sum(vector<int> &nums, int length, int target) {
    if (length < 3) return vector<int> {};
    for (int i = 1; i < length - 1; i++) {
        int l = 0, r = length - 1, mid = target - nums[i];
        while (l < r) {
            if (nums[l] + nums[r] == mid) return vector<int> {l, i, r};
            if (nums[l] + nums[r] > mid) r--;
            else l++;
            if (l >= i || r <= i) break;
        }
    }
    return vector<int> {};
}