/************************************************************
    File Name : 37_序列化二叉树.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-16 星期四 21:19:45
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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ret = "";
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int len = q.size();
            for (int i = 0 ; i < len; i++) {
                TreeNode* temp = q.front();
                q.pop();
                if (!temp) {
                    ret += "null ";
                    continue;
                }
                else ret += to_string(temp->val) + " ";
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        ret[ret.length() - 1] = ' ';
     //   cout << ret << endl;
        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream input(data);
        vector<TreeNode *> v;
        string val;
        while (input >> val) {
            if (val == "null") v.push_back(NULL);
            else v.push_back(new TreeNode(stoi(val)));
        } 
        int len = v.size();
        for (int i = 0, j = 1; j < len; i++) {
            if (v[i] == NULL) continue;
            if (j < len) v[i]->left = v[j++];
            if (j < len) v[i]->right = v[j++];
        }
        return v[0];
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));