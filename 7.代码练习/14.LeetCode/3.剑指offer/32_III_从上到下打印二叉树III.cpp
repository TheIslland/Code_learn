
/************************************************************
    File Name : 32_III_从上到下打印二叉树III.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-16 星期四 11:19:06
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
//反转vector法
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if (!root) return ret;
        queue<TreeNode *> q;
        q.push(root);
        int num = 0;
        while (!q.empty()) {
            vector<int> level;
            int len = q.size();
            for (int i = 0 ; i < len; i++) {
                TreeNode *temp = q.front();
                level.push_back(temp->val);
                q.pop();
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right); 
            }
            if (num++ & 1) reverse(level.begin(), level.end());
            ret.push_back(level);
        }
        return ret;
    }
};

//双端队列法
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if (!root) return ret;
        deque<TreeNode *> q;
        q.push_back(root);
        bool num = true;
        while (!q.empty()) {
            vector<int> level;
            int len = q.size();
            if (num) {
                for (int i = 0 ; i < len; i++) {
                    TreeNode *temp = q.front();
                    level.push_back(temp->val);
                    q.pop_front();
                    if (temp->left) q.push_back(temp->left);
                    if (temp->right) q.push_back(temp->right); 
                }
            } else {
                for (int i = 0 ; i < len; i++) {
                    TreeNode *temp = q.back();
                    level.push_back(temp->val);
                    q.pop_back();
                    if (temp->right) q.push_front(temp->right);
                    if (temp->left) q.push_front(temp->left); 
                }
            }
            num = !num;
            ret.push_back(level);
        }
        return ret;
    }
};