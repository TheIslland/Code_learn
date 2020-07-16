/************************************************************
    File Name : 33_二叉搜索树的后序遍历序列.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-16 星期四 13:55:08
************************************************************/
//递归法，利用后续遍历左右根的特性，与二叉搜索树，左子树全小于根右子树全大于根的特性，递归划分左右子树
//每层递归找到第一个大于当前节点的值，其为右子树的根节点，划分左右
//由于该特性，左半部分一定满足，故核验右半部分是否满足二叉搜索树性质，不满足返回false
//满足继续递归，直到单个节点返回true
class Solution {
public:
    bool recur(vector<int>& nums, int left, int right) {
        if (left >= right) return true;
        int mid;
        for (mid = left; mid < right; mid++) {
            if (nums[mid] > nums[right]) break;
        }
        for (int i = mid; i < right; i++) {
            if (nums[i] < nums[right]) return false;
        }
        return recur(nums, left, mid - 1) && recur(nums, mid, right - 1);
    }
    bool verifyPostorder(vector<int>& postorder) {
        return recur(postorder, 0, postorder.size() - 1);
    }
};

//由于改序列为二叉搜索树的后序遍历（左->右->根），所以其倒序为（根->右->左）,且由二叉搜索树特性可知，此序列右子树应单调递增，
//左子树单调递减，故我们维护一个单调栈，存储根节点与右子树，当当前元素小于栈顶时，代表即将进入左子树，故，循环出战找到该左子树的父节点
//在该左子树中的任何一个值不应大于其父节点的值。
class Solution {
public:
    bool verifyPostorder(vector<int>& nums) {
        int len = nums.size();
        if (len < 2) return true;
        stack<int> s;
        //s.push(nums[len - 1]);
        int max_num = INT_MAX;
        for (int i = len - 1; i >= 0; i--) {
            if (max_num < nums[i]) return false;
            while (!s.empty() && nums[i] < s.top()) {
                max_num = s.top();
                s.pop();
            }
            s.push(nums[i]);
        }
        return true;
    }
};