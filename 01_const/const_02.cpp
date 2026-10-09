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
