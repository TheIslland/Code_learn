/************************************************************
    File Name : stable_sort.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-22 星期三 15:28:13
************************************************************/
#include <ctime>
#include <iostream>

using namespace std;

void insert_sort(int *nums, int n) {
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0; j--) {
            if (nums[j] < nums[j - 1]) swap(nums[j], nums[j - 1]);
        }
    }
}
void bubble_sort(int *nums, int n) {
    int judg = 1;
    for (int i = 0; i < n - 1 && judg; i++) {
        judg = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (nums[j] > nums[j + 1]) {
                swap(nums[j], nums[j + 1]);
                judg = 1;
            }
        }
    }
    return;
}
void merage_sort(int *nums, int *temp, int left, int right) {
    if (left >= right) return;
    int l1 = left, r1 = (left + right) >> 1;
    int l2 = r1 + 1, r2 = right;
    merage_sort(nums, temp, l1, r1);
    merage_sort(nums, temp, l2, r2);
    int ind = left;
    while (l1 <= r1 && l2 <= r2) {
        if (nums[l1] < nums[l2]) temp[ind++] = nums[l1++];
        else
            temp[ind++] = nums[l2++];
    }
    while (l1 <= r1) temp[ind++] = nums[l1++];
    while (l2 <= r2) temp[ind++] = nums[l2++];
    for (int i = left; i <= right; i++) {
        nums[i] = temp[i];
    }
    return;
}
int main() {
    srand(time(0));
#define MAX_OP 20
    int arr[MAX_OP] = {0};
    for (int i = 0; i < MAX_OP; i++) {
        arr[i] = rand() % 100;
    }
    cout << "arr in sort before is = [";
    for (int i = 0; i < MAX_OP; i++) {
        cout << arr[i] << " ";
    }
    cout << "]" << endl;
    /*
    insert_sort(arr, MAX_OP);
    bubble_sort(arr, MAX_OP);
    */
    int temp[MAX_OP] = {0};
    merage_sort(arr, temp, 0, MAX_OP - 1);
    cout << "sort = [";
    for (int i = 0; i < MAX_OP; i++) {
        cout << arr[i] << " " ;
    }
    cout << "]" << endl;
    
    return 0;
}