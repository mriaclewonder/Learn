#include <iostream>
#include <type_traits>

namespace week_05
{
    struct A // 移动构造 noexcept，可拷贝
    {
        A() = default;
        A(const A &) {};
        A(A &&) noexcept {};
    };

    struct B // 移动构造 非noexcept，可拷贝
    {
        B() = default;
        B(const B &) {};
        B(B &&) {};
    };

    struct C // 移动构造 非noexcept，不可拷贝
    {
        C() = default;
        C(const C &) = delete;
        C(C &&) {};
    };

    void test_static_assert()
    {
        static_assert(std::is_nothrow_move_constructible_v<A>);
        static_assert(!std::is_nothrow_move_constructible_v<B>);
        static_assert(!std::is_nothrow_move_constructible_v<C>);

        static_assert(std::is_same_v<decltype(std::move_if_noexcept(std::declval<A &>())), A &&>);
        static_assert(std::is_same_v<decltype(std::move_if_noexcept(std::declval<B &>())), const B &>);
        static_assert(std::is_same_v<decltype(std::move_if_noexcept(std::declval<C &>())), C &&>);

        static_assert(noexcept(A(std::declval<A &&>())));
        static_assert(!noexcept(B(std::declval<B &&>())));
    }
}

int main(int argc, char const *argv[])
{
    week_05::test_static_assert();
    return 0;
}
