#ifndef _JJALLOC_H
#define _JJALLOC_H

#include <new>
#include <iostream>
#include <climits> // UINT_MAX

namespace JJ
{
    template <class T>
    inline T *_allocate(ptrdiff_t size, T *)
    {
        std::set_new_handler(0);
        T *tmp = static_cast<T *>(::operator new((std::size_t)(size * sizeof(T))));
        if (tmp == nullptr)
        {
            std::cerr << "out of memory" << std::endl;
            exit(1);
        }
        return tmp;
    }

    template <class T>
    inline void _deallocate(T *buffer)
    {
        ::operator delete(buffer);
    }

    template <class T1, class T2>
    inline void _construct(T1 *p, const T2 &value)
    {
        new (p) T1(value); // placement new
    }

    template <class T>
    inline void _destroy(T *ptr)
    {
        ptr->~T();
    }

    template <class T>
    class allocator
    {
    public:
        typedef T value_type;
        typedef T *pointer;
        typedef const T *const_pointer;
        typedef T &reference;
        typedef const T &const_reference;
        typedef std::size_t size_type;
        typedef std::ptrdiff_t difference_type;

        // rebind allocator of type U
        template <class U>
        struct rebind
        {
            typedef allocator<U> other;
        };

        allocator() = default; // 用户声明了下面的转换构造后，隐式默认构造被抑制，必须显式恢复

        template <class U>
        allocator(const allocator<U> &) {}

        pointer allocate(size_type size, const void *hint = 0)
        {
            return _allocate((difference_type)size, (pointer)hint);
        }

        void deallocate(pointer p, size_type n)
        {
            _deallocate(p);
        }

        void construct(pointer p, const_reference value)
        {
            _construct(p, value);
        }

        void destroy(pointer p)
        {
            _destroy(p);
        }

        pointer address(reference x)
        {
            return (pointer)&x;
        }

        const_pointer address(const_reference x)
        {
            return (const_pointer)&x;
        }

        size_type max_size() const
        {
            return (size_type)(UINT_MAX / sizeof(T)); // element number
        }
    };
}

#endif // _JJALLOC_H