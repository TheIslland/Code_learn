/************************************************************
    File Name : Linked_list.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-02-01 星期六 08:47:50
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

typedef struct LinkNode {
    int data;
    struct LinkNode *next;
} LinkNode;

typedef struct LinkList {
    LinkNode head;
    int length;
} LinkList;

LinkList *init() {
    LinkList *p = (LinkList *)malloc(sizeof(LinkList));
    p->head.next = NULL;
    p->length = 0;
    return p;
}

LinkNode *getNewNode(int value) {
    LinkNode *p = (LinkNode *)malloc(sizeof(LinkNode));
    p->data = value;
    p->next = NULL;
    return p;
}

void Linklist_insert(LinkList *l, int value, int ind) {
    LinkNode *p = &(l->head);
    while (ind--) {
        p = p->next;
        if (p == NULL) return ;
    }
    LinkNode *new_node = getNewNode(value);
    new_node->next = p->next;
    p->next = new_node;
    l->length++;
    return ;
}

void erase(LinkList *l, int ind) {
    LinkNode*p = &(l->head);
    while (ind--) {
        p = p->next;
        if (p == NULL) return ;
    }
    if (p->next == NULL) return ;
    LinkNode *q = p->next;
    p->next = q->next;
    free(q);
    l->length--;
    return ;
}

void output(LinkList *l) {
    LinkNode *p = l->head.next;
    printf("linklist = [ length = %d, ", l->length);
    while (p != NULL) {
        printf("%d->", p->data);
        p = p->next;
    }
    printf("NULL ]\n");
    return;
}

void clear(LinkList *l) {
    if (l->head.next == NULL) return;
    LinkNode *p = l->head.next, *q;
    while (p != NULL) {
        q = p;
        p = p->next;
        free(q);
    }
    free(l);
    return;
}

int main() {
    srand(time(0));
    LinkList *l = init();
#define MAX_OP 20
    for (int i = 0; i < MAX_OP; i++) {
        int op = rand() % 4, value, ind;
        switch (op) {
            case 0:
            case 1:
            case 2: {
                ind = rand() % (l->length + 1);
                value = rand() % 100;
                printf("insert(%d, %d) to linkedlist\n", value, ind);
                Linklist_insert(l, value, ind);
                output(l);
            } break;
            case 3: {
                if (!l->length) break;
                ind = rand() % (l->length);
                printf("erase(%d) from linkedlist\n", ind);
                erase(l, ind);
                output(l);
            } break;
        }
    }
    clear(l);
    return 0;
}