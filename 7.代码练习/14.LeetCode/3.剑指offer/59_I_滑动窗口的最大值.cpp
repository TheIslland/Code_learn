/************************************************************
    File Name : 59_I_滑动窗口的最大值.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-17 星期五 20:50:45
************************************************************/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        if (!nums.size()) return ret;
        deque<int> q;
        for (int i = 0; i < k; i++) {
            if (q.empty()) q.push_back(nums[i]);
            else {
                while(!q.empty() && q.back() < nums[i]) q.pop_back();
                q.push_back(nums[i]);  
            }
        }
        for (int i = k; i < nums.size(); i++) {
            ret.push_back(q.front());
            if (q.front() == nums[i - k]) q.pop_front();
            while(!q.empty() && q.back() < nums[i]) q.pop_back();
            q.push_back(nums[i]);
        }
        ret.push_back(q.front());
        return ret;
    }
};