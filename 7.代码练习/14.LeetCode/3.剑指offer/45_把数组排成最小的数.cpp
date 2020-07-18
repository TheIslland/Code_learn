/************************************************************
    File Name : 45_把数组排成最小的数.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-18 星期六 20:17:06
************************************************************/
class Solution {
public:
    static bool cmp(string &a, string &b) {
        return a + b < b + a;
    }
    string minNumber(vector<int>& nums) {
        vector<string> str;
        string ans = "";
        for (int i = 0; i < nums.size(); i++) {
            str.push_back(to_string(nums[i]));
        }
        sort(str.begin(), str.end(), cmp);
        for (int i = 0; i < str.size(); i++) {
            ans += str[i];
        }
        return ans;
    }
};