/************************************************************
    File Name : 元素所在位置.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-11 星期六 10:11:09
************************************************************/
#include <stdio.h>
int binary_search(int target, int *num, int len) {
	int left = 0, right = len - 1, mid;
    while (left <= right) {
        mid = (left + right) >> 1;
        if (target == num[mid]) return mid;
        if (target > num[mid]) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}
int main() {
	int num[1000000];
	int n, m;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &num[i]);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		int value;
		scanf("%d", &value);
		printf("%d\n", binary_search(value, num, n));
	}
	return 0;
}