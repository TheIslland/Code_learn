/************************************************************
    File Name : 三数较小和.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-12 星期天 10:09:53
************************************************************/
void quick_sort(vector<int> &nums, int left, int right) {
    while (left < right) {
        int l = left, r = right, u = nums[left + rand() % (r - l + 1)];
        while (l <= r) {
            while (nums[l] < u) l++;
            while (nums[r] > u) r--;
            if (l <= r) {
                int temp = nums[l];
                nums[l] = nums[r];
                nums[r] = temp;
                l++, r--;
            }
        }
        quick_sort(nums, left, r);
        left = l;
    }
    return ;
}

int three_sum_smaller(vector<int> &nums, int length, int target) {
    if (length < 3) return 0;
    quick_sort(nums, 0, length - 1);
    int ans = 0;
    for (int i = 0; i < length - 2; i++) {
        int l = i + 1, r = length - 1;
        while (l < r) {
            if (nums[l] + nums[r] + nums[i] < target) {
                ans += r - l;
                l++;
            } else {
                r--;
            }
        }
    }
    return ans;
}