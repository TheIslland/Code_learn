/************************************************************
    File Name : 归并排序.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-11 星期六 15:26:20
************************************************************/
#include <iostream>
#include <vector>
using std::vector;
using std::cin;
using std::cout;
void merge_sort(vector<int> &nums, int left, int right) {
    if (left == right) return ;
    vector<int> ret;
    int l1 = left, r1 = left + (right - left + 1) / 2 - 1; 
    int l2 = r1 + 1, r2 = right;
    merge_sort(nums, l1, r1);
    merge_sort(nums, l2, r2);
    while (l1 <= r1 && l2 <= r2) {
        if (nums[l1] < nums[l2]) ret.push_back(nums[l1++]);
        else ret.push_back(nums[l2++]);
    }
    while (l1 <= r1) ret.push_back(nums[l1++]);
    while (l2 <= r2) ret.push_back(nums[l2++]);
    for (int i = 0; i < ret.size(); i++) {
        nums[left + i] = ret[i];
    }
    return ;
}
int main() {
    int n;
    cin >> n;
    vector<int> num(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
    }
    merge_sort(num, 0, n - 1);
    for (int i = 0; i < n; ++i) {
        cout << num[i] << (i == n - 1?'\n' : ' ');
    }
    return 0;
}