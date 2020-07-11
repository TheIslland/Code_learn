#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void merge(int *nums, int *nums1, int length1,
                      int *nums2, int length2) {
    int l = 0, l1 = 0, l2 = 0;
	while (l1 < length1 || l2 < length2) {
		if (l1 == length1) nums[l++] = nums2[l2++];
        else if (l2 == length2) nums[l++] = nums1[l1++];
        else nums[l++] = nums1[l1] < nums2[l2] ? nums1[l1++] : nums2[l2++];
    }
    return ;
}
int main() {
    int n, m;
    scanf("%d %d",&n, &m);
    int *num = (int*)malloc((n + m) * sizeof(int));
    int *num1 = (int*)malloc(n * sizeof(int));
    int *num2 = (int*)malloc(m * sizeof(int));
    for (int i = 0; i < n; ++i) {
        scanf("%d", num1 + i);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d", num2 + i);
    }
    for (int i = 0; i < 1000; ++i) {
        free(num);
        num = (int*)malloc((n + m) * sizeof(int));
        merge(num, num1, n, num2, m);
    }
    for (int i = 0; i < n + m; ++i) {
        printf("%d%c", num[i], i == n + m - 1? '\n' : ' ');
    }
    free(num);
    free(num1);
    free(num2);
    return 0;
}