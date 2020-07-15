/************************************************************
    File Name : 28._对称的二叉树.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-15 星期三 15:42:13
************************************************************/
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>

using namespace std;

int main() {
    
    return 0;
}/**
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
    bool judg_Symmetric(TreeNode *p, TreeNode * q) {
        if (p == NULL && q == NULL) return true;
        if (p == NULL || q == NULL || p->val != q->val) return false;
        return judg_Symmetric(p->left, q->right) && judg_Symmetric(p->right, q->left);
    }
    bool isSymmetric(TreeNode* root) {
        //if (root == NULL) return true;
        return judg_Symmetric(root, root);
    }
};