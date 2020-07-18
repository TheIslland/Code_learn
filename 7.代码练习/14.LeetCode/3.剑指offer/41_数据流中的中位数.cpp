/************************************************************
    File Name : 41_数据流中的中位数.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-17 星期五 15:03:19
************************************************************/
//方法一排序（超时）o(nlogn)
class MedianFinder {
public:
    /** initialize your data structure here. */
    vector<int> arr;
    MedianFinder() {

    }
    
    void addNum(int num) {
        arr.push_back(num);
    }
    
    double findMedian() {
        sort(arr.begin(), arr.end());
        int len = arr.size();
        if (len & 1) return arr[len / 2 - 1] * 1.0;
        return (arr[len / 2 - 1] + arr[len / 2]) * 1.0 / 2;
    }
};

//方法二，二分插入o(logn)
class MedianFinder {
public:
    /** initialize your data structure here. */
    vector<int> arr;
    MedianFinder() {

    }
    int binary_search(int x) {
        int l = 0, r = arr.size() - 1, mid;
        while (l < r) {
            mid = (l + r) >> 1;
            if (arr[mid] >= x) r = mid;
            else l = mid + 1;
        }
        return r;
    }

    void addNum(int num) {
        //cout << num << endl;
        arr.push_back(0);
        int x = binary_search(num);
        for (int i = arr.size() - 1; i > x; i--) arr[i] = arr[i - 1];
        arr[x] = num;
    }
    
    double findMedian() {
        int len = arr.size();
        if (len & 1) return arr[len / 2] * 1.0;
        return (arr[len / 2 - 1] + arr[len / 2]) * 1.0 / 2;
    }
};

//方法3 双堆维护
class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> left; //较小的一半存大顶堆
    priority_queue<int, vector<int>, greater<int>> right; //较大的一半存大顶堆
    MedianFinder() {

    }
    
    void addNum(int num) {
        left.push(num);
        right.push(left.top());
        left.pop();
        if (left.size() < right.size()) {
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        return (left.size() > right.size() ? left.top() * 1.0: (left.top() + right.top()) * 0.5);
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */