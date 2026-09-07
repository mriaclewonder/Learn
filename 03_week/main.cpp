#include <cassert>
#include <cstddef>
#include <cstring>
#include <iostream>
#include <stdexcept>
#include <utility>

// 算术运算符： 成员函数 vs 非成员函数
namespace week_03
{
    class vec
    {
    public:
        vec(int val) : _val(val) {}
        int value() const { return _val; }

    private:
        int _val;
    };

    vec operator+(const vec &lhs, const vec &rhs)
    {
        return lhs.value() + rhs.value(); // 隐式转换
    }

    bool operator==(const vec &a, const vec &b)
    {
        return a.value() == b.value();
    }

    bool operator<(const vec &a, const vec &b)
    {
        return a.value() < b.value();
    }

    void test()
    {
        vec a(10);
        vec b = a + 1;
        vec c = 1 + a;

        assert(b == vec(11));
        assert(c == vec(11));
        assert(a < b);
    }

    class vec1
    {
    public:
        vec1(int val) : _val(val) {}
        int value() const { return _val; }

        vec1 operator+(const vec1 &rhs) const
        {
            return rhs.value() + _val; // 隐式转换
        }

    private:
        int _val;
    };

    void test1()
    {
        vec1 a(10);
        vec1 b = a + 1;
        // vec1 c = 1 + a; // 等价于 1.operator(b) error
    }

    class vec2
    {
    public:
        explicit vec2(int val) : _val(val) {}
        int value() const { return _val; }

        vec2 operator+(const vec2 &rhs) const
        {
            // return rhs.value() + _val; // 隐式转换
            return vec2(rhs.value() + _val); // 必须显示构造
        }

    private:
        int _val;
    };

    void test3()
    {
        vec2 a(10);
        vec2 b = a + vec2(1);
    }

    class String
    {
    public:
        static bool throwOnCopy;
        explicit String(const char *data = "") : _len(strlen(data)), _data(new char[_len + 1])
        {
            std::strcpy(_data, data);
        }

        String(const String &rhs) : _len(rhs._len), _data(new char[_len + 1])
        {
            if (throwOnCopy)
                throw std::runtime_error("copy failed");
            std::strcpy(_data, rhs._data);
        }

        ~String() { delete[] _data; }

        friend void swap(String &a, String &b) noexcept
        {
            std::swap(a._data, b._data);
            std::swap(a._len, b._len);
        }

        String &operator=(String rhs)
        {
            swap(*this, rhs);
            return *this;
        }

        const char *c_str() const { return _data; }

    private:
        std::size_t _len;
        char *_data;
    };

    bool String::throwOnCopy = false;

    void test4()
    {
        String a("hello");
        String b("world");
        a = b;
        assert(std::strcmp(a.c_str(), "world") == 0);
        std::cout << "[1] copy assign OK: a = " << a.c_str() << "\n";

        a = a;
        assert(std::strcmp(a.c_str(), "world") == 0);
        std::cout << "[2] self assign OK\n";

        String c("original");
        String d("replacement");
        String::throwOnCopy = true; // 注入异常

        try
        {
            c = d;
            assert(false);
        } // 若异常没抛，走到这里就断言失败
        catch (const std::runtime_error &)
        {
        } // 形参构造抛异常，被这里捕获
        String::throwOnCopy = false;
        assert(std::strcmp(c.c_str(), "original") == 0);
        std::cout << "[3] strong exception safety OK: c = " << c.c_str() << "\n";
    }
}

int main(int argc, char const *argv[])
{
    week_03::test();  // 测试非成员函数
    week_03::test1(); // 测试成员函数
    week_03::test3(); // 测试显示构造
    week_03::test4(); // 测试copy-and-swap
    return 0;
}
