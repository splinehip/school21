/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:21:18 by cflorind          #+#    #+#             */
/*   Updated: 2022/06/02 15:28:14 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"

template<typename T, typename Allocator>
ft::vector<T, Allocator>::vector(const size_type n, const value_type &val)
    : arr(NULL), len(n), cap(n), alloc(allocator_type())
{
    arr = alloc.allocate(cap);
    for(size_t i = 0; i < len; i++)
        alloc.construct(&arr[i], val);
}

template<typename T, typename Allocator>
ft::vector<T, Allocator>    &ft::vector<T, Allocator>::operator=(
    const vector &inst)
{
    if (this == &inst)
        return (*this);
    len = inst.len;
    cap = inst.cap;
    if (cap)
    {
        arr = alloc.allocate(cap);
        for (size_t i = 0; i < len; i++)
        {
            alloc.construct(&arr[i], inst.arr[i]);
        }
    }
    else
    {
        arr = NULL;
    }
    return (*this);
}

//Utils:
template<typename T, typename Allocator>
void    ft::vector<T, Allocator>::realloc(
    typename ft::vector<T, Allocator>::size_type newcap)
{
    ft::vector<T, Allocator>::value_type    *tmp;

    tmp = alloc.allocate(newcap);
    for (size_t i = 0; i < len; i++)
    {
        if (i < newcap)
            alloc.construct(&tmp[i], arr[i]);
        alloc.destroy(&arr[i]);
    }
    alloc.deallocate(arr, cap);
    cap = newcap;
    if (len > cap)
        len = cap;
    arr = tmp;
}

template<typename T, typename Allocator>
void    ft::vector<T, Allocator>::destroy(void)
{
    for(size_t i = 0; i < len; i++)
        alloc.destroy(&arr[i]);
    len = 0;
}

//Capacity:
template<typename T, typename Allocator>
    void    ft::vector<T, Allocator>::resize(
        typename ft::vector<T, Allocator>::size_type n,
        typename ft::vector<T, Allocator>::value_type val)
{
    if (n == len)
        return ;
    else if (n < len)
    {
        while (len != n)
            pop_back();
    }
    else
    {
        while (len != n)
            push_back(val);
    }
}

template<typename T, typename Allocator>
void    ft::vector<T, Allocator>::reserve(ft::vector<T, Allocator>::size_type n)
{
    if (n <= cap)
        return ;
    realloc(n);
}

template<typename T, typename Allocator>
void    ft::vector<T, Allocator>::shrink_to_fit(void)
{
    if (len == cap)
        return ;
    realloc(len);
}

//Modifiers:
template<typename T, typename Allocator>
template <class InputIterator>
void    ft::vector<T, Allocator>::assign(
    InputIterator first, InputIterator last)
{
    destroy();
    while (first != last)
        push_back(*first++);
}

template<typename T, typename Allocator>
void    ft::vector<T, Allocator>::assign(
    ft::vector<T, Allocator>::size_type n,
    const ft::vector<T, Allocator>::value_type &val)
{
    destroy();
    while (len != n)
        push_back(val);
}

template<typename T, typename Allocator>
void    ft::vector<T, Allocator>::push_back(
    const ft::vector<T, Allocator>::value_type &value)
{
    if (arr)
    {
        if (len == cap)
            realloc(cap * 2);
    }
    else
    {
        cap = 2;
        arr = alloc.allocate(cap);
    }
    alloc.construct(&arr[len++], value);
}

template<typename T, typename Allocator>
void    ft::vector<T, Allocator>::clear()
{
    destroy();
    alloc.deallocate(arr, cap);
    cap = 0;
    arr = NULL;
}


