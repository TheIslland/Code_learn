/************************************************************
    File Name : 61_扑克牌中的顺子.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-18 星期六 09:14:14
************************************************************/
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        int flag = 0, max_number = -1;
        int a[14] = {0};
        for (int i = 0; i < 5; i++) {
            a[nums[i]]++;
        }
        for (int i = 1; i < 13; i++) {
            if (a[i]) {
                for (int j = i; j < i + 5; j++) {
                    if (j > 12) return a[0] == (i + 5 - j);
                    if (a[j] == 1) continue ;
                    if (a[j] > 1 || !a[0]) return false;
                    a[0]--;
                }
                return true;
            }
        }
        return false;
    }
};