/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:21:18 by cflorind          #+#    #+#             */
/*   Updated: 2022/06/01 21:13:28 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"

template<typename T, typename Allocator>
ft::vector<T, Allocator>    &ft::vector<T, Allocator>::operator=(const vector &inst)
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

//Capacity:

//Modifiers:
template<typename T, typename Allocator>
void    ft::vector<T, Allocator>::push_back(const T &value)
{
    T *tmp;

    if (arr)
    {
        if (len == cap)
        {
            tmp = alloc.allocate(cap * 2);
            for (size_t i = 0; i < len; i++)
            {
                alloc.construct(&tmp[i], arr[i]);
            }
            clear();
            cap *= 2;
            arr = tmp;
        }
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
    for (size_t i = 0; i < len; i++)
        alloc.destroy(&arr[i]);
    alloc.deallocate(arr, cap);
}
