/************************************************************
    File Name : 快排6式.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-11 星期六 16:15:51
************************************************************/

//普通快排
void quick_sort(int *nums, int left, int right) {
    if (left >= right) return ;
    int l = left, r = right, u = nums[l];
    while (l < r) {
        while (l < r && nums[r] <= u) r--;
        if (l < r) nums[l++] = nums[r];
        while (l < r && nums[l] >= u) l++;
        if (l < r) nums[r--] = nums[l];
    }
    nums[l] = u;
    quick_sort(nums, left, l - 1);
    quick_sort(nums, l + 1, right);
    return ;
}

// 区间左闭右闭
// 单边递归法 节省一半的递归函数调用
//所有快排partition操作的左半部分交给递归，右半部分交给循环以节省一半的递归函数调用
//也可以说是右边界收缩递归，左边界收缩循环

void quick_sort(int *nums, int left, int right) {
    while (left < right) {
        int l = left, r = right, u = nums[l];
        while (l < r) {
            while (l < r && nums[r] <= u) r--;
            if (l < r) nums[l++] = nums[r];
            while (l < r && nums[l] >= u) l++;
            if (l < r) nums[r--] = nums[l];
        }
        nums[l] = u;
        quick_sort(nums, left, l - 1);
        left = l + 1;
    }
    return ;
}


// 区间左闭右闭
// 无监督partition
//减少while循环判断条件，从基准值的左右两边各找一个大于等于和小于等于基准值的数进行交换，
//且在每轮do'while的过程中，基准值被更新，并只在第一次交换中调整基准值，此后只进行基准值左右，大于基准值的数字与小于基准值的数字交换
//在第一次交换之后再基准值的左侧，满足条件的基准值左右两端的值互换直到y走到x的左边也就是离基准值最近的且比基准值大的值的位置那么也式递归的必要位置。
//在第一次交换时，基准值被划分到了右半部分
void quick_sort(int *nums, int left, int right) {
    while (left < right) {
        int l = left, r = right, u = nums[l];
        do {
            while (nums[l] > u) l++;
            while (nums[r] < u) r--;
            if (l <= r) {
                SWAP(nums[l], nums[r]);
                l++, r--;
            }
        } while(l <= r);
        quick_sort(nums, left, r);
        left = l;
    }
    return ;
}



// 区间左闭右闭
// 小数据范围改插入排序
//其中插入排序时，先找出最小值，与基准值交换，用以优化后续插入排序操作，并预防完全逆序
void insert_sort(int *nums, int left, int right) {
    int ind = left;
    for (int i = left + 1; i <= right; i++) {
        if (nums[i] > nums[ind]) ind = i;
    }
    SWAP(nums[ind], nums[left]);
    for (int i = left + 2; i <= right; i++) {
        int j = i;
        while (nums[j] > nums[j - 1]) {
            SWAP(nums[j], nums[j - 1]);
            j--;
        }
    }
    return ;
}

void quick_sort(int *nums, int left, int right) {
    while (right - left >= 16) {
        int l = left, r = right, u = nums[l];
        do {
            while (nums[l] > u) l++;
            while (nums[r] < u) r--;
            if (l <= r) {
                SWAP(nums[l], nums[r]);
                l++, r--;
            }
        } while (l <= r);
        quick_sort(nums, left, r);
        left = l;
    }
    if (left < right) insert_sort(nums, left, right);
    return ;
}


// 区间左闭右闭
// 基准值：随机法
void insert_sort(int *nums, int left, int right) {
    int ind = left;
    for (int i = left + 1; i <= right; i++) {
        if (nums[i] > nums[ind]) ind = i;
    }
    SWAP(nums[ind], nums[left]);
    for (int i = left + 2; i <= right; i++) {
        int j = i;
        while (nums[j] > nums[j - 1]) {
            SWAP(nums[j], nums[j - 1]);
            j--;
        }
    }
    return ;
}

void quick_sort(int *nums, int left, int right) {
    while (right - left >= 16) {
        int l = left, r = right, u = nums[l + rand() % (r - l + 1)];
        do {
            while (nums[l] > u) l++;
            while (nums[r] < u) r--;
            if (l <= r) {
                SWAP(nums[l], nums[r]);
                l++, r--;
            }
        } while (l <= r);
        quick_sort(nums, left, r);
        left = l;
    }
    if (left < right) insert_sort(nums, left, right);
    return ;
}