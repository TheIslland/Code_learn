/************************************************************
    File Name : trie.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-23 星期四 14:04:34
************************************************************/
#include <ctime>
#include <iostream>

using namespace std;
#define BASE 26
#define BASE_Litter 'a'
class Node {
   public:
    Node() { 
        flag = 0;
        for (int i = 0; i < BASE; i++) {
            data[i] = NULL;
        }
    }

   public:
    int flag;
    Node *data[BASE];
};
class Trie {
   public:
    Trie() { head = new Node(); }
    void clear_node(Node *root) {
        if (!root) return;
        for (int i = 0; i < BASE; i++) {
            if (root->data[i]) clear_node(root->data[i]);
        }
        delete root;
        return;
    }
    ~Trie() { clear_node(head); }
    inline int code(char x) { return x - BASE_Litter; }
    void insert(string str) {
        Node *p = head;
        for (int i = 0; i < str[i]; i++) {
            if (p->data[code(str[i])] == NULL) p->data[code(str[i])] = new Node();
            p = p->data[code(str[i])];
        }
        p->flag = 1;
        return;
    }
    bool search(string str) {
        Node *p = head;
        for (int i = 0; str[i]; i++) {
            if (p->data[code(str[i])] == NULL) return false;
            p = p->data[code(str[i])];
        }
        return p->flag == 1;
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
};

int main() {
    Trie root = Trie();
#define MAX_OP 5
    string str;
    int n;
    for (int i = 0; i < MAX_OP; i++) {
        cin >> n >> str;
        if (n == 1) root.insert(str);
        else {
            if (root.search(str)) cout << "str in the Trie" << endl;
            else
                cout << "Node found the str" << endl;
        }
    }
    root.output();
    return 0;
}