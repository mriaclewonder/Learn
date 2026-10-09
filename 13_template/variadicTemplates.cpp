#include <iostream>

// 可变模板，泛化和特化

namespace variadicTemplates
{
    // 可变参数可用来做递归
    void printf()
    {
        // 最后没参数了调用函数重载版本
    }

    template <typename T, typename... Types>
    void printf(const T &first_arg, const Types &...args)
    {
        std::cout << first_arg << std::endl;
        printf(args...);
    }

    template <typename T>
    void printf(const T &x)
    {
        std::cout << x << std::endl;
    }

    template <>
    void printf<bool>(const bool &x)
    {
        std::cout << "hello world" << std::endl;
    }

    /*
    // 偏特化，只有个别类型固定
    // 函数模板不支持偏特化
    template <typename U>
    void printf<int, U>(int n, const U &m)
    {
    }
    */
}

int main(int argc, char const *argv[])
{
    // ① 多参数递归：1 / 1 / hello
    variadicTemplates::printf(1, 1.0, "hello");

    // ② 混合类型：A / 3.14 / 100
    variadicTemplates::printf('A', 3.14f, 100);

    // ③ 单参数：42
    variadicTemplates::printf(42);

    // ④ bool：走全特化 printf<bool> → 当前空体，无输出
    variadicTemplates::printf(true);

    // ⑤ 无参数：非模板 printf() → 无输出
    variadicTemplates::printf();
    return 0;
}
