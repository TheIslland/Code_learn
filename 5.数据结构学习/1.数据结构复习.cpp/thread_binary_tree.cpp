#include <ctime>
#include <iostream>
using namespace std;
#define THREAD 1
#define NORMAL 0

class Node {
   public:
    Node() {
        ltag = rtag = NORMAL;
        lchild = rchild = NULL;
    }
    Node(int value) {
        this->val = value;
        ltag = rtag = NORMAL;
        lchild = rchild = NULL;
    }

   public:
    int val;
    int ltag, rtag;
    Node *lchild, *rchild;
};

class thread_tree {
   public:
    thread_tree() { head = new Node(); }
    Node *insert(Node *root, int val) {
        if (!root) return new Node(val);
        if (root->val == val) return root;
        if (root->val > val)
            root->lchild = insert(root->lchild, val);
        else
            root->rchild = insert(root->rchild, val);
        return root;
    }
    void push(int val) {
        Node *root = head->lchild;
        head->lchild = insert(root, val);
        return;
    }
    Node *build_thread_tree(Node *root) {
        if (!root) return NULL;
        static Node *pre = NULL;
        root->lchild = build_thread_tree(root->lchild);
        if (root->lchild == NULL) {
            root->lchild = pre;
            root->ltag = THREAD;
        }
        if (pre && pre->rchild == NULL) {
            pre->rchild = root;
            pre->rtag = THREAD;
        }
        pre = root;
        root->rchild = build_thread_tree(root->rchild);
        return root;
    }
    void build_thread() {
        Node *root = head->lchild;
        head->lchild = build_thread_tree(root);
        return;
    }
    Node *most_left(Node *root) {
        while (root && root->ltag == NORMAL && root->lchild)
            root = root->lchild;
        return root;
    }
    void in_order() {
        cout << "in_order output is: [ ";
        Node *first_node = most_left(head->lchild);
        while (first_node) {
            cout << first_node->val << " ";
            if (first_node->rtag == THREAD) {
                first_node = first_node->rchild;
            } else {
                first_node = most_left(first_node->rchild);
            }
        }
        cout << "]" << endl;
    }
    void output_node(Node *root) {
        if (!root) return;
        if (root->ltag == NORMAL) output_node(root->lchild);
        cout << root->val << " ";
        if (root->rtag == NORMAL) output_node(root->rchild);
        return;
    }
    void output() {
        cout << "the tree output is: [ ";
        output_node(head->lchild);
        cout << "]" << endl;
    }

   private:
    Node *head;  //虚拟头节点
};

int main() {
    thread_tree root = thread_tree();
    srand(time(0));
#define MAX_OP 20
    for (int i = 0; i < MAX_OP; i++) {
        root.push(rand() % 100);
    }
    root.build_thread();
    root.output();
    root.in_order();
    return 0;
}