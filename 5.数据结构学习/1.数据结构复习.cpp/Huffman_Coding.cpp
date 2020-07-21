/************************************************************
    File Name : Huffman_Coding.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-21 星期二 08:31:43
************************************************************/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Node {
   public:
    Node() {
        lchild = NULL;
        rchild = NULL;
    }
    Node(int val, int freq) {
        lchild = NULL;
        rchild = NULL;
        this->val = val;
        this->freq = freq;
    }

   public:
    Node *lchild, *rchild;
    int val, freq;
};

Node *build_tree(Node * node[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 2; j++) {
            // j < n - i - 2,是为了预留出最小值与次小值的位置
            if (node[j]->freq <= node[n - i - 1]->freq) {
                swap(node[j], node[n - i - 1]);
            }
            if (node[j]->freq <= node[n - i - 2]->freq) {
                swap(node[j], node[n - i - 2]);
            }
        }
        Node *temp = new Node(-1, node[n - i - 1]->freq + node[n - i - 2]->freq);
        temp->lchild = node[n - i - 1];
        temp->rchild = node[n - i - 2];
        node[n - i - 2] = temp;
    }
    return node[0];
}
void extract_node(Node *root, vector<string> &ans, string ret) {
    if (!root) return;
    if (root->val != -1) {
        string temp = "";
        temp += (char)root->val;
        temp += " " + ret;
        ans.push_back(temp);
        return;
    }
    ret += "0";
    extract_node(root->lchild, ans, ret);
    ret[ret.length() - 1] = '1';
    extract_node(root->rchild, ans, ret);
    return;
}

void output(Node *root) {
    if (!root) return;
    cout << root->val << " " << endl;
    output(root->lchild);
    output(root->rchild);
    return;
}
int main() {
    string str;
    int a[256] = {0}, n = 0;
    cin >> str;
    for (int i = 0; i < str.length(); i++) {
        if (a[str[i]]++ == 0) n++;
    }
    Node* node[256];
    int num = 0;
    for (int i = 0; i < 256; i++) {
        if (a[i]) {
            node[num++] = new Node(i, a[i]);
        }
    }
    Node *root = build_tree(node, n);
    vector<string> ans;
    string ret = "";
    extract_node(root, ans, ret);
    for (int i = 0; i < ans.size(); i++) {
        cout << "code = " << ans[i] << endl;
    }
    return 0;
}