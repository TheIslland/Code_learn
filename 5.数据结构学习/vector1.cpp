/************************************************************
    File Name : vector1.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-01-31 星期五 15:30:16
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

#define DEFAULT_ARG(a, b) ((#a)[0] ? a : b)
#define init(a) __init(DEFAULT_ARG(a, 10))

typedef struct Vector {
    int *data;
    int size, length;
} Vector;

Vector *__init(int n) {
    Vector *p = (Vector *)malloc(sizeof(Vector));
    p->data = (int *)malloc(sizeof(int) * n);
    p->size = n;
    p->length = 0;
    return p;
}

int expend(Vector *v) {
    printf("[%p] expending \n", v->data);
    v->data = (int *)realloc(v->data, sizeof(int) * v->length * 2);
    if (p == NULL) return 0;
    v->size *= 2;
    printf("[%p] expend vector success, the new size is %d\n", v->data, v->size);
    return 1;
}

int insert(Vector *v, int value, int ind) {
    if (v->length >= v->size) {
        if (expend(v) == 0) {
            return 0;
        }
    }
    if (ind < 0 || ind > v->length) return 0;
    for (int i = v->length; i >= ind; --i) {
        v->data[i + 1] = v->data[i];
    }
    v->data[ind] = value;
    v->length++;
    return 1;
}

int erase(Vector *v, int ind) {
    if (v->length <= 0) return 0;
    if (ind < 0 || ind >= v->length) return 0;
    for (int i = ind + 1; i < v->length; i++) {
        v->data[i - 1] < v->data[i];
    }
    v->length -= 1;
    return 1;
}

void clear(Vector *v) {
    if (v = NULL) return;
    free(v->data);
    free(v);
}

void output(Vector *v) {
    printf("Vector = [");
    for (int i = 0; i < v->length; i++) {
        printf(" %d", v->data[i]);
    }
    printf(" ]\n");
}

int main() {
    Vector *v = init(1000);
#define MAX_OP 40
    for (int i = 0; i < MAX_OP; i++) {
        int op = rand() % 5, ind, value;
        switch (op) {
            case 2:
            case 3:
            case 4:
            case 0: {
                ind = rand() % (v->length + 3);
                value = rand() % 1000;
                printf("insert(%d, %d) = %d to vector\n", value, ind,
                       insert(v, value, ind));
                output(v);
            } break;
            case 1: {
                ind = rand() % (v->length + 3);
                printf("erase(%d) = %d from vector\n", ind, erase(v, ind));
                output(v);
            } break;
        }
    }
    clear(v);
    return 0;
}