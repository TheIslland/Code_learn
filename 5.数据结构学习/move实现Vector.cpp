/*************************************************************************
	> File Name: move实现Vector.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年03月19日 星期二 18时35分43秒
 ************************************************************************/
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
class Element {
private:
    int number;
public:
	Element() :number(0) {
	    cout << "ctor" << endl;
	}
  	Element(int num):number(num) {
  		cout << "ctor" << endl;
  	}
  	Element(const Element& e):number(e.number) {
  		cout << "copy ctor" << endl;
  	}
  	Element(Element&& e):number(e.number) {
  		cout << "right value ctor" << endl;
  	}
  	~Element() {
  		cout << "dtor" << endl;
  	}
  	void operator=(const Element& item) {
  		number = item.number;
  	}
  	bool operator==(const Element& item) {
  		return (number == item.number);
  	}
  	void operator()() {
  		cout << number;
  	}
  	int GetNumber() {
  		return number;
  	}
};
template<typename T>
class Vector {
private:
  	T* items;
  	int count;
public:
  	Vector() :count{ 0 }, items{nullptr} {

  	}
  	Vector(const Vector& vector) :count{vector.count} {
  		items = static_cast<T*>(malloc(sizeof(T) * count));
  	//下一行会导致某些变量改变是是另一些元素值也改变的bug，其操作为二层浅拷贝因为调用了malloc，一层浅拷贝为this指针直接指向。
		memcpy(items, vector.items, sizeof(T) * count);
  	}
  	Vector(Vector&& vector) :count{ vector.count }, items{ vector.items } {
        vector.items = nullptr;
        vector.count = 0;
  	}
  	~Vector() {
        for (int i = 0; i < this->count; i++) {
			this->items[i].~Element();
        }
        free(this->items);
        this->items = nullptr;
        this->count = 0;
  	}
    T& operator[](int index){
    	if (index<0||index>=count) {
    		cout<<"invalid index"<<endl;
    		return items[0];
    	}
    	return items[index];
    }
    int returnCount(){
    	return count;
    }
  	void Clear() {
        for (int i = 0; i < this->count; i++) {
			this->items[i].~Element();
        }
        free(this->items);
        this->count = 0;
        this->items = nullptr;
  	}

  	void Add(const T& item) {
  		//当malloc失败时buffer为空
        T *buffer = (T *)malloc(sizeof(T) * (this->count + 1));
        for (int i = 0; i < this->count; i++) {
            new(buffer + i)Element(std::move(this->items[i]));
        }
        new(buffer + this->count)Element(item);
        int total = this->count + 1;
        this->Clear();
        this->count = total;
        this->items = buffer;
        return ;
  	}
  	bool Insert(const T& item,int index) {
        if (index < 0 || index > this->count ) return false;
        T *buffer = (T*)malloc(sizeof(T) * (this->count + 1));
        for (int i = this->count; i > index; i--) {
			new(buffer + i)Element(std::move(this->items[i - 1]));
        }
        new(buffer + index)Element(item);
        for (int i = index - 1; i >= 0; i--) {
            new(buffer + i)Element(std::move(this->items[i]));
        } 
        int total = this->count + 1;
		this->Clear();
        this->count = total;
        this->items = buffer;
        return true;
  	}
  	bool Remove(int index) {
        if (index < 0 || index >= this->count) return false;
        T *buffer = (T*)malloc(sizeof(T) * (this->count - 1));
        for (int i = 0; i < this->count - 1; i++) {
			new(buffer + i)Element(std::move(this->items[i + (i >= index)]));
        }
        int total = this->count - 1;
        this->Clear();
        this->count = total;
        this->items = buffer;
        return true;
  	} 
  	int Contains(const T& item) {
    	for (int i = 0; i < this->count; i++) {
			if (this->items[i] == item) return i;
        }
        return -1;
  	}
};
template<typename T>
void PrintVector(Vector<T>& v){
	  int count=v.returnCount();
	  for (int i = 0; i < count; i++)
	  {
		  v[i]();
		  cout << " ";
	  }
	  cout << endl;
}
int main() {
  	Vector<Element>v;
  	for (int i = 0; i < 4; i++) {
  		Element e(i);
  		v.Add(e);
  	}
  	PrintVector(v);
  	Element e2(4);
  	if (!v.Insert(e2, 10))
  	{
  		v.Insert(e2, 2);
  	}
  	PrintVector(v);
  	if (!v.Remove(10))
  	{
  		v.Remove(2);
  	}
  	PrintVector(v);
  	Element e3(1), e4(10);
  	cout << v.Contains(e3) << endl;
  	cout << v.Contains(e4) << endl;
  	Vector<Element>v2(v);
  	Vector<Element>v3(move(v2));
  	PrintVector(v3);
  	v2.Add(e3);
  	PrintVector(v2);
  	return 0;
}

