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

    void test3()
    {
        std::shared_ptr<int> p = std::make_shared<int>(42);
        std::cout << "p count " << p.use_count() << std::endl; // 1

        auto q = p;                                            // +1
        std::cout << "p count " << p.use_count() << std::endl; // 2

        q.reset();                                             // -1
        std::cout << "p count " << p.use_count() << std::endl; // 1
    }

    void test4()
    {
        std::shared_ptr<int> p = std::make_shared<int>(42);
        std::cout << "p size " << sizeof(p) << std::endl;
    }

    void test5()
    {
        std::shared_ptr<int> a = std::make_shared<int>(10);
        std::shared_ptr<int> b = a;

        int *raw = new int[4];
        std::shared_ptr<int> p(raw);
        std::shared_ptr<int> q(raw); // 生成两个独立控制块，各加一
    } // 双重释放

    struct Node
    {
        std::shared_ptr<Node> next;
        std::shared_ptr<Node> prev;
        ~Node() { std::cout << "~Node\n"; }
    };

    void test6()
    {
        auto a = std::make_shared<Node>();
        auto b = std::make_shared<Node>();
        a->next = b;
        b->prev = a;
        std::cout << "a count " << a.use_count() << std::endl; // 2
        std::cout << "b count " << b.use_count() << std::endl; // 2
    } // a、b 各 -1 → 强计数都剩 1，谁都不归零 → 两个 Node 都不析构 → 泄漏

    struct Node1
    {
        std::shared_ptr<Node1> next;
        std::weak_ptr<Node1> prev;
        ~Node1() { printf("~Node1\n"); }
    };

    void test7()
    {
        auto a = std::make_shared<Node1>();
        auto b = std::make_shared<Node1>();
        a->next = b;
        b->prev = a;
        std::cout << "a count " << a.use_count() << std::endl; // 1
        std::cout << "b count " << b.use_count() << std::endl; // 2
    }

    void test8()
    {
        std::weak_ptr<Node1> w;
        {
            auto v = std::make_shared<Node1>();
            w = v;
            std::cout << "expired " << w.expired() << " use_count " << w.use_count() << "\n";
            if (auto c = w.lock())
            {
            }
        }
        std::cout << "expired " << w.expired() << " use_count " << w.use_count() << "\n";
        auto c = w.lock(); // 可将weak_ptr提升shared_ptr
        if (!c)
        {
            std::cout << "object gone\n";
        }

        //  强计数 == 0	对象析构（调用 deleter）
        // 强计数 == 0 且 弱计数 == 0	控制块释放
    }

    class Foo
    {
        ~Foo() { std::cout << "~Foo\n"; }

    public:
        std::shared_ptr<Foo> bad() { return std::shared_ptr<Foo>(); } // 导致双重释放
    };

    // crtp 奇异递归模板
    struct Foo1 : public std::enable_shared_from_this<Foo1>
    {
    public:
        int x = 1.0;
        std::shared_ptr<Foo1> bad() { return shared_from_this(); }
    };

    void test9()
    {
        std::shared_ptr<Foo1> f = std::make_shared<Foo1>();
        std::cout << "f use_count " << f.use_count() << "\n";

        auto a = f->bad();
        std::cout << "f use_count " << f.use_count() << "\n";

        // 别名构造函数
        // b 拥有整个 Foo1，但指向 f->x
        std::shared_ptr<int> b(f, &f->x);
        std::cout << "f use_count " << f.use_count() << "\n";

        try
        {
            // 调用时该对象必须已被某个 shared_ptr 持有，否则抛 std::bad_weak_ptr
            Foo1 ob;
            ob.bad();
        }
        catch (const std::bad_weak_ptr &e)
        {
            std::printf("bad_weak_ptr: %s\n", e.what());
        }
    }
}

int main(int argc, char const *argv[])
{
    // test::test1(); // 测试独占权
    // test::test2(); // 测试unique_ptr自定义deleter
    // test::test3(); // 测试引用计数
    // test::test4(); // 测试shared_ptr大小
    // test::test6(); // 测试循环引用
    // test::test7(); // 测试weak_ptr
    // test::test8(); // 测试api
    // test::test9(); // 测试enable_shared_from_this
    return 0;
}
