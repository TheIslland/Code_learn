/************************************************************
    File Name : 55_II_平衡二叉树.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-17 星期五 18:33:22
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
    int dfs(TreeNode* root) {
       if (!root) return 0;
       int l = dfs(root->left);
       int r = dfs(root->right);
       if (l == -1 || r == -1 || abs(l - r) > 1) return -1;
       return max(l, r) + 1; 
    }
    bool isBalanced(TreeNode* root) {
        return dfs(root) != -1;
    }
};