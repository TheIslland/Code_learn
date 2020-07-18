/************************************************************
    File Name : 68_I_二叉搜索树的最近公共祖先.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-18 星期六 14:19:38
************************************************************/
//迭代
class Solution {
public:

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val > q->val) swap(p, q);
        while (root) {
            if (root->val < p->val) root = root->right;
            else if (root->val > q->val) root = root->left;
            else return root;
        }
        return NULL;   
    }
};
//递归

class Solution {
public:
    TreeNode *find_parent(TreeNode* root, TreeNode* p, TreeNode *q) {
        if (root->val > q->val) return find_parent(root->left, p, q);
        if (root->val < p->val) return find_parent(root->right, p, q);
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val > q->val) swap(p, q);
        return find_parent(root, p, q);
    }
};