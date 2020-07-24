/************************************************************
    File Name : AVL_tree.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-24 星期五 09:54:00
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

#define LH(root) (root->lchild->h)
#define RH(root) (root->rchild->h)
#define MAX(a, b)                         \
    ({                                    \
        __typeof(a) __a = (a), __b = (b); \
        __a > __b ? __a : __b;            \
    })
class Node {
   public:
    Node() {
        key = 0, h = 0;
        lchild = NULL;
        rchild = NULL;
    }
    Node(int val) {
        key = val;
        h = 1;
        lchild = NULL;
        rchild = NULL;
    }
    Node(int val, Node *node) {
        key = val;
        h = 1;
        lchild = node;
        rchild = node;
    }

   public:
    int key, h;
    Node *lchild, *rchild;
};

class AVL_tree {
   public:
    AVL_tree() {
        head = new Node();
        NIL = new Node();
        NIL->lchild = NIL->rchild = NIL;
        head->lchild = NIL;
    }
    void clear_node(Node *root) {
        if (root == NIL) return;
        if (root->lchild) clear_node(root->lchild);
        if (root->rchild) clear_node(root->rchild);
        delete root;
        return;
    }
    ~AVL_tree() {
        Node *root = head->lchild;
        clear_node(root);
    }
    void updata_height(Node *root) { root->h = (max(LH(root), RH(root)) + 1); }
    Node *left_rotate(Node *root) {
        Node *temp = root->rchild;
        root->rchild = temp->lchild;
        temp->lchild = root;
        updata_height(root);
        updata_height(temp);
        return temp;
    }
    Node *right_rotate(Node *root) {
        Node *temp = root->lchild;
        root->lchild = temp->rchild;
        temp->rchild = root;
        updata_height(root);
        updata_height(temp);
        return temp;
    }
    Node *maintain(Node *root) {
        updata_height(root);
        if (abs(LH(root) - RH(root)) <= 1) return root;
        if (LH(root) > RH(root)) {
            if (RH(root->lchild) > LH(root->rchild)) {
                root->lchild = left_rotate(root->lchild);
            }
            root = right_rotate(root);
        } else {
            if (LH(root->rchild) > RH(root->rchild)) {
                root->rchild = right_rotate(root->rchild);
            }
            root = left_rotate(root);
        }
        return root;
    }
    Node *insert_node(Node *root, int val) {
        if (root == NIL) return new Node(val, NIL);
        if (root->key == val) return root;
        if (root->key > val) {
            root->lchild = insert_node(root->lchild, val);
        } else {
            root->rchild = insert_node(root->rchild, val);
        }
        return maintain(root);
    }
    void insert(int val) {
        Node *root = head->lchild;
        head->lchild = insert_node(root, val);
        return;
    }
    void output_node(Node *root) {
        if (root == NIL) return;
        output_node(root->lchild);
        cout << root->key << " ";
        output_node(root->rchild);
        return;
    }
    void output() {
        cout << "The Tree is [";
        Node *root = head->lchild;
        output_node(root);
        cout << "]" << endl;
        return;
    }

   public:
    Node *head;
    Node *NIL;
};
int main() {
    srand(time(0));
    int n;
#define MAX_OP 20
    AVL_tree root = AVL_tree();
    for (int i = 0; i < MAX_OP; i++) {
        int val = rand() % 100;
        cout << "insert val is " << val << endl;
        root.insert(val);
    }
    root.output();
    return 0;
}