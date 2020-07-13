/************************************************************
    File Name : 二分法解方程.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-11 星期六 10:47:28
************************************************************/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define ESP 1e-8
double func(double x) {
    return pow(x, 4) + 5 * pow(x, 3) + 6 * pow(x,2) + 7 * x + 4;
}

double solve_equation(double y) {
    double l = 0, r = 100, mid;
    if (y < func(l) || y > func(r)) return -1;
    while (r - l > ESP) {
        mid = (l + r) / 2.0;
        if (y > func(mid)) l = mid;
        else r = mid;
    }
    return l;
}
int main() {
	double y;
	scanf("%lf", &y);
	printf("%.10f\n", solve_equation(y));
}