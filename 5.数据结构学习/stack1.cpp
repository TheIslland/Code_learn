/************************************************************
    File Name : stack1.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-02-03 星期一 09:35:01
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
typedef struct Stack {
    int *data;
    int top, size;
} STack;

Stack *init(int n) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = (int *)malloc(sizeof(int) * n);
    s->top = -1;
    s->size = n;
    return s;
}

int empty(Stack *s) { return s->top == -1; }

int top(Stack *s) {
    if (empty(s)) return 0;
    return s->data[s->top];
}

int push(Stack *s, int value) {
    if (s->top + 1 == s->size) return 0;
    s->top += 1;
    s->data[s->top] = value;
    return 1;
}

void pop(Stack *s) {
    if (empty(s)) return;
    s->top--;
    return;
}

void output(Stack *s) {
    printf("Stack = [");
    for (int i = s->top; i >= 0; i--) {
        printf(" %d", s->data[i]);
        i == 0 || printf(",");
    }
    printf(" ]\n");
}

void clear(Stack *s) {
    if (s == NULL) return;
    free(s->data);
    free(s);
    return;
}

int main() {
#define MAX_OP 20
    Stack *s = init(MAX_OP);
    srand(time(0));
    for (int i = 0; i < MAX_OP; i++) {
        int op = rand() % 4, value = rand() % 100;
        switch (op) {
            case 0:
            case 1:
            case 2: {
                push(s, value);
                printf("Push %d to stack\n", value);
                output(s);
            } break;
            case 3: {
                printf("POP %d from stack\n", top(s));
                pop(s);
                output(s);
            } break;
        }
    }
    return 0;
}