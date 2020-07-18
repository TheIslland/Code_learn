/************************************************************
    File Name : 40_最小的k个数.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-17 星期五 14:49:06
************************************************************/
//快速选择
class Solution {
public:
    int partitation(vector<int> &nums, int left, int right) {
        int l = left, r = right, mid = left + rand() % (r - l + 1);
        swap(nums[l], nums[mid]);
        while (l < r) {
            while (l < r && nums[l] <= nums[r]) {
			    r--;
            }
            swap(nums[l], nums[r]);
    	    while (l < r && nums[l] <= nums[r]) {
			    l++;
            }
            swap(nums[l], nums[r]);
        }
        return l;
    }
    void quick_slect(vector<int> &arr, int l, int r, int k) {
        if (l >= r) return ;
        int mid = partitation(arr, l, r);
        int judg = mid - l + 1;
        if (judg == k) return ;
        else if (judg > k) quick_slect(arr, l, mid - 1, k);
        else quick_slect(arr, mid + 1, r, k - judg);
    }
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> ret;
        if (!k) return ret;
        quick_slect(arr, 0, arr.size() - 1, k);
        for (int i = 0; i < k; i++) ret.push_back(arr[i]);
        return ret;
    }
};

//快排

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if (!k) return vector<int> {};
        sort(arr.begin(), arr.end());
        return vector<int> (arr.begin(), arr.begin() + k);
    }
};

//堆

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if (!k) return vector<int> {};
        if (arr.size() == k) return vector<int> (arr); 
        priority_queue<int> q;
        for (int i = 0; i < k; i++) {
            q.push(arr[i]);
        }
        for (int i = k; i < arr.size(); i++) {
            if (q.top() > arr[i]) {
                q.pop();
                q.push(arr[i]);
            }
        }
        vector<int> ret;
        for (int i = 0; i < k; i++) {
            ret.push_back(q.top());
            q.pop();
        }
        return ret;
    }
};