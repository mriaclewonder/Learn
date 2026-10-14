#include <iostream>

#include <utility>

namespace week_05
{
    void target(int &)
    {
        std::cout << "left value &\n";
    }

    void target(int &&)
    {
        std::cout << "right value &&\n";
    }

    template <class T>
    void wrapper_no_forward(T &&x)
    {
        target(x);
    }

    void test_no_forward()
    {
        wrapper_no_forward(4);
    }

    template <class T>
    void wrapper_forward(T &&x)
    {
        target(std::forward<T>(x));
    }

    void test_forward()
    {
        wrapper_forward(4);
    }

    void test_no_forward_left()
    {
        int x = 4;
        wrapper_no_forward(x);
    }

    void test_forward_left()
    {
        int x = 4;
        wrapper_forward(x);
    }
}

int main(int argc, char const *argv[])
{
    week_05::test_no_forward();
    week_05::test_forward();

    week_05::test_no_forward_left();
    week_05::test_forward_left();
    return 0;
}
