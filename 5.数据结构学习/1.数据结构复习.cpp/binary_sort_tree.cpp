/************************************************************
    File Name : binary_sort_tree.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-20 星期一 09:18:07
************************************************************/
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

template <typename Type>
class Node {
   public:
    Node() {}
    Node(Type val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }

   public:
    Type val;
    Node<Type> *left, *right;
};

template <typename Type>
class binary_sort_tree {
   public:
    binary_sort_tree() {
        head = Node<Type>();
        head.left = NULL;
        head.right = NULL;
    }
    ~binary_sort_tree() {}
    Node<Type> *insert(Node<Type> *root, int val) {
        if (!root) return new Node<Type>(val);
        if (root->val == val) return root;
        if (root->val > val)
            root->left = insert(root->left, val);
        else
            root->right = insert(root->right, val);
        return root;
    }
    void push(Type val) {
        Node<Type> *root = head.left;
        head.left = insert(root, val);

        return;
    }
    bool find_node(Node<Type> *root, int val) {
        if (!root) return false;
        if (root->val == val) return true;
        if (root->val > val) return insert(root->left, val);
        return insert(root->right, val);
    }
    bool count(Type val) {
        Node<Type> *root = head.left;
        return find_node(root, val);
    }
    Node<Type> *pre_node(Node<Type> *root) {
        Node<Type> *current_node = root->left;
        while (current_node->right) current_node = current_node->right;
        return current_node;
    }
    Node<Type> *delete_node(Node<Type> *root, Type val) {
        if (!root) return NULL;
        if (root->val > val) {
            root->left = delete_node(root->left, val);
        } else if (root->val < val) {
            root->right = delete_node(root->right, val);
        } else {
            if (root->left == NULL && root->right == NULL) {
                delete root;
                return NULL;
            } else if (root->left == NULL || root->right == NULL) {
                Node<Type> *ret_node = (root->left ? root->left : root->right);
                delete root;
                return ret_node;
            } else {
                Node<Type> *temp = pre_node(root);
                root->val = temp->val;
                root->left = delete_node(root->left, temp->val);
            }
        }
        return root;
    }
    void erase(Type val) {
        Node<Type> *root = head.left;
        head.left = delete_node(root, val);
        return;
    }

    void mid_output(Node<Type> *root) {
        if (!root) return;
        mid_output(root->left);
        cout << root->val << " ";
        mid_output(root->right);
    }
    void output() {
        Node<Type> *root = head.left;
        cout << "binary_sort_tree = [ ";
        mid_output(root);
        cout << "]" << endl;
    }

   private:
    Node<Type> head;
};
int main() {
    srand(time(0));
    int op, val;
#define MAX_OP 20
#define MAX_N 15
    binary_sort_tree<int> head = binary_sort_tree<int>();
    for (int i = 0; i < 20; i++) {
        op = rand() % 4;  // 0:search, 1:erase,2.3.4.5:insert
        val = rand() % 20;
        switch (op) {
            case 0: {
                cout << "search " << val << " is " << (head.count(val) ? "true" : "false") << endl;
            } break;
            case 1: {
                printf("erase %d from BST\n", val);
                head.erase(val);
            } break;
            default: {
                printf("insert %d to BST\n", val);
                head.push(val);
            }
        }
        head.output();
        printf("\n\n");
    }
    // clear(root);
    return 0;
}