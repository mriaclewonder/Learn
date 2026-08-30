#include <iostream>

namespace week_02
{
    class Base
    {
    public:
        explicit Base(int count) : _count(count) { std::cout << "Base constrator ...\n"; }
        virtual ~Base() { std::cout << "Base destroy ...\n"; }
        virtual void test() const { std::cout << "Base test ...\n"; }

        int count() const { return _count; }

    private:
        int _count = 0;
    };

    class Derived : public Base
    {
    public:
        explicit Derived(int count) : Base(count) { std::cout << "Derived constrator ...\n"; }
        ~Derived() { std::cout << "Derived destroy ...\n"; }
        void test() const override { std::cout << "Derived test ...\n"; }
    };

    class Derived_01 : public Base
    {
    public:
        Derived_01(int count) : Base(count) { std::cout << "Derived_01 constrator ...\n"; }
        ~Derived_01() { std::cout << "Derived_01 destroy ...\n"; }
        void test() const override { std::cout << "Derived_01 test ...\n"; }
    };

    void test01()
    {
        // 编译期指定，不检查
        double i = 3.7;
        int a = static_cast<double>(i);
        std::cout << "test01 a " << a << "\n";

        // void* -> T*
        Derived der(1);
        void *vp = &der;
        Derived *vp2 = static_cast<Derived *>(vp);
        std::cout << "test01 vp2 " << (*vp2).count() << "\n";

        // 继承 向上安全，向下不检查（靠你自己保证）
        Base *bp = static_cast<Base *>(&der);     // 向上
        Derived *dp = static_cast<Derived *>(bp); // 向下，编译期直接定
    }

    void test02()
    {
        // 运行期，查 vtable 验证真实类型
        Base *base = new Derived_01(1);
        Derived_01 *ok = dynamic_cast<Derived_01 *>(base); // 成功
        // Derived *bad = dynamic_cast<Base*>(base); // error
    }

    void test03()
    {
        // 去 const，安全边界 const_cast 去掉的是"访问通道上的 const"，不是"对象本身的 const"
        int n = 10;
        const int &cr = n;
        const_cast<int &>(cr) = 20; // 安全：n 本身非 const

        std::cout << "test03 n " << n << "\n";

        const int c = 5;
        int &rc = const_cast<int &>(c); // 不安全（UB），注释说明不执行修改
        rc = 20;
        std::cout << "test03 rc " << rc << "\n";
    }

    void test04()
    {
        struct Packet
        {
            int len;
            char buf[8];
        };

        Packet pkt{66, "abcdef"};
        char *bytes = reinterpret_cast<char *>(&pkt);       // 按字节看内存（看字节序） 把&pkt当作char*来看
        uintptr_t addr = reinterpret_cast<uintptr_t>(&pkt); // 指针 <-> 整数

        std::cout << "test04 bytes " << *bytes << "\n"; // B

        {
            Packet *pkt1 = new Packet{66, "abcdef"};

            char *bytes1 = reinterpret_cast<char *>(pkt1);

            std::cout << "test04 new Packet bytes " << *bytes1 << "\n"; // 66 0 0 0 97 98 99 100 101 102 0 0
            delete pkt1;
        }

        std::cout << "test04 addr " << addr << "\n";

        const char *buf = "123";
        std::cout << "test04 buf " << buf << "\n";
    }

    void test05(const Base &b)
    {
        b.test();
    }

    void test06(const Derived &d)
    {
        d.test();
    }

    void test07(const Derived_01 &d_01)
    {
        d_01.test();
    }
}

int main(int argc, char const *argv[])
{
    // week_02::test01(); // static_cast
    // week_02::test02(); // dynamic_cast
    // week_02::test03(); // const_cast

    week_02::test04(); // reinterpret_cast

    // explicit
    // week_02::test05(10);
    // week_02::test06(10); // error
    // week_02::test07(10); // 构造函数没加explicit

    return 0;
}