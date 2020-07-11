/************************************************************
    File Name : 58完美宏定义.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2019-12-27 星期五 20:17:41
************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#define MAX(a, b)                             \
    ({                                        \
        __typeof(a) __a = (a);                \
        __typeof(b) __b = (b);                \
        (__a) > (__b) ? (__a) : (__b); \
    })

#define Plog(frm, arg...)        \
    {                            \
        printf("[ %s : %d ] " frm "\n", __func__, __LINE__, ##arg);\
    }

void haizei_test() {
    int a = 6;
    Plog("%d", MAX(2, 3));
    Plog("%d", 5 + MAX(2, 3));
    Plog("%d", MAX(2, MAX(3, 4)));
    Plog("%d", MAX(2, 3 > 4 ? 3 : 4));
    Plog("%d", MAX(a++, 6));
    Plog("a value = %d", a);
}

int main() {
    haizei_test();
    return 0;
}