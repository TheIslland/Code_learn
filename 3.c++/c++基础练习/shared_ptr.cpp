/************************************************************
    File Name : shared_ptr.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-08-09 星期天 14:28:16
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>

using namespace std;

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;


namespace my {
template<typename T>
    class shared_ptr {
    public :
        shared_ptr() : p(nullptr), cnt(nullptr) {}
        shared_ptr(T *p) : p(p), cnt(nullptr) {
            cnt = new size_t(1);
        }
        shared_ptr(const shared_ptr<T> &obj) : p(p), cnt(cnt) {
            (*cnt) += 1;
        }
        shared_ptr(shared_ptr<T> &obj) : p(p), cnt(cnt) { 
            obj.p = nullptr; 
            obj.cnt = nullptr;
        }
        size_t &use_count() { return (*cnt); }
        T *get() { return p; }
        T &operator*() { return *p; }
        T *operator->() { return p; }
        template<typename U>
        shared_ptr<T> &operator=(shared_ptr<U> &obj) {
            sub_one();
            p = reinterpret_cast<T *>(obj.get());
            cnt = &(obj.use_count());
            (*cnt) += 1;
            return *this;
        }
        ~shared_ptr() {
            sub_one();
        }
    private:
        void sub_one() {
            if (p == nullptr) return ;
            (*cnt) -= 1;
            if ((*cnt) == 0) {
                delete cnt;
                delete p;
                cnt = nullptr;
            }
            p = nullptr;
        }
        T *p;
        size_t *cnt;
    };

template<typename T>
    class weak_ptr {
    public:
        weak_ptr() : p(nullptr), cnt(nullptr) {}
        weak_ptr(shared_ptr<T> &obj) : p(obj.get()), cnt(&(obj.use_count())) {}
        weak_ptr(const weak_ptr<T> &obj) : p(obj.p), cnt(obj.cnt) {}
        T &operator*() { return *p; }
        size_t &use_count() { return *cnt; }
        T *get() { return p; }
        template<typename U>
        weak_ptr<T> &operator=(weak_ptr<U> &obj) {
            cnt = &(obj.use_count());
            p = reinterpret_cast<T *>(obj.get());
            return *this;
        }
        template<typename U>
        weak_ptr<T> &operator=(shared_ptr<U> &obj) {
            cnt = &(obj.use_count());
            p = reinterpret_cast<T *>(obj.get());
            return *this;
        }
        ~weak_ptr() {}
    private:
        T *p;
        size_t *cnt;
    };
}

class A {
public :
    A() {}
    virtual ~A() {
        cout << "Class A" << endl;
    }
};

class B : public A {
public :
    B() {}
    virtual ~B() {
        cout << "Class B" << endl;
    }
    my::weak_ptr<B> next;
    //my::shared_ptr<B> next;
};

// shared_ptr要和weak_ptr结合去用， 防止由智能指针循环引用引起内存泄漏
void func() {
    my::shared_ptr<B> p1(new B);
    my::shared_ptr<B> p2(new B);
    my::weak_ptr<A> p3;
    p3 = p1;
    cout << p1.use_count() << " " << p3.use_count() << endl;
    p1->next = p2;
    p2->next = p2;
    return ;
}

int main() {
    func();
    return 0;
}
