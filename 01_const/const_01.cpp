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