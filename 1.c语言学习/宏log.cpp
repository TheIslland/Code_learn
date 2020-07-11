/************************************************************
    File Name : 宏log.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2019-12-12 星期四 19:19:23
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>

using namespace std;

#define DEBUG
#ifdef DEBUG

//##在宏定义中表示连接，如果在宏定义中有有一个#或两个##则宏会停止展开，否则他会对该宏进行持续展开
//代码第30行不加##无法通过编译的原因，无法通过宏展开合法性检查

#define log(frm, arg...)                                             \
    {                                                                \
        printf("[%s : %s : %d] %d\n", __FILE__, __func__, __LINE__); \
        printf(frm, ##arg);                                             \
        printf("\n");\
}
#else
#define log(frm, arg)
#endif

#define contact(a, b) a##b
#define B(a) a * 2
#define A(a) a + 3

int main() {
    int a = 123;
   // A(B(a)); //1 => B(a) + 3 1=> a * 2 + 3
    int abcdef = 0;
    contact(abc, def) = 23;
    log("%d", a);
    log("hello world");
    log("%d", abcdef);
    return 0;
}