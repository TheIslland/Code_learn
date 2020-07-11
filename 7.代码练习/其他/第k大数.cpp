/************************************************************
    File Name : 第k大数.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2019-12-14 星期六 14:22:43
************************************************************/
#include <stdio.h>
#include <stdlib.h>

int binary_search(int * num1, int * num2, int len1, int len2, int k) {
	if (len1 == 0) return num2[k - 1];
    if (len2 == 0) return num1[k - 1];
    if (k == 1) return num1[0] < num2[0] ? num1[0] : num2[0];
    int a = len1 > k / 2 ? k / 2 : len1;
    int b = k - a;
    if (num1[a - 1] < num2[b - 1]) {
		num1 += a;
        len1 -= a;
        k -= a;
    } else {
        num2 += b;
        len2 -= b;
        k -= b;
    }
    return binary_search(num1, num2, len1, len2, k);
}
int find_kth_number(int *num1, int *num2, int n, int k) {
    return binary_search(num1, num2, n, n, k);	
}
int main() {
	int n;
	scanf("%d", &n);
	int *num1 = malloc(n * sizeof(int));
	int *num2 = malloc(n * sizeof(int));
	for (int i = 0; i < n; ++i) {
		scanf("%d ", &num1[i]);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d ", &num2[i]);
	}
	int m, tp;
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d", &tp);
		printf("%d\n", find_kth_number(num1, num2, n, tp));
	}
	return 0;
}