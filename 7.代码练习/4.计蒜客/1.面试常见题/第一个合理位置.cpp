/************************************************************
    File Name : 第一个合理位置.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-11 星期六 10:54:01
************************************************************/
#include <algorithm>
#include <iostream>
using namespace std;
int find_first_location(int *num, int len, int target) {
	int l = 0, r = len - 1, mid;
    while (l < r) {
        mid = (l + r) >> 1;
        if (target > num[mid]) l = mid + 1;
        else r = mid;
    }
    return l;
}
int main() {
	int num[100000];
	int n, m;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> num[i];
	}
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int value;
		cin >> value;
		cout << find_first_location(num, n, value) << endl;
	}
	return 0;
}