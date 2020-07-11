#include <iostream>
#include <vector>
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using namespace std;

int quick_select(vector<int> &nums, int left, int right, int k) {
	int l = left, r = right, mid = nums[left];
    while (l < r) {
        while (l < r && nums[l] <= nums[r]) {
			r--;
        }
        swap(nums[l], nums[r]);
    	while (l < r && nums[l] <= nums[r]) {
			l++;
        }
        swap(nums[l], nums[r]);
        /*
        while (l < r && nums[r] > mid) r--;
        if (l < r) nums[l++] = nums[r];
        while (l < r && nums[l] < mid) l++;
        if (l < r) nums[r--] = nums[l];
        */
    }
    if ((l - left) + 1 == k) return mid;
    nums[l] = mid;
    if ((l - left + 1) > k) {
        return quick_select(nums, left, l - 1, k);
    } else {
		return quick_select(nums, l + 1, right, k + left - l - 1);
    }
    return 0;
} 

int main() {
    int n;
    cin >> n;
    vector<int> num(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
    }
    for (int i = 1; i <= std::min(100, n); ++i) {
        cout << quick_select(num, 0, n - 1, i) << endl;
    }
    return 0;
}