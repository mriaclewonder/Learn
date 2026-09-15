#include <iostream>
#include <memory>

namespace test
{
    class A
    {
    public:
        A(int val) : _a(val) {}

        int a() const { return _a; }

    private:
        int _a;
    };

    class B
    {
        int v;
    };

    void test1()
    {
        std::unique_ptr<A> ptr_a = std::make_unique<A>(1);
        std::cout << "a " << ptr_a->a() << std::endl;

        // std::unique_ptr<A> r = ptr_a; 赋值 =delete
        // std::unique_ptr<A> r(ptr_a); 拷贝构造 =delete

        std::unique_ptr<A> r = std::move(ptr_a);
        std::cout << "r a " << r->a() << std::endl;

        // std::cout << "ptr_a a " << ptr_a->a() << std::endl;

        std::cout << "sizeof ptr_a " << sizeof(ptr_a) << std::endl;

        std::unique_ptr<B> p(new B[10]);    // 默认是delete
        std::unique_ptr<B[]> p1(new B[10]); // 默认是delete[]
    }

    void test2()
    {
        // 函数对象
        struct FileCloser
        {
            void operator()(std::FILE *f) const noexcept
            {
                if (f)
                    std::fclose(f);
            }
        };
        std::unique_ptr<std::FILE, FileCloser> a1(std::fopen("a.txt", "r"));

        // lamada表达式
        int a = 10;
        auto del = [a](std::FILE *f) noexcept
        {if(f) std::fclose(f); };
        std::unique_ptr<std::FILE, decltype(del)> a2(std::fopen("a.txt", "r"), del);

        // 函数指针
        std::unique_ptr<std::FILE, int (*)(std::FILE *)> a3(std::fopen("a.txt", "r"), std::fclose);

        std::cout << "sizeof a1 " << sizeof(a1) << std::endl; // 8
        std::cout << "sizeof a2 " << sizeof(a2) << std::endl; // 16 8 + 捕获内容
        std::cout << "sizeof a3 " << sizeof(a3) << std::endl; // 16
    }
}

int main(int argc, char const *argv[])
{
    test::test1(); // 测试独占权
    test::test2(); // 测试unique_ptr自定义deleter
    return 0;
}
