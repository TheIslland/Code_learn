/************************************************************
    File Name : 11_旋转数组的最小数字.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-14 星期二 15:00:23
************************************************************/
class Solution {
public:
    int minArray(vector<int>& numbers) {
        if (numbers.size() == 0) return 0;
        int l = 0, r = numbers.size() - 1, mid;
        while (l < r) {
            mid = (l + r) >> 1;
            if (numbers[mid] > numbers[r]) l = mid + 1;
            else if (numbers[mid] < numbers[l]) r = mid;
            else r--;
        }
        return numbers[r];
    }
};