/************************************************************
    File Name : 26_树的子结构.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-15 星期三 15:14:53
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
    bool judg_SubStructure(TreeNode * A, TreeNode *B) {
        if (B == NULL) return true;
        if (A == NULL || A->val != B->val) return false;
        return judg_SubStructure(A->left, B->left) && judg_SubStructure(A->right, B->right);
    }
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (A == NULL || B == NULL) return false;
        return judg_SubStructure(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
};