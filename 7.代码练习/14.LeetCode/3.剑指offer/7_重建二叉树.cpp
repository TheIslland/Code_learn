/************************************************************
    File Name : 7_重建二叉树.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-14 星期二 10:42:07
************************************************************/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    map<int, int> m;
    TreeNode* next_Tree(vector<int> &pre, vector<int> &ino, int l1, int l2, int n) {
        if (n < 1) return NULL;
        TreeNode * root = new TreeNode(pre[l1]);
        int mid = m[pre[l1]] - l2;
        if (l1 + 1 < pre.size()) root->left = next_Tree(pre, ino, l1 + 1, l2, mid);
        if (l2 + 1 < ino.size()) root->right = next_Tree(pre, ino, l1 + mid + 1 ,l2 + mid + 1, n - mid - 1);
        return root;
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& ino) {
        if (pre.size() == 0 || ino.size() == 0) return NULL;
        for (int i = 0; i < ino.size(); i++) m[ino[i]] = i;
        return next_Tree(pre, ino, 0, 0, pre.size());
    }
};