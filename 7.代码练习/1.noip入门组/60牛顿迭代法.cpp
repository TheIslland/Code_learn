/************************************************************
    File Name : 60牛顿迭代法.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2019-12-28 星期六 16:25:05
************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <assert.h>

#define EPSLON 1e-6
#define sqrt(a) (0)

#define Plog(frm, arg...) { \
    printf("[ %s : %d -> output ] " frm "\n", __func__, __LINE__, ##arg); \
    fflush(stdout); \
}

double newton_sqrt(double n);

void haizei_test() {
    for (int i = 0; i < 1000; i++) {
        double n = rand() % 1000000;
        double x = newton_sqrt(n);
        assert(fabs(x * x - n) < EPSLON);
        Plog("Accept");
    }
    return ;
}

int main() {
    srand(time(0));
    haizei_test();
    return 0;
}

double newton_sqrt(double n) {
    //TODO
    double l = 0, r = n, mid = (l + r) / 2;
    while (mid * mid - n > EPSLON) {
        mid = mid - (mid * mid) / (2 * mid);
    }
    return mid;
}