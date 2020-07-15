/************************************************************
    File Name : 27_ 二叉树的镜像.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-15 星期三 15:19:36
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
    TreeNode* mirrorTree(TreeNode* root) {
        if (root == NULL) return NULL;
        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;
        mirrorTree(root->left);
        mirrorTree(root->right);
        return root;
    }
};