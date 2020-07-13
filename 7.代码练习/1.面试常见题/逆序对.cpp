/************************************************************
    File Name : 逆序对.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-12 星期天 15:12:12
************************************************************/
#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

int merage_sort(vector<int>& nums, int left, int right) {
    if (left >= right) return 0;
    int l1 = left, r1 = (right + left) / 2;
    int l2 = r1 + 1, r2 = right, sum = 0;
    sum += merage_sort(nums, l1, r1) + merage_sort(nums, l2, r2);
    vector<int> ret;
    while (l1 <= r1 && l2 <= r2) {
        while (l1 <= r1 && nums[l1] <= 3 * nums[l2]) l1++;
        sum += (r1 - l1 + 1);
        l2++;
    }
    l1 = left, l2 = r1 + 1;
    while (l1 <= r1 && l2 <= r2) {
        if (nums[l1] < nums[l2]) {
            ret.push_back(nums[l1++]);
        } else {
            ret.push_back(nums[l2++]);
        }
    }
    while (l1 <= r1) ret.push_back(nums[l1++]);
    while (l2 <= r2) ret.push_back(nums[l2++]);
    for (int i = 0; i < ret.size(); i++) {
        nums[left + i] = ret[i];
    }
    return sum;
}

int reverse_pairs(vector<int>& nums) {
    return merage_sort(nums, 0, nums.size() - 1);
}

int main() {
    int n;
    cin >> n;
    vector<int> num(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
    }
    cout << reverse_pairs(num) << endl;
    return 0;
}