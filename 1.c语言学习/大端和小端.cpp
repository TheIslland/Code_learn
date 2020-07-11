/************************************************************
    File Name : 大端和小端.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2019-12-14 星期六 19:46:20
************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

union IP{
    unsigned int num;
    struct {
        unsigned char a1;
        unsigned char a2;
        unsigned char a3;
        unsigned char a4;
    }ip;
};

int main() {
    union IP p;
    char str[25];
    unsigned int arr[4];
    while(~scanf("%s", str)) {
        sscanf(str, "%d.%d.%d.%d",arr, arr + 1, arr + 2, arr + 3);   
        p.ip.a1 = arr[3];
        p.ip.a2 = arr[2];
        p.ip.a3 = arr[1];
        p.ip.a4 = arr[0];//大端机使用这种输入形式
        //小端机器使用p.ip.a1 = arr[0][1][2][3] 这种形式
        printf("%u\n", p.num);
        
    unsigned int a;
    unsigned char b;
    a = 192;
    b = a;
    a = b;
    printf("%u\n", a);
    }
    return 0;
}