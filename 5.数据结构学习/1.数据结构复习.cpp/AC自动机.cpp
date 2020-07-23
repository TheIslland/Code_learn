/************************************************************
    File Name : AC自动机.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-23 星期四 15:55:24
************************************************************/
#include <iostream>
#include <queue>
using namespace std;
#define BASE 26
#define BASE_litter 'a'

class Node {
   public:
    Node() {
        flag = 0;
        fail = NULL;
        for (int i = 0; i < BASE; i++) {
            data[i] = NULL;
        }
    }
   public:
    Node *data[BASE];
    Node *fail;
    int flag;
};

class AC_Trie {
   public:
    AC_Trie() {
        cnt = 0;
        head = new Node();
    }
    inline int code(char x) { return x - BASE_litter; }
    void insert(string str) {
        Node *p = head;
        for (int i = 0; str[i]; i++) {
            int ind = code(str[i]);
            if (p->data[ind] == NULL) cnt++, p->data[ind] = new Node();
            p = p->data[ind];
        }
        p->flag = 1;
        return;
    }
    void build_ac() {
        queue<Node *> q;
        Node *root = head;
        q.push(root);
        while (!q.empty()) {
            Node *current_node = q.front();
            q.pop();
            for (int i = 0; i < BASE; i++) {
                if (current_node->data[i] == NULL) continue;
                Node *p = current_node->fail;
                while (p && p->data[i] == NULL) p = p->fail;
                if (p == NULL)
                    current_node->data[i]->fail = head;
                else
                    current_node->data[i]->fail = p->data[i];
                q.push(current_node->data[i]);
            }
        }
        return;
    }
    int match(string str) {
        int ret = 0;
        Node *p = head, *temp = head;
        for (int i = 0; str[i]; i++) {
            int ind = code(str[i]);
            while (p && p->data[ind] == NULL) p = p->fail;
            if (p == NULL) p = head;
            else
                p = p->data[ind];
            Node *q = p;
            while (q) ret += q->flag, q = q->fail;
        }
        return ret;
    }
    void output_tree(Node *root, string str) {
        if (!root) return;
        if (root->flag) {
            cout << str << endl;
        }
        for (int i = 0; i < BASE; i++) {
            if (root->data[i] != NULL) {
                string temp = str + (char)(i + 'a');
                output_tree(root->data[i], temp);
            }
        }
        return;
    }
    void output() {
        output_tree(head, "");
        return;
    }
   public:
    Node *head;
    int cnt;
};
int main() {
    AC_Trie root = AC_Trie();
    int op;
    cin >> op;
    for (int i = 0; i < op; i++) {
        string str;
        cin >> str;
        root.insert(str);
    }
    root.build_ac();
    //root.output();
    string str;
    cin >> str;
    cout << root.match(str) << endl;
    return 0;
}