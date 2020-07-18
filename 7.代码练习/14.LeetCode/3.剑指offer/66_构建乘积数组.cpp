/************************************************************
    File Name : 66_构建乘积数组.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-18 星期六 21:20:21
************************************************************/
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        vector<int> ans;
        int l = 1;
        for (int i = 0; i < a.size(); i++) {
            ans.push_back(l);
            l *= a[i];
        }
        l = 1;
        for (int i = a.size() - 1; i >= 0; i--) {
            ans[i] *= l;
            l *= a[i];
        }
        return ans;
    }
};