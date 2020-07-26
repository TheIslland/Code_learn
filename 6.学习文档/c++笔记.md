# c++

## 一、static

* 全局区（静态存储区）
* static属于类名，多个对象共享

* 默认是extern类型，其他文件也可访问，static修饰后，由external转化为internal，只能文件内部访问

* 局部static变量，作用域不变，函数执行完后，生命周期结束，但不释放内存，下一次调用该函数时值不变
* 类中static方法只能调用static成员，想要调用非static成员，与要通过对象调用static方法，正常通过`类名::方法名`调用static方法

## 二、类型转换

> <https://blog.csdn.net/qq_40421919/article/details/90677220>

### 1、static_cast

> static_cast<目标类型>（标识符）
>
> 所谓的静态,即在编译期内即可决定其类型的转换,用的也是最多的一种。

类似C风格的强制转换，进行无条件转换，静态类型转换：

1. 基类和子类之间的转换：其中子类指针转换为父类指针是安全的，但父类指针转换为子类指针是不安全的（基类和子类之间的动态类型转换建议用dynamic_cast）。
2. 基本数据类型转换，enum，struct，int，char，float等。static_cast不能进行无关类型（如非基类和子类）指针之间的转换。
3. 把任何类型的表达式转换成void类型。
4. static_cast不能去掉类型的const、volatile属性（用const_cast）。

### 2、const_cast

> const_cast<目标类型>（标识符）:目标类型只能是指针或者引用

去掉类型的const或volatile属性

**目标类型只能是引用或指针**

### 3、dynamic_cast

> dynamic_cast<目标类型>（标识符）
>
> 用于多态中父子类之间的多态转换

有条件转换，动态类型转换，运行时检查类型安全（转换失败返回NULL）：

1. 安全的基类和子类之间的转换。
2. 必须有虚函数。
3. 相同基类不同子类之间的交叉转换，但结果返回NULL。

#### 转换情况

* 至于“先上转型”（即派生类指针或引用类型转换为其基类类型），本身就是安全的，尽管可以使用dynamic_cast进行转换，但这是没必要的， 普通的转换已经可以达到目的，**毕竟使用dynamic_cast是需要开销的**。

* dynamic_cast主要用于“安全地向下转型”
  * 一种是基类指针所指对象是派生类类型的，这种转换是安全的；
  * 另一种是基类指针所指对象为基类类型，在这种情况下dynamic_cast在运行时做检查，转换失败，返回结果为NULL；

### 4、reinterpret_cast 重新解释类型转换

> reinterpret_cast<目标类型>（标识符）
>
> 数据的二进制重新解释，但是不改变其值。

仅重新解释类型，但没有进行二进制的转换：

1. 转换的类型必须是一个指针，应用、算术类型、函数指针或者成员指针。
2. 在比特级别上进行转换，可以把一个指针转换成一个整数，也可以把一个整数转换成一个指针（先把一个指针转换成一个整数，在把该整数转换成原类型的指针，还可以得到原先的指针值）。但不能将非32bit的实例转成指针。
3. 最普通的用途就是在函数指针类型之间进行转换。
4.  很难保证移植性。

### 总结

* 去const属性用const_cast
* 基本类型转换用static_cast
* 多态类之间的类型转换用dynamic_cast
* 不同类型的指针类型转换用reinterpret_cast

##  三、volatile

> 参考博客：
>
> <https://baijiahao.baidu.com/s?id=1663045221235771554&wfr=spider&for=pc>



## 四、虚函数和非虚函数

### 动态绑定和静态绑定

> 参考博客：
>
> <https://www.cnblogs.com/dongzhiquan/p/3789197.html>
>
> <https://www.cnblogs.com/xinxue/p/5471708.html>

#### 相关概念

对象的静态类型：对象在声明时采用的类型。是在编译期确定的。

对象的动态类型：目前所指对象的类型。是在运行期决定的。对象的动态类型可以更改，但是静态类型无法更改。

静态绑定：绑定的是对象的静态类型，某特性（比如函数）依赖于对象的静态类型，发生在编译期。

动态绑定：绑定的是对象的动态类型，某特性（比如函数）依赖于对象的动态类型，发生在运行期。

#### 绑定方式

**虚函数是动态绑定的，非虚函数是静态绑定的**

只有虚函数才使用的是动态绑定，其他的全部是静态绑定。目前我还没有发现不适用这句话的，如果有错误，希望你可以指出来。

```cpp
class B {
    void DoSomething();
    virtual void vfun();
};
class C : public B {
    void DoSomething();//首先说明一下，这个子类重新定义了父类的no-virtual函数，这是一个不好的设计，会导致名称遮掩；这里只是为了说明动态绑定和静态绑定才这样使用。
    virtual void vfun();
};
class D : public B {
    void DoSomething();
    virtual void vfun();
};

D* pD = new D();//pD的静态类型是它声明的类型D*，动态类型也是D*
B* pB = pD;//pB的静态类型是它声明的类型B*，动态类型是pB所指向的对象pD的类型D*
C* pC = new C();
pB = pC;//pB的动态类型是可以更改的，现在它的动态类型是C*
```

1、pD->DoSomething()和pB->DoSomething()调用的是同一个函数吗？

> 不是的，虽然pD和pB都指向同一个对象。因为函数DoSomething是一个no-virtual函数，它是静态绑定的，也就是编译器会在编译期根据对 象的静态类型来选择函数。pD的静态类型是`D*`，那么编译器在处理pD->DoSomething()的时候会将它指向 D::DoSomething()。同理，pB的静态类型是`B*`，那pB->DoSomething()调用的就是 B::DoSomething()。

2、让我们再来看一下，pD->vfun()和pB->vfun()调用的是同一个函数吗？

> 是的。因为vfun是一个虚函数，它动态绑定的，也就是说它绑定的是对象的动态类型，pB和pD虽然静态类型不同，但是他们同时指向一个对象，他们的动态类型是相同的，都是D*，所以，他们的调用的是同一个函数：D::vfun()。

**上面都是针对对象指针的情况，对于引用（reference）的情况同样适用。指针和引用的动态类型和静态类型可能会不一致，但是对象的动态类型和静态类型是一致的。**

##### 特别需要注意的地方

当缺省参数和虚函数一起出现的时候情况有点复杂，极易出错。我们知道，**虚函数是动态绑定的，但是为了执行效率，缺省参数是静态绑定的。**

```cpp
class B {
 virtual void vfun(int i = 10);
};
class D : public B {
 virtual void vfun(int i = 20);
};
D* pD = new D();
B* pB = pD;
pD->vfun();
pB->vfun();
```

1、有上面的分析可知pD->vfun()和pB->vfun()调用都是函数D::vfun()，但是他们的缺省参数是多少？

> 分析一下，缺省参数是静态绑定的，pD->vfun()时，pD的静态类型是D*，所以它的缺省参数应该是20；
>
> 同理，pB->vfun()的缺省参数应该是10。

对于这个特性，估计没有人会喜欢。所以，永远记住：
“**绝不重新定义继承而来的缺省参数**（Never redefine function’s inherited default parameters value.）”



## 五、智能指针

> 参考博客:
>
> <https://blog.csdn.net/weixin_39731083/article/details/81534333>
>
> <https://blog.csdn.net/weixin_43705457/article/details/97617676>

C++里面的四个智能指针: auto_ptr, **shared_ptr, weak_ptr, unique_ptr** 其中后三个是c++11支持，并且第一个已经被11弃用。

**不能混合使用普通指针和智能指针，因为智能指针不是单纯的赤裸裸的指针**

##### 为什么要使用智能指针：

智能指针的作用是管理一个指针，因为存在以下这种情况：申请的空间在函数结束时忘记释放，造成内存泄漏。使用智能指针可以很大程度上的避免这个问题，因为智能指针就是一个类，当超出了类的作用域是，类会自动调用析构函数，析构函数会自动释放资源。所以智能指针的作用原理就是在函数结束时自动释放内存空间，不需要手动释放内存空间。

### 1、auto_ptr（c++98的方案，cpp11已经抛弃）

采用所有权模式。

```cpp
auto_ptr< string> p1 (new string ("I reigned lonely as a cloud.”));
auto_ptr<string> p2;
p2 = p1; //auto_ptr不会报错.
```

此时不会报错，p2剥夺了p1的所有权，但是当程序运行时访问p1将会报错。所以auto_ptr的缺点是：存在潜在的内存崩溃问题！

### 2、unique_ptr（替换auto_ptr）

#### 简单解释

- 与shared_ptr不同，某一时刻，只能有一个unique_ptr指向一个给定的对象。因此，当unique_ptr被销毁,它所指的对象也会被销毁。
- unique_ptr的初始化必须采用直接初始化

#### 使用方法

```cpp
unique_ptr<string> p(new string("China"));
//没问题
 
unique_ptr<string> p (q);
//错误，不支持拷贝
 
unique_ptr<string> q;
 
q = p;
//错误,不支持赋值




unique_ptr<T> p;
//空智能指针，可指向类型是T的对象
 
if(p) 
//如果p指向一个对象,则是true
 
(*p)
//解引用获取指针所指向的对象
 
p -> number == (*p).number;
 
p.get();
//返回p中保存的指针
 
swap(p,q);
//交换p q指针
 
p.swap(q);
//交换p,q指针
 
unique_ptr<T,D>p;
//p使用D类型的可调用对象释放它的指针
 
p = nullptr;
//释放对象，将p置空
 
p.release();
//p放弃对指针的控制，返回指针，p置数空
 
p.reset();
//释放p指向的对象
 
p.reset(q);
//让u指向内置指针q
```

#### 举例

unique_ptr实现独占式拥有或严格拥有概念，保证同一时间内只有一个智能指针可以指向该对象。它对于避免资源泄露(例如“以new创建对象后因为发生异常而忘记调用delete”)特别有用。

采用所有权模式，还是上面那个例子

```cpp
unique_ptr<string> p3 (new string ("auto"));   //#4
unique_ptr<string> p4；                       //#5
p4 = p3;//此时会报错！！
```

编译器认为p4=p3非法，避免了p3不再指向有效数据的问题。因此，unique_ptr比auto_ptr更安全。

另外unique_ptr还有更聪明的地方：当程序试图将一个 unique_ptr 赋值给另一个时，如果源 unique_ptr 是个临时右值，编译器允许这么做；如果源 unique_ptr 将存在一段时间，编译器将禁止这么做，比如：

```cpp
unique_ptr<string> pu1(new string ("hello world"));
unique_ptr<string> pu2;
pu2 = pu1;                                      // #1 not allowed
unique_ptr<string> pu3;
pu3 = unique_ptr<string>(new string ("You"));   // #2 allowed
```

其中#1留下悬挂的unique_ptr(pu1)，这可能导致危害。而#2不会留下悬挂的unique_ptr，因为它调用 unique_ptr 的构造函数，该构造函数创建的临时对象在其所有权让给 pu3 后就会被销毁。这种随情况而已的行为表明，unique_ptr 优于允许两种赋值的auto_ptr 。

注：如果确实想执行类似与#1的操作，要安全的重用这种指针，可给它赋新值。C++有一个标准库函数std::move()，让你能够将一个unique_ptr赋给另一个。例如：

```cpp
unique_ptr<string> ps1, ps2;
ps1 = demo("hello");
ps2 = move(ps1);
ps1 = demo("alexia");
cout << *ps2 << *ps1 << endl;
```





### 3、shared_ptr

shared_ptr实现共享式拥有概念。多个智能指针可以指向相同对象，该对象和其相关资源会在“最后一个引用被销毁”时候释放。从名字share就可以看出了资源可以被多个指针共享，它使用计数机制来表明资源被几个指针共享。可以通过成员函数use_count()来查看资源的所有者个数。除了可以通过new来构造，还可以通过传入auto_ptr, unique_ptr,weak_ptr来构造。当我们调用release()时，当前指针会释放资源所有权，计数减一。当计数等于0时，资源会被释放。

shared_ptr 是为了解决 auto_ptr 在对象所有权上的局限性(auto_ptr 是独占的), 在使用引用计数的机制上提供了可以共享所有权的智能指针。



成员函数：

| use_count | 返回引用计数的个数                                           |
| --------- | ------------------------------------------------------------ |
| unique    | 返回是否是独占所有权( use_count 为 1)                        |
| swap      | 交换两个 shared_ptr 对象(即交换所拥有的对象)                 |
| reset     | 放弃内部对象的所有权或拥有对象的变更, 会引起原有对象的引用计数的减少 |
| get       | 返回内部对象(指针), 由于已经重载了()方法, 因此和直接使用对象是一样的.如 `shared_ptr<int> sp(new int(1)); `sp 与 sp.get()是等价的 |



#### 使用方法

```cpp
shared_ptr<int> p1;
//被初始化成为一个空指针
 
shared_ptr<int> p2 (new int(4));
//指向一个值是4的int类型数据
 
shared_ptr<int> p3 = new int(4);
//错误，必须直接初始化


shared_ptr<T> p;
//空智能指针，可指向类型是T的对象
 
if(p)
 //如果p指向一个对象,则是true
 
(*p)
//解引用获取指针所指向的对象
 
p -> number == (*p).number;
 
p.get();
//返回p中保存的指针
 
swap(p,q);
//交换p q指针
 
p.swap(q);
//交换p,q指针
 
make_shared<T>(args) 
//返回一个shared_ptr的对象，指向一个动态类型分配为T的对象，用args初始化这个T对象
 
shared_ptr<T> p(q)
//p 是q的拷贝，q的计数器++，这个的使用前提是q的类型能够转化成是T*
 
shared_pts<T> p(q,d) 
//p是q的拷贝,p将用可调用对象d代替delete
//上面这个我其实没懂，也没有查出来这个的意思
 
p =q;
//p的引用计数-1，q的+1,p为零释放所管理的内存
 
p.unique();
//判断引用计数是否是1，是，返回true
 
p.use_count();
//返回和p共享对象的智能指针数量
 
p.reset();
p.reset(q);
p.reset(q,d);
//reset()没懂，这个以后再来补充吧
```





### 4、weak_ptr

#### 简单解释

weak_ptr是一种不控制所指向对象生存期的智能指针，指向shared_ptr管理的对象，但是不影响shared_ptr的引用计数。它像shared_ptr的助手，一旦最后一个shared_ptr被销毁,对象就被释放，weak_ptr不影响这个过程。



**weak_ptr不可以从unique_ptr构造出来**

weak_ptr获得指向的对象的方法是使用lock函数，这个函数返回的是shared_ptr。首先我们就没有办法把unique_ptr和shared_ptr混在一起用，因为独占和分享是互斥的，同时只能选择一个。其次，如果我们真的有一个unique_ptr版本的，那么lock函数到底要返回什么呢？如果返回的是一个unique_ptr的话，那么所有权已经被拿过来了，我们就等于破坏了原本用来构造weak_ptr的unique_ptr的所有权。如果大家想要完成的是这种功能的话，为什么不直接使用unique_ptr

#### 使用方法

```cpp
weak_ptr<T> w(sp);
//定义一个和shared_ptr sp指向相同对象的weak_ptr w,T必须能转化成sp指向的类型
 
w = p;
//p是shared_ptr或者weak_ptr，w和p共享对象
 
w.reset();
//w置为空
 
w.use_count();
//计算与w共享对象的shared_ptr个数
 
w.expired();
//w.use_count()为0，返回true
 
w.lock();
//w.expired()为true，返回空shared_ptr,否则返回w指向对象的shared_ptr
```

#### 举例

weak_ptr 是一种不控制对象生命周期的智能指针, 它指向一个 shared_ptr 管理的对象. 进行该对象的内存管理的是那个强引用的 shared_ptr. weak_ptr只是提供了对管理对象的一个访问手段。weak_ptr 设计的目的是为配合 shared_ptr 而引入的一种智能指针来协助 shared_ptr 工作, 它只可以从一个 shared_ptr 或另一个 weak_ptr 对象构造, 它的构造和析构不会引起引用记数的增加或减少。weak_ptr是用来解决shared_ptr相互引用时的死锁问题,如果说两个shared_ptr相互引用,那么这两个指针的引用计数永远不可能下降为0,资源永远不会释放。它是对对象的一种弱引用，不会增加对象的引用计数，和shared_ptr之间可以相互转化，shared_ptr可以直接赋值给它，它可以通过调用lock函数来获得shared_ptr。

```cpp
class B;
class A
{
public:
shared_ptr<B> pb_;
~A()
{
cout<<"A delete\n";
}
};
class B
{
public:
shared_ptr<A> pa_;
~B()
{
cout<<"B delete\n";
}
};
void fun()
{
shared_ptr<B> pb(new B());
shared_ptr<A> pa(new A());
pb->pa_ = pa;
pa->pb_ = pb;
cout<<pb.use_count()<<endl;
cout<<pa.use_count()<<endl;
}
int main()
{
fun();
return 0;
}
```

可以看到fun函数中pa ，pb之间互相引用，两个资源的引用计数为2，当要跳出函数时，智能指针pa，pb析构时两个资源引用计数会减一，但是两者引用计数还是为1，导致跳出函数时资源没有被释放（A B的析构函数没有被调用），如果把其中一个改为weak_ptr就可以了，我们把类A里面的shared_ptr pb_; 改为weak_ptr pb_; 运行结果如下，这样的话，资源B的引用开始就只有1，当pb析构时，B的计数变为0，B得到释放，B释放的同时也会使A的计数减一，同时pa析构时使A的计数减一，那么A的计数为0，A得到释放。

**注意的是我们不能通过weak_ptr直接访问对象的方法**，比如B对象中有一个方法print(),我们不能这样访问，`pa->pb_->print()`; 英文`pb_`是一个weak_ptr，**应该先把它转化为shared_ptr**,如：`shared_ptr p = pa->pb_.lock(); p->print();`



### 5、注意

**智能指针没有重载 [] 运算符**

**shared_ptr 在默认情况下是不能指向数组的。**

> 原因：因为我们的 shared_ptr 默认的删除器是使用 Delete 对智能指针中的对象进行删除，而 delete 要求 new 时是单一指针 Delete时也应该是指针 new时是数组 delete 也应该用数组类型去delete

#### 1、shared_ptr

所以我们如果想让我们的 share_ptr 去指向指针 我们只需要去使用一个可调用对象即可 在这种情况下比较常用的函数或者lambda表达式均可

```cpp
bool del(int *p){
    delete [] p;
}

shared_ptr<int> shared(new int[100],del);//使用函数

shared_ptr<int> ptr(new int[100], [](int *p){delete [] p;});//使用lambda表达式
```

因为智能指针没有重载下标运算符 意味着我们不能想数组那样去使用这个指针 那怎么样才可以使用呢

shared_ptr 有一个函数可以返回当前智能指针的内置指针的函数 就是成员函数get() 但是我们要注意当智能指针指针已经释放内存以后，get得到的指针就成了空悬指针
有一点需要注意 在我们得到get返回的指针以后，智能指针对象的引用计数其实并没有增加

`get() const noexcept { return _M_ptr; }`

**但是如果我们delete从get得到的指针 并不会出现多次delete的错误**

```cpp
auto x = ptr.get();
cout << *(x+i) << endl;
```

#### 2、unique_ptr

**其实只是C++11 中不支持而已 C++17中已经支持**


相比与shared_ptr unique_ptr对于动态数组的管理就轻松多了 我们只需要直接使用即可

```cpp
unique_ptr<int[]>unique(new int[100]);
```

**而且unique_ptr是重载了下标运算符的，意味着我们可以方便把其当数组一样使用**

#### 3、Boost C++库

著名的Boost库其实是支持指向数组的，使用方法与unique_ptr差不多

**类名为`boost::shared_array`，定义在`<boost/shared_ptr.hpp>`**

```cpp
boost::shared_array<int> arr(new int[100]); 
```



### 6、野指针

#### 1. 什么是野指针？

野指针和空指针不一样，是一个指向垃圾内存的指针。

#### 2. 为什么会产生野指针？

**①指针变量没有被初始化：**

任何指针变量被刚创建时不会被自动初始化为NULL指针，它的缺省值是随机的。所以，指针变量在创建的同时应当被初始化，要么将指针设置为NULL，要么让它指向合法的内存。

**②指针被free或者delete之后，没有设置为NULL，让人误以为这是一个合法指针：**
free和delete只是把指针所指向的内存给释放掉，但并没有把指针本身给清理掉。这时候的指针依然指向原来的位置，只不过这个位置的内存数据已经被毁尸灭迹，此时的这个指针指向的内存就是一个垃圾内存。但是此时的指针由于并不是一个NULL指针（在没有置为NULL的前提下）。

**③指针操作超越了变量的作用范围：**
由于C/C++中指针有++操作，因而在执行该操作的时候，稍有不慎，就容易指针访问越界，访问了一个不该访问的内存，结果程序崩溃。
另一种情况是指针指向一个临时变量的引用，当该变量被释放时，此时的指针就变成了一个野指针。



## 六、C++存储区

**对于局部常量，存放在栈区；对于全局常量，编译期一般不分配内存，放在符号表中以提高访问效率；字面值常量，比如字符串，放在常量区。**

![存储区](imgs\存储区.png)

* **栈**，就是那些由编译器在需要的时候分配，在不需要的时候自动清楚的变量的存储区。里面的变量通常是局部变量、函数参数等。
* **堆，**就是那些由malloc等分配的内存块，用free来结束自己的生命的。
* **3.自由存储区，**就是那些由new分配的内存块，他们的释放编译器不去管，由我们的应用程序去控制，一般一个new就要对应一个delete。如果程序员没有释放掉，那么在程序结束后，操作系统会自动回收。
* **4.全局/静态存储区**，全局变量和静态变量被分配到同一块内存中，在以前的C语言中，全局变量又分为初始化的和未初始化的，在C++里面没有这个区分了，他们共同占用同一块内存区。
* **5.常量存储区，**这是一块比较特殊的存储区，他们里面存放的是常量，不允许修改（当然，你要通过非正当手段也可以修改）
* 代码区：存放程序的代码。

> 常量在C++里的定义就是一个top-level const加上对象类型，常量定义必须初始化。对于局部对象，常量存放在栈区，对于全局对象，常量存放在全局/静态存储区。对于字面值常量，常量存放在常量存储区。
>
> const 和一般变量的存储去没有区别只是是只读，"hello"这种字面值常量才存放在常量存储区

### 堆栈的区别

* 管理方式不同；
* 空间大小不同；
* 能否产生碎片不同；
* 生长方向不同；
* 分配方式不同；
* 分配效率不同；

### 自由存储区和堆“free store” VS “heap”

当我问你C++的内存布局时，你大概会回答：

> “在C++中，内存区分为5个区，分别是堆、栈、自由存储区、全局/静态存储区、常量存储区”。

如果我接着问你自由存储区与堆有什么区别，你或许这样回答：

> “malloc在堆上分配的内存块，使用free释放内存，而new所申请的内存则是在自由存储区上，使用delete来释放。”

这样听起来似乎也没错，但如果我接着问：

> 自由存储区与堆是两块不同的内存区域吗？它们有可能相同吗？

你可能就懵了。

事实上，我在网上看的很多博客，划分自由存储区与堆的分界线就是new/delete与malloc/free。然而，尽管C++标准没有要求，但很多编译器的new/delete都是以malloc/free为基础来实现的。那么请问：借以malloc实现的new，所申请的内存是在堆上还是在自由存储区上？

从技术上来说，堆（heap）是C语言和操作系统的术语。堆是操作系统所维护的一块特殊内存，它提供了动态分配的功能，当运行程序调用malloc()时就会从中分配，稍后调用free可把内存交还。而自由存储是C++中通过new和delete动态分配和释放对象的抽象概念，通过new来申请的内存区域可称为自由存储区。基本上，所有的C++编译器默认使用堆来实现自由存储，也即是缺省的全局运算符new和delete也许会按照malloc和free的方式来被实现，这时藉由new运算符分配的对象，说它在堆上也对，说它在自由存储区上也正确。但程序员也可以通过重载操作符，改用其他内存来实现自由存储，例如全局变量做的对象池，这时自由存储区就区别于堆了。我们所需要记住的就是：

> 堆是操作系统维护的一块内存，而自由存储是C++中通过new与delete动态分配和释放对象的抽象概念。堆与自由存储区并不等价。

### 结论

- 自由存储是C++中通过new与delete动态分配和释放对象的**抽象概念**，而堆（heap）是C语言和操作系统的术语，是操作系统维护的一块动态分配内存。
- new所申请的内存区域在C++中称为自由存储区。藉由堆实现的自由存储，可以说new所申请的内存区域在堆上。
- 堆与自由存储区还是有区别的，它们并非等价。

假如你来自C语言，从没接触过C++；或者说你一开始就熟悉C++的自由储存概念，而从没听说过C语言的malloc，可能你就不会陷入“自由存储区与堆好像一样，好像又不同”这样的迷惑之中。这就像Bjarne Stroustrup所说的：

> usually because they come from a different language background.



## 七、const 和 constexpr

> <https://blog.csdn.net/u010843408/article/details/107288934/>
>
> c++11 constexpr：<https://www.cnblogs.com/ljwgis/p/13095739.html>
>
> 运行期常量和编译期常量：<https://blog.csdn.net/quinta_2018_01_09/article/details/95727536>

常量在C++里的定义就是一个top-level const加上对象类型，常量定义必须初始化。对于局部对象，常量存放在栈区，对于全局对象，常量存放在全局/静态存储区。对于字面值常量，常量存放在常量存储区。

const 和一般变量的存储去没有区别只是是只读，"hello"这种字面值常量才存放在常量存储区

const 是运行期常量，constexpr 是编译期常量

**在 C++11 以后，建议凡是「常量」语义的场景都使用 constexpr，只对「只读」语义使用 const。**

## 八、缺省参数

在C++中，允许实参的个数与形参的个数不同。在声明函数原型时，为一个或者多个形参指定默认值，以后调用这个函数时，若省略某一个实参，c++则自动的以默认值作为相应参数的值。



**在定义的过程中，一定要把缺省参数放在最后**

```cpp
void func(int x, int y = 1, int z = 2) // 合法
void func(int x = 1, int y, int z = 2); // 不合法
```

**在调用的过程中会按照顺序复制**

```cpp
double func(int x, int y = 1, double z = 2.9) {
	return x + y + z;
}

func(1, 2, 5.7); // 8.7
func(1, 2.3); // 5.9
```



## 九、栈溢出

> <https://blog.csdn.net/sinat_31054897/article/details/82223889>



## 十、friend

### 模板类中的友元函数

模板类中的友元函数，直接定义在模板类中会比较方便。

**在外面定义时，由于类模板编译时的规则：**

* 下面代码中，operator +=被定义在类模板内部。其他3个函数先被声明(需提前声明类模板，如果模板函数的参数中含有类模板)，然后在类模板中被声明为友元函数， 之后被定义在类模板体之外。
* 请注意当模板函数被声明为类模板的友元时，在函数名之后必须紧跟模板实参表，用来代表该友元声明指向函数模板的实例。否则友元函数会被解释为一个非模板函数，链接时无法解析。
* 友元模板函数的模板参数类型，并不一定要求是类模板的参数类型，也可以另外声明。

```cpp
#include <iostream>
#include <vector>

template <typename T>
class Number;

template <typename T>
void print(const Number<T>& n);

template <typename T>
std::ostream& operator << (std::ostream& os, const Number<T>& n);

template <typename T>
std::istream& operator>>(std::istream& is, Number<T>& n);

template <typename T, typename T2>
void printVector(const std::vector<T2>& vt, const Number<T>& n);

template <typename T>
class Number {
public:
    Number(T v) : val(v) {}
    ~Number() {}

private:
    T val;
public:
	friend void print<T> (const Number<T>& n);
    friend std::ostream& operator << <T>(std::ostream& os, const Number<T>& n);
    friend std::istream& operator>> <T>(std::istream& is, Number<T>& n);

    friend Number<T>& operator += (Number<T>& a, const Number<T>& b) {
        a.val += b.val;
        return a;
    }

    template <typename T2>
    friend void printVector<T>(const std::vector<T2>& vt, const Number<T>& n);
    
    template <typename T2>
    void memFunc(const std::vector<T2>& vt, const Number<T>& n);
};

template <typename T>
std::ostream& operator <<(std::ostream& os, const Number<T>& n) {
    os << n.val << std::endl;
    return os;
}

template <typename T>
std::istream& operator >>(std::istream& is, Number<T>& n) {
	is >> n.val;
    return is;
}
 
template <typename T>
void print<T> (const Number<T>& n) {
    std::cout << n;
}

template <typename T, typename T2>
void printVector(const std::vector<T2>& vt, const Number<T>& n) {
    for (unsigned int i = 0; i < vt.size(); i++)
        std::cout << vt.at(i) << " ";
    std::cout << "=> " << n;
}

template <typename T>
template <typename T2>
void Number<T>::memFunc(const std::vector<T2>& vt, const Number<T>& n) {
    for (unsigned int i = 0; i < vt.size(); i++)
        std::cout << vt.at(i) << " ";
    std::cout << "=> " << n;
}
```

### 友元类

```cpp
class CatFactory; // 一定要声明，否则 Cat 会认为在给 Cat::CatFactory 开后门

class Cat {
	friend class CatFactory;
private:
    Cat() = default;
    ~Cat() = default;
};

class CatFactory {
public:

};
```





## 十一、访问权限

### private,public,protected的访问范围:

private: 只能由该类中的函数、其友元函数访问,不能被任何其他访问，该类的对象也不能访问. 
protected: 可以被该类中的函数、子类的函数、以及其友元函数访问,但不能被该类的对象访问
public: 可以被该类中的函数、子类的函数、其友元函数访问,也可以由该类的对象访问
注：友元函数包括两种：设为友元的全局函数，设为友元类中的成员函数



第二:类的继承后方法属性变化:
使用private继承,父类的所有方法在子类中变为private; 
使用protected继承,父类的protected和public方法在子类中变为protected,private方法不变; 
使用public继承,父类中的方法属性不发生改变;



**三种访问权限**

**public:**可以被任意实体访问

**protected:**只允许子类及本类的成员函数访问

**private:**只允许本类的成员函数访问



**三种继承方式**

public 继承

protect 继承

private 继承



**组合结果**

基类中 继承方式 子类中

public ＆ public继承 => public

public ＆ protected继承 => protected

public ＆ private继承 = > private


protected ＆ public继承 => protected

protected ＆ protected继承 => protected

protected ＆ private继承 = > private


private ＆ public继承 => 子类无权访问

private ＆ protected继承 => 子类无权访问

private ＆ private继承 = > 子类无权访问



**由以上组合结果可以看出**

1、public继承不改变基类成员的访问权限

2、private继承使得基类所有成员在子类中的访问权限变为private

3、protected继承将基类中public成员变为子类的protected成员，其它成员的访问 权限不变。

4、基类中的private成员不受继承方式的影响，子类永远无权访问。

此外，在使用private继承时，还存在另外一种机制：准许访问 。

我们已经知道，在基类以private方式被继承时，其public和protected成员在子类中变为private成员。然而某些情况下，需要在子类中将一个或多个继承的成员恢复其在基类中的访问权限。



**C++支持以两种方式实现该目的**

**方法一，**使用using 语句，这是C++标准建议使用的方式

**方法二，**使用访问声明，形式为 base-class::member;， 位置在子类中适当的访问声明处。(注，只能恢复原有访问权限，而不能提高或降低访问权限)

## 十二、explicit关键字

首先, C++中的explicit关键字只能用于修饰只有一个参数的类构造函数, 它的作用是表明该构造函数是显示的, 而非隐式的, 跟它相对应的另一个关键字是implicit, 意思是隐藏的,类构造函数默认情况下即声明为implicit(隐式).

那么显示声明的构造函数和隐式声明的有什么区别呢? 我们来看下面的例子:

```c+
class CxString  // 没有使用explicit关键字的类声明, 即默认为隐式声明  
{  
public:  
    char *_pstr;  
    int _size;  
    CxString(int size)  
    {  
        _size = size;                // string的预设大小  
        _pstr = malloc(size + 1);    // 分配string的内存  
        memset(_pstr, 0, size + 1);  
    }  
    CxString(const char *p)  
    {  
        int size = strlen(p);  
        _pstr = malloc(size + 1);    // 分配string的内存  
        strcpy(_pstr, p);            // 复制字符串  
        _size = strlen(_pstr);  
    }  
    // 析构函数这里不讨论, 省略...  
};  
// 下面是调用:  
  
CxString string1(24);     // 这样是OK的, 为CxString预分配24字节的大小的内存  
CxString string2 = 10;    // 这样是OK的, 为CxString预分配10字节的大小的内存  
CxString string3;         // 这样是不行的, 因为没有默认构造函数, 错误为: “CxString”: 没有合适的默认构造函数可用  
CxString string4("aaaa"); // 这样是OK的  
CxString string5 = "bbb"; // 这样也是OK的, 调用的是CxString(const char *p)  
CxString string6 = 'c';   // 这样也是OK的, 其实调用的是CxString(int size), 且size等于'c'的ascii码  
string1 = 2;              // 这样也是OK的, 为CxString预分配2字节的大小的内存  
string2 = 3;              // 这样也是OK的, 为CxString预分配3字节的大小的内存  
string3 = string1;        // 这样也是OK的, 至少编译是没问题的, 但是如果析构函数里用free释放_pstr内存指针的时候可能会报错, 完整的代码必须重载运算符"=", 并在其中处理内存释放  
```

 上面的代码中, "CxString string2 = 10;" 这句为什么是可以的呢? 在C++中, 如果的构造函数只有一个参数时, 那么在编译的时候就会有一个缺省的转换操作:将该构造函数对应数据类型的数据转换为该类对象. 也就是说 "CxString string2 = 10;" 这段代码, 编译器自动将整型转换为CxString类对象, 实际上等同于下面的操作:

```c++
CxString string2(10);  
或  
CxString temp(10);  
CxString string2 = temp; 
```



但是, 上面的代码中的_size代表的是字符串内存分配的大小, 那么调用的第二句 "CxString string2 = 10;" 和第六句 "CxString string6 = 'c';" 就显得不伦不类, 而且容易让人疑惑. 有什么办法阻止这种用法呢? 答案就是使用explicit关键字. 我们把上面的代码修改一下, 如下:



    class CxString  // 使用关键字explicit的类声明, 显示转换  
    {  
    public:  
        char *_pstr;  
        int _size;  
        explicit CxString(int size)  
        {  
            _size = size;  
            // 代码同上, 省略...  
        }  
        CxString(const char *p)  
        {  
            // 代码同上, 省略...  
        }  
    };  
    // 下面是调用:  
      
    CxString string1(24);     // 这样是OK的  
    CxString string2 = 10;    // 这样是不行的, 因为explicit关键字取消了隐式转换  
    CxString string3;         // 这样是不行的, 因为没有默认构造函数  
    CxString string4("aaaa"); // 这样是OK的  
    CxString string5 = "bbb"; // 这样也是OK的, 调用的是CxString(const char *p)  
    CxString string6 = 'c';   // 这样是不行的, 其实调用的是CxString(int size), 且size等于'c'的ascii码, 但explicit关键字取消了隐式转换  
    string1 = 2;              // 这样也是不行的, 因为取消了隐式转换  
    string2 = 3;              // 这样也是不行的, 因为取消了隐式转换  
    string3 = string1;        // 这样也是不行的, 因为取消了隐式转换, 除非类实现操作符"="的重载  
 explicit关键字的作用就是防止类构造函数的隐式自动转换.

上面也已经说过了, explicit关键字只对有一个参数的类构造函数有效, 如果类构造函数参数大于或等于两个时, 是不会产生隐式转换的, 所以explicit关键字也就无效了. 例如: 

    class CxString  // explicit关键字在类构造函数参数大于或等于两个时无效  
    {  
    public:  
        char *_pstr;  
        int _age;  
        int _size;  
        explicit CxString(int age, int size)  
        {  
            _age = age;  
            _size = size;  
            // 代码同上, 省略...  
        }  
        CxString(const char *p)  
        {  
            // 代码同上, 省略...  
        }  
    };  
    // 这个时候有没有explicit关键字都是一样的  
但是, 也有一个例外, 就是当除了第一个参数以外的其他参数都有默认值的时候, explicit关键字依然有效, 此时, 当调用构造函数时只传入一个参数, 等效于只有一个参数的类构造函数。

## STL

### emplace_back

添加一个新元素到结束的容器。该元件是构成在就地，即没有复制或移动操作进行。就是empace_back与push_back相比，替我们省去了拷贝构造。



## C++11

### {} 和 () 

#### 简述

**{}是c++11新的初始化方式**

所谓花括号列表初始化，即是用花括号来初始化变量，其形式如： int  test =  { 0 } ；无论是初始化对象还是为对象赋值 ， 在C++11下都可以使用这种形式的初始值。

   不同的一点 是：使用这种形式来初始化内置类型的变量时，若存在类型转换且具有丢失信息的风险时，编译器将会报错。

#### 举例说明

C++11之前主要有以下几种初始化方式：

```cpp
//小括号初始化
string str("hello");


//等号初始化
string str="hello";


//POD对象与POD数组列表初始化
struct Studnet {
    char* name;
    int age;
};

Studnet s={"dablelv",18}; //纯数据（Plain of Data,POD）类型对象
Studnet sArr[]={{"dablelv",18},{"tommy",19}};  //POD数组



//构造函数的初始化列表
class Class {
    int x;
public:
    Class(): x(0){} 
};
```

在C++11以前，程序员，或者初学者经常会感到疑惑关于怎样去初始化一个变量或者是一个对象。这么多的对象初始化方式，不仅增加了学习成本，也使得代码风格有较大出入，影响了代码的可读性和统一性。

从C++11开始，对列表初始化（List Initialization）的功能进行了扩充，可以作用于任何类型对象的初始化，至此，列表初始化方式完成了天下大一统。

花括号列表初始化，作为C++11新标准的一部被加入到了C++中。

因为这个原因，c++11提出了统一初始化，以为着使用这初始化列表，下面的做法都是正确的。

```cpp
class Test {
    int a;
    int b;
public:    
    C(int i, int j);    
};    


Test t{0,0};                    //C++11 only，相当于 Test t(0,0);    
Test* pT=new Test{1,2};         //C++11 only，相当于 Test* pT=new Test(1,2);

int* a = new int[3]{1,2,0};    //C++11 only
```

此外，C++11列表初始化还可以应用于容器，终于可以摆脱 push_back() 调用了，C++11中可以直观地初始化容器： 

```cpp
//C++11 container initializer
vector<string> vs={"first", "second", "third"};    

map<string,string> singers ={{"Lady Gaga", "+1 (212) 555-7890"},{"Beyonce Knowles", "+1 (212) 555-0987"}};
```

因此，可以将C++11提供的列表初始化作为统一的初始化方式，既降低了记忆难度，也提高的代码的统一度。

此外，C++11中，类的数据成员在申明时可以直接赋予一个默认值：

```cpp
class C {
private:  
    int a=7; //C++11 only
};    
```

所谓花括号列表初始化，即是用花括号来初始化变量，其形式如： int  test =  { 0 } ；无论是初始化对象还是为对象赋值 ， 在C++11下都可以使用这种形式的初始值。

   不同的一点 是：使用这种形式来初始化内置类型的变量时，若存在类型转换且具有丢失信息的风险时，编译器将会报错。

  通过这一点可以看出，列表初始化比原有的初始化方式具有更严格的安全要求。下面是例子：

 ```cpp
long double ld = 3.1415926536；
int a {ld} ， b = {ld}         // 编译器报错，存在丢失信息的风险
int c （ld）  , d = ld ;    //正确
 ```

### lambda表达式

#### 简介

lambda表达式相当于旧时代的函数指针，但它的很多功能是函数指针所做不到的

lambda表达式的一般形式：

 [capture list] (parameter list) -> return type{function body}; 

其中，capture list (捕获列表）是一个lambda所在函数中定义的局部变量的列表（通常为空）；

return type、parameter list和function body与任何普通函数一样分别表示返回类型、参数列表和函数体。

但是与普通函数不同，lambda必须使用尾置返回来指定返回类型。

此外，我可以忽略参数列表和返回类型，但必须永远包含捕获列表和函数体：

```
auto f = [] { return 42 }
```

调用方式：与普通函数一致；

```
cout << f() << endl;
```

在忽略了返回值类型的情况下， lambda根据函数体中代码推断出返回值类型；如果函数体只是一个return语句，则返回类型从返回的表达式的类型推断而来。否则，返回类型为void。

使用条件：

“引用捕获有时是必要的。例如， 我们可能希望biggies函数接受一个ostream的引用，用来输出数据，并接受一个字符作为分隔符：”

```
void biggies(vector<string> &words, 
                  vector<string> ::size_type sz,
                  ostream &os = cout, char c = ' ')
{
     //打印count的语句改为打印到os
    for_each(words.begin(), words.end(),
                  [&os, c] (const string &s) { os << s << c; });          
}
```

我们不能拷贝ostream对象，因此捕获os的唯一方法就是捕获其引用（或指向os的指针）。

注意：当引用方式捕获一个变量时，必须保证lambda执行时变量是存在的。

 

一般来说，我们应该尽量减少捕获的数据量，来避免潜在的捕获导致的问题。而且，如果可能的话，应该避免捕获指针或引用。

可以注意到 lambda 表达式和函数指针的区别：

* 函数指针的声明比较复杂。虽然在这个例子里面还不怎么看出来，但是里面的东西一多，你就只好不断地`typedef`
* 使用函数指针会使得代码逻辑分散。其实这个在 vector 和排序的例子里面已经提到过了。lambda 表达式可以让所有相关的代码都放在一起。而使用函数指针经常会让你把几段完整的表达逻辑的代码分散在不同的函数里面，难以阅读。

**[捕获值列表]:**

* 空。没有使用任何函数对象参数。

* =。函数体内可以使用Lambda所在作用范围内所有可见的局部变量（包括Lambda所在类的this），并且是值传递方式（相当于编译器自动为我们按值传递了所有局部变量）。

* &。函数体内可以使用Lambda所在作用范围内所有可见的局部变量（包括Lambda所在类的this），并且是引用传递方式（相当于编译器自动为我们按引用传递了所有局部变量）。

* this。函数体内可以使用Lambda所在类中的成员变量。

* a。将a按值进行传递。按值进行传递时，函数体内不能修改传递进来的a的拷贝，因为默认情况下函数是const的。要修改传递进来的a的拷贝，可以添加mutable修饰符。

* &a。将a按引用进行传递。

* a, &b。将a按值进行传递，b按引用进行传递。

* =，&a, &b。除a和b按引用进行传递外，其他参数都按值进行传递。

* &, a, b。除a和b按值进行传递外，其他参数都按引用进行传递。

**注意：lambda 表达式在使用全局变量的时候，不能够选择要复制它还是引用它。因为非局部变量，如静态变量、全局变量等可以不经捕获，直接使用lambda 表达式即可修改。**

