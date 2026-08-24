### const 正确性

- const 修饰变量：const int*、int* const、const int\* const

```c++
#include <iostream>

// const 修饰变量：const int*、int* const、const int* const
int main()
{
    int a = 10;
    int b = 20;

    // 指向常量的指针
    const int *p = &a;
    std::cout << "*p a " << *p << std::endl;
    p = &b; // 可以改变指向
    std::cout << "*p b " << *p << std::endl;
    // *p = 20; // 不可以改变值

    // 常量指针
    int *const p1 = &a;
    std::cout << "*p1 a " << *p1 << std::endl;
    *p1 = 20; // 可以改变值
    std::cout << "*p1 a " << *p1 << std::endl;
    std::cout << "a " << a << std::endl; // 20
    // p1 = &b; // 不可以改变指向

    // 指向常量的常量指针
    const int *const p3 = &a;
    // *p3 = &b;
    // *p3 = 50;
    std::cout << "*p3 a " << *p3 << std::endl;
    return 0;
}
```

- const 成员函数与 mutable

```c++
#include <iostream>
#include <list>

// 1.const 成员函数与 mutable
class Circle
{
public:
    double area() const
    {
        // const 在修饰 this 指针
        // 修饰完成后this指针变成 const Circle*
        // 也就是指向常量的指针
        // 能读成员变量
        // 不能改成员变量
        // 不能调用非 const 成员函数（会编译报错）
        return _area;
    };

private:
    double _area;
};

// 2.mutable 有些操作逻辑上不改对象，但物理上要动一下内部状态。此时 const 成员函数里改成员会编译报错，就加 mutable
// mutable 成员如果被多个线程同时改，要加锁
class shape
{
public:
    double area() const
    {
        _cacheArea = 1.0 * _cacheArea;
        return _cacheArea;
    }

private:
    mutable double _cacheArea = 1.2;
};

// 3.const 函数里调用非 const 函数
class Od
{
public:
    double length() const { return _list.size(); } // size() 本身是 const，OK
    // double bad() const { return _list.append(1); } // 编译错误

private:
    std::list<int> _list;
};

// 4.const 对象 → 调 const 版本（只读）
// 非 const 对象 → 调非 const 版本（可改）
// 这正是 QList、std::string 里 operator[] 有重载的原因。
class example
{
public:
    std::string &operator[](int i) {}             // 可修改版本
    const std::string &operator[](int i) const {} // 只读版本
};

int main(int argc, char const *argv[])
{
    return 0;
}
```

- 顶层 const 与底层 const

  > 顶层const = 修饰对象本身（int* const p 里的 const）；底层 const = 修饰指向的对象（const int* p 里的 const）。

- constexpr 变量与函数基础

```c++
  constexpr int square(int x) { return x \* x; } // 编译期求值
  const int x = square(5); // 若参数是编译期常量，square(5) 在编译期就算完
```

const = 运行期不可改；
constexpr = 强制编译期求值（能编译期算就编译期算）。
