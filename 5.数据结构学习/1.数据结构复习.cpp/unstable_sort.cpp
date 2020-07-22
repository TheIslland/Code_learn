/************************************************************
    File Name : unstable_sort.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-22 星期三 16:26:45
************************************************************/
#include <ctime>
#include <iostream>

using namespace std;

void select_sort(int *nums, int n) {
    for (int i = 0; i < n - 1; i++) {
        int ind = i;
        for (int j = i + 1; j < n; j++) {
            if (nums[ind] < nums[j]) ind = j;
        }
        swap(nums[i], nums[ind]);
    }
}

void shell_sort(int *nums, int n) {

}

void quick_sort(int *nums, int left, int right) {
    while (left < right) {
        int l = left, r = right, mid = left + rand() % (right - left + 1);
        while (l <= r) {
            while (nums[l] < nums[mid]) l++;
            while (nums[r] > nums[mid]) r--;
            if (l <= r) {
                swap(nums[l], nums[r]);
                l++, r--;
            }
        }
        quick_sort(nums, left, r);
        left = l;
    }
    return;
}

void downUpdata(int *nums, int n, int ind) {
    while ((ind << 1) <= n) {
        int temp = ind, l = ind << 1, r = ind << 1 | 1;
        if (nums[temp] < nums[l]) temp = l;
        if ((r <= n) && nums[temp] < nums[r]) temp = r;
        if (temp == ind) break;
        swap(nums[temp], nums[ind]);
        ind = temp;
    }
    return;
}

void head_sort(int *nums, int n) { 
    nums--;
    for (int i = n >> 1; i > 0; i--) {
        downUpdata(nums, n, i);
    }
    for (int i = n; i > 0; i--) {
        swap(nums[1], nums[i]);
        downUpdata(nums, i - 1, 1);
    }
    return;
}

int main() {
    srand(time(0));
    #define MAX_OP 20
    int arr[MAX_OP];
    for (int i = 0; i < MAX_OP; i++) {
        arr[i] = rand() % 100;
    }
    cout << "arr in sort before is = [ ";
    for (int i = 0; i < MAX_OP; i++) {
        cout << arr[i] << " ";
    }
    cout << "]" << endl;
    //select_sort(arr, MAX_OP);
    //quick_sort(arr, 0, MAX_OP - 1);
    head_sort(arr, MAX_OP);
    cout << "sort arr is = [ ";
    for (int i = 0; i < MAX_OP; i++) {
        cout << arr[i] << " ";
    }
    cout << "]" << endl;
    

    return 0;
}