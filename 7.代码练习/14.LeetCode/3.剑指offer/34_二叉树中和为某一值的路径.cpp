/************************************************************
    File Name : 34_二叉树中和为某一值的路径.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-16 星期四 15:55:50
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
    vector<vector<int>> ret;
    vector<int> path;    
    void dfs(TreeNode *root, int sum) {
        if (!root) return ;
        sum -= root->val;
        path.push_back(root->val);
        if (!sum && root->left == NULL && root->right == NULL) ret.push_back(path); 
        dfs(root->left, sum);
        dfs(root->right, sum);
        path.pop_back();
        return ;
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        dfs(root, sum);
        return ret;
    }
};