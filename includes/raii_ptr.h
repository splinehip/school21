#pragma once

#include <cstddef>

#include <memory>

template <typename T>
class raii_ptr
{
public:
    typedef T* pointer;
    typedef T value_type;
    typedef T& reference;

private:
    pointer data;

public:
    raii_ptr()
        : data(NULL)
    {}

    explicit raii_ptr(pointer p)
        : data(p)
    {}

    ~raii_ptr()
    {
        delete data;
    }

    raii_ptr(const raii_ptr& other)
        : data(new T)
    {
        *data = *other.data;
    }

    raii_ptr& operator=(const raii_ptr& other)
    {
        data = new T;
        *data = *other.data;
    }

    reference operator*() const
    {
        return *data;
    }

    pointer operator->() const
    {
        return data;
    }

    explicit operator bool() const
    {
        return data != NULL;
    }
};

template <typename T>
raii_ptr<T> make_default_ptr()
{
    return raii_ptr<T>();
}
