/*************************************************************************
	> File Name: 162派.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Mon Nov  4 14:03:22 2019
 ************************************************************************/
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>
#include <iomanip>
using namespace std;
#define MAX_OP 60000000
//蒙特卡洛法画一个边长为2的正方形做一个内切圆，向正方形内投石子，求罗在园内的概率，大量实验使m/n逼近于pi/4，最后对m/n*4得到pi
int main()
{
    srand(time(0));
    int n = 0, m = 0;
    for (int i = 0; i < MAX_OP; i++) {
        double x = rand() * 1.0 / RAND_MAX * (rand() % 2 ? 1 : -1);
        double y = rand() * 1.0 / RAND_MAX * (rand() % 2 ? 1 : -1);
        if (x * x + y * y <= 1.0) m++;
        n += 1;
    }
    printf("%.8lf\n", m * 1.0 / n * 4.0);
	return 0;
}