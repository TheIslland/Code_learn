/************************************************************
    File Name : 102二叉树层次遍历.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2019-11-23 星期六 11:04:00
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
    vector<vector<int>> levels;
    void Sub_Node(TreeNode *root, int level) {
        if (!root) return;
        if (levels.size() == level) levels.push_back(vector<int>());
        levels[level].push_back(root->val);
        if (root->left != NULL) Sub_Node(root->left, level + 1);
        if (root->right != NULL) Sub_Node(root->right, level + 1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return levels;
        Sub_Node(root, 0);
        return levels;
    }
};
int main() {
    
    return 0;
}