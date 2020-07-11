/*************************************************************************
	> File Name: 441路飞的征程.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Thu Nov  7 01:02:33 2019
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main() {
    int x, n;
    scanf("%d %d", &x, &n);
    int w[7]= {0 ,2, 2, 2, 2, 2, 0};
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += w[(x + i) % 7];    
    }
    printf("%d", sum);
    return 0;
}