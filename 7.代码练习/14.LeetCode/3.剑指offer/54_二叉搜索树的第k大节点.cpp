/************************************************************
    File Name : 54_二叉搜索树的第k大节点.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-17 星期五 18:13:39
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
    int ret;
    int kthLargest(TreeNode* root, int &k) {
        if (root) {
            kthLargest(root->right, k);
            if (--k == 0) ret = root->val; 
            kthLargest(root->left, k);
        }
        return ret;
    }
};