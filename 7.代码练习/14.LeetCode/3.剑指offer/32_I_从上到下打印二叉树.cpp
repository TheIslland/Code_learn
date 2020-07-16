/************************************************************
    File Name : 32_I_从上到下打印二叉树.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-16 星期四 10:52:09
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
    vector<int> levelOrder(TreeNode* root) {
        vector<int> ret;
        if(!root) return ret;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode * temp = q.front();
            q.pop();
            ret.push_back(temp->val);
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
        return ret;
    }
};