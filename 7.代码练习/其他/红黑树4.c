/*************************************************************************
	> File Name: 红黑树4.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年02月21日 星期四 14时20分35秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define RED 0
#define BLACK 1
#define DOUBLE_BLACK 2

typedef int color_t;

typedef struct RBTNode {
    int key;
    color_t color;
    struct RBTNode *lchild, *rchild;
} RBTNode;

RBTNode *NIL;

__attribute__((constructor))
void init_NIL() {
    NIL = (RBTNode *)malloc(sizeof(RBTNode));
    NIL->key = -1;
    NIL->color = BLACK;
    NIL->lchild = NIL->rchild = NIL;
    return ;
}

RBTNode *init(int key) {
    RBTNode *p = (RBTNode *)malloc(sizeof(RBTNode));
    p->key = key;
    p->color = RED;
    p->lchild = p->rchild = NIL;
    return p;
}

int has_red_child(RBTNode *root) {
    return root->lchild->color == RED || root->rchild->color == RED;
}

RBTNode *left_rotate(RBTNode *node) {
    RBTNode *temp = node->rchild;
    node->rchild = temp->lchild;
    temp->lchild = node;
    return temp;
}

RBTNode *right_rotate(RBTNode *node) {
    RBTNode *temp = node->lchild;
    node->lchild = temp->rchild;
    temp->rchild = node;
    return temp;
}

RBTNode *insert_maintain(RBTNode *root) {
    if (!has_red_child(root)) return root;
    if (root->lchild->color == RED && root->rchild->color == RED) {
        if (!has_red_child(root->lchild) && !has_red_child(root->rchild)) return root;
    } else if (root->lchild->color == RED && has_red_child(root->lchild)) {
        if (root->lchild->rchild->color == RED) {
            root->lchild = left_rotate(root->lchild);
        }
        root = right_rotate(root);
    } else if (root->rchild->color == RED && has_red_child(root->rchild)) {
        if (root->rchild->lchild->color == RED) {
            root->rchild = right_rotate(root->rchild);
        }
        root = left_rotate(root);
    } else {
        return root;
    }
    root->color = RED;
    root->lchild->color = root->rchild->color = BLACK;
    return root;
}

RBTNode *__insert(RBTNode *root, int key) {
    if (root == NIL) return init(key);
    if (root->key == key) return root;
    else if (root->key > key) {
        root->lchild = __insert(root->lchild, key);
    } else {
        root->rchild = __insert(root->rchild, key);
    }
    return insert_maintain(root);
}

RBTNode *insert(RBTNode *root, int key) {
    root = __insert(root, key);
    root->color = BLACK;
    return root;
}

RBTNode *predecessor(RBTNode *root) {
    RBTNode *temp = root->lchild;
    while (temp->rchild != NIL) temp = temp->rchild;
    return temp;
}

RBTNode *erase_maintain(RBTNode *root) {
    if (root->lchild->color != DOUBLE_BLACK && root->rchild->color != DOUBLE_BLACK) return root;
    #define UNBALANCE(a,b) (root->a->color == DOUBLE_BLACK && root->b->color == BLACK && !has_red_child(root->b))
    if (UNBALANCE(lchild, rchild) || UNBALANCE(rchild, lchild)) {
        root->color += 1;
        root->lchild->color -= 1;
        root->rchild->color -= 1;
        return root;
    }
    #undef UNBALANCE
    if (root->lchild->color == DOUBLE_BLACK) {
        if (root->rchild->color == RED) {
            root = left_rotate(root);
            root->color = BLACK;
            root->lchild->color = RED;
            root->lchild = erase_maintain(root->lchild);
            return root;
        }
        root->lchild->color = BLACK;
        if (root->rchild->rchild->color != RED) {
            root->rchild = right_rotate(root->rchild);
            root->rchild->color = BLACK;
            root->rchild->rchild->color = RED;
        }
        root = left_rotate(root);
        root->color = root->lchild->color;
    } else {
        if (root->lchild->color == RED) {
            root = right_rotate(root);
            root->color = BLACK;
            root->rchild->color = RED;
            root->rchild = erase_maintain(root->rchild);
            return root;
        }
        root->rchild->color = BLACK;
        if (root->lchild->lchild->color != RED) {
            root->lchild = left_rotate(root->lchild);
            root->lchild->color = BLACK;
            root->lchild->lchild->color = RED;
        }
        root = right_rotate(root);
        root->color = root->rchild->color;
    }
    root->lchild->color = root->rchild->color = BLACK;
    return root;
}

RBTNode *__erase(RBTNode *root, int key) {
    if (root == NIL) return NIL;
    if (root->key > key) {
        root->lchild = __erase(root->lchild, key);
    } else if (root->key < key) {
        root->rchild = __erase(root->rchild, key);
    } else {
        if (root->lchild == NIL || root->rchild == NIL) {
            RBTNode *temp = (root->lchild == NIL ? root->rchild : root->lchild);
            temp->color += root->color;
            free(root);
            return temp;
        } else {
            RBTNode *temp = predecessor(root);
            root->key = temp->key;
            root->lchild = __erase(root->lchild, temp->key);
        }
    }
    return erase_maintain(root);
}

RBTNode *erase(RBTNode *root, int key) {
    root = __erase(root, key);
    root->color = BLACK;
    return root;
}

void clear(RBTNode *root) {
    if (root == NIL) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}

void output(RBTNode *root, FILE *name) {
    if (root == NIL) return ;
    fprintf(name, "(%d, %d, %d) = %d\n", root->key, root->lchild->key, root->rchild->key, root->color);
    output(root->lchild, name);
    output(root->rchild, name);
    return ;
}

int main() {
    int op, val;
    RBTNode *root = NIL;
    FILE *file;
    file = fopen("output1.txt", "w");
    while (scanf("%d %d", &op, &val) != EOF) {
        if (op) {
            root = insert(root, val);
        } else {
            root = erase(root, val);
        }
        output(root, file);
        fprintf(file, "\n");
    }     
    fclose(file);
    return 0;
}
