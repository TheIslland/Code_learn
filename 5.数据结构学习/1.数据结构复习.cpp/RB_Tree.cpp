/************************************************************
    File Name : RB_tree1.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-25 星期六 10:56:45
************************************************************/
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>

using namespace std;

#define RED 0
#define BLACK 1
#define DOUBLE_BLACK 2

typedef struct Node {
    struct Node *lchild, *rchild;
    int color, key;
} Node;

Node _NIL, *const NIL = &_NIL;

__attribute__((constructor)) void init_NIL() {
    NIL->key = 0;
    NIL->color = BLACK;
    NIL->lchild = NIL->rchild = NIL;
    return;
}

Node *get_new_node(int val) {
    Node *ret = (Node *)malloc(sizeof(Node));
    ret->key = val;
    ret->color = RED;
    ret->lchild = ret->rchild = NIL;
    return ret;
}

bool has_Red_node(Node *root) {
    return root->lchild->color == RED || root->rchild->color == RED;
}

Node *left_rotate(Node *root) {
    Node *temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    return temp;
}
Node *right_rotate(Node *root) {
    Node *temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    return temp;
}
Node *insert_maintain(Node *root) {
    if (root == NIL) return root;
    if (root->lchild->color == RED && root->rchild->color == RED) {
        if (!has_Red_node(root->lchild) && !has_Red_node(root->rchild))
            return root;
        goto red_up;
    }
    if (root->lchild->color == RED && has_Red_node(root->lchild)) {
        if (root->lchild->rchild->color == RED) {
            root->lchild = left_rotate(root->lchild);
        }
        root = right_rotate(root);
    } else if (root->rchild->color == RED && has_Red_node(root->rchild)) {
        if (root->rchild->lchild->color == RED) {
            root->rchild = right_rotate(root->rchild);
        }
        root = left_rotate(root);
    } else {
        return root;
    }
red_up:
    root->color = RED;
    root->lchild->color = root->rchild->color = BLACK;
    return root;
}

Node *__insert(Node *root, int val) {
    if (root == NIL) return get_new_node(val);
    if (root->key == val) return root;
    if (root->key > val) {
        root->lchild = __insert(root->lchild, val);
    } else {
        root->rchild = __insert(root->rchild, val);
    }
    return insert_maintain(root);
}
Node *insert(Node *root, int val) {
    root = __insert(root, val);
    root->color = BLACK;
    return root;
}

Node *predecessor(Node *root) {
    Node *temp = root->lchild;
    while (temp->rchild != NIL) temp = temp->rchild;
    return temp;
}

Node *erase_maintain(Node *root) {
    if (root->lchild->color != DOUBLE_BLACK &&
        root->rchild->color != DOUBLE_BLACK) {
        return root;
    }
    if (root->rchild->color == DOUBLE_BLACK) {
        if (root->lchild->color == RED) {
            root->color = RED;
            root->lchild->color = BLACK;
            root = right_rotate(root);
            root->rchild = erase_maintain(root->rchild);
            return root;
        }
        if (!has_Red_node(root->lchild)) {
            root->color += 1;
            root->lchild->color -= 1;
            root->rchild->color -= 1;
            return root;
        }
        //不使用root->lchild->rchild->color == RED的理由是
        //该判断会将黑红红，红色下沉的状况视为LR型，但本质上其为LL型
        if (root->lchild->lchild->color != RED) {
            root->lchild->color = RED;
            root->lchild->rchild->color = BLACK;
            root->lchild = left_rotate(root->lchild);
        }
        root->lchild->color = root->color;
        root->rchild->color -= 1;
        root = right_rotate(root);
        root->lchild->color = root->rchild->color = BLACK;
    } else {
        if (root->rchild->color == RED) {
            root->color = RED;
            root->rchild->color = BLACK;
            root = left_rotate(root);
            root->lchild = erase_maintain(root->lchild);
            return root;
        }
        if (!has_Red_node(root->rchild)) {
            root->color += 1;
            root->rchild->color -= 1;
            root->lchild->color -= 1;
            return root;
        }
        if (root->rchild->rchild->color != RED) {
            root->rchild->color = RED;
            root->rchild->lchild->color = BLACK;
            root->rchild = right_rotate(root->rchild);
        }
        root->rchild->color = root->color;
        root->rchild->color -= 1;
        root = left_rotate(root);
        root->rchild->color = root->lchild->color = BLACK;
    }
    return root;
}

Node *__erase(Node *root, int val) {
    if (root == NIL) return root;
    if (root->key > val) {
        root->lchild = __erase(root->lchild, val);
    } else if (root->key < val) {
        root->rchild = __erase(root->rchild, val);
    } else {
        if (root->lchild == NIL || root->rchild == NIL) {
            Node *temp = root->lchild == NIL ? root->rchild : root->lchild;
            temp->color += root->color;
            free(root);
            return temp;
        } else {
            Node *temp = predecessor(root);
            root->key = temp->key;
            root->lchild = __erase(root->lchild, temp->key);
        }
    }
    return erase_maintain(root);
}

Node *erase(Node *root, int val) {
    root = __erase(root, val);
    root->color = BLACK;
    return root;
}

void __output(Node *root) {
    if (root == NIL) return;
    printf("(%d | %d %d %d)\n", root->color, root->key, root->lchild->key,
           root->rchild->key);
    __output(root->lchild);
    __output(root->rchild);
    return;
}

void output(Node *root) {
    printf("\n==== red black tree ====\n");
    __output(root);
    printf("NIL color : %d\n", NIL->color);
    return;
}
int main() {
    int op, val;
    Node *root = NIL;
    while (~scanf("%d%d", &op, &val)) {
        switch (op) {
            case 1: {
                printf("insert %d to red black tree!\n", val);
                root = insert(root, val);
            } break;
            case 2: {
                printf("erase %d from red black tree!\n", val);
                // root = erase(root, val);
            } break;
            default:
                break;
        }
        output(root);
    }
    return 0;
}