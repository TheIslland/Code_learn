/*************************************************************************
	> File Name: 哈夫曼编码.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年10月28日 星期日 21时44分09秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>

typedef struct Node {
    int key, freq;
    struct Node *lchild, *rchild;
} Node;

Node *getNewNode (int key, int freq) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->freq = freq;
    p->lchild = p->rchild = NULL;
    return p;
}

void clear(Node *root) {
    if(root == NULL) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}

int swap_node(Node **p, Node **q) {
    Node *temp = *p;
    *p = *q;
    *q = temp;
    return 1;
}

//排序是一种优秀的函数模板
Node *build_haffman(Node **arr, int n) {
   // Node INIT_NODE = {0, INT32_MAX, NULL, NULL};
    for(int i = 0; i < n - 1 ; i++) {
        //因为需要寻找次小点所以n - i - 2
        for(int j = 0; j < n - i - 2; j++) {
            //将当前ｊ范围内所有值和末尾和次末尾值比较找出所有数中最小和次小的值放到末尾和次末尾
            if(arr[j]->freq <= arr[n - i - 1]->freq) {
                swap_node (arr + j, arr + n - i - 1);
            }
            if(arr[j]->freq <= arr[n - i - 2 ]->freq) {
                swap_node (arr + j, arr + n - i - 2);
            }
        }
        //获取新节点值为最小点和次小点频率之和，或者说合成最小点和次小点
        Node *temp = getNewNode(0, arr[n -i - 1]->freq + arr[n - i - 2] ->freq);
        //新节点的左右子树，为合成他的前最小点和前次小点
        temp->lchild = arr[n - i - 1];
        temp->rchild = arr[n - i - 2];
        //更新合成节点
        arr[n - i - 2] = temp;
    }
    return arr[0];
}

void extract_code(Node *root , char (*code)[20], int k, char * buff) {
    buff[k] = 0;
    //递归遍历寻找叶子节点返回按树顺序标记的节点
    if(root->key) {
        strcpy(code[root->key], buff);
        return ;
    }
    //左边集标记为０右边集标为１
    buff[k] = '0';
    extract_code(root->lchild, code, k + 1, buff);
    buff[k] = '1';
    extract_code(root->rchild, code, k + 1, buff);
    return ;
}

int main() {
    int n; 
    scanf("%d", &n);
    Node **arr = (Node **)malloc(sizeof(Node *) * n);
    Node *root;
    for(int i = 0; i < n; i++) {
        char key[10];
        int freq;
        scanf("%s%d", key, &freq);
        arr[i] = getNewNode(key[0], freq);
    }
    root = build_haffman(arr, n);
    char code[256][20] = {0}, buff[20];
    extract_code(root, code, 0, buff);
    for(int i = 0; i < 256; i++) {
        if(code[i][0] == 0) continue;
        printf("%c : %s\n", i, code[i]);
    }
    return 0;
}

