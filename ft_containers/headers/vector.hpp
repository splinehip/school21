/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 12:49:25 by cflorind          #+#    #+#             */
/*   Updated: 2022/06/02 18:18:03 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <cstddef>
#include <memory>
#include <stdexcept>

namespace ft
{
const std::string OOR_MSG =
    "vector::at: n (which is %lu) >= this->size() (which is %lu)";

template<typename T, typename Allocator = std::allocator<T> >
class vector
{
typedef T                                           value_type;
typedef Allocator                                   allocator_type;
typedef typename allocator_type::reference          reference;
typedef typename allocator_type::const_reference    const_reference;
typedef typename allocator_type::pointer            pointer;
typedef typename allocator_type::const_pointer      const_pointer;
typedef typename allocator_type::size_type          size_type;

private:
    value_type     *arr;
    size_type       len;
    size_type       cap;
    allocator_type  alloc;

private:
    void    realloc(size_type newcap);
    void    destroy(void);

public:
    vector(void): arr(NULL), len(0), cap(0), alloc(allocator_type()){}
    vector(const size_type n, const value_type &val);
    vector(const vector &inst){*this = inst;}
    ~vector(void){clear();}

    vector          &operator=(const vector &inst);

    //Element access:
    reference       operator[](const size_type i){return arr[i];}
    const_reference operator[](const size_type i) const {return arr[i];}

    reference       at(size_type n){if (n < len) return arr[n];
                        char err[128];
                        snprintf(err, 128, OOR_MSG.c_str(), n, len);
                        throw std::out_of_range(err);}

    const_reference at(size_type n) const {if (n < len) return arr[n];
                        char err[128];
                        snprintf(err, 128, OOR_MSG.c_str(), n, len);
                        throw std::out_of_range(err);}

    reference       front(void){return arr;}
    const_reference front(void) const {return arr;}
    reference       back(void){return arr[len - 1];}
    const_reference back(void) const {return arr[len - 1];}

    //Capacity:
    size_type   size(void) const {return len;}
    size_type   max_size(void) const {return alloc.max_size();}
    void        resize(size_type n, value_type val = value_type());
    size_type   capacity(void) const {return cap;}
    bool        empty(void) const {return len == false;}
    void        reserve(size_type n);
    void        shrink_to_fit(void);

    //Modifiers:
    template <class InputIterator>
    void    assign(InputIterator first, InputIterator last);
    void    assign(size_type n, const value_type &val);
    void    push_back(const value_type &value);
    void    pop_back(void){if (len) alloc.destroy(&arr[--len]);}
    //insert Insert elements (public member function )
    //erase Erase elements (public member function )

    void    swap(vector& x){if (this == &x) return ;
                value_type  *xarr = x.arr; size_type   xlen = x.len;
                size_type   xcap = x.cap; x.arr = arr; x.len = len; x.cap = cap;
                arr = xarr; len = xlen; cap = xcap;}

    void    clear(void);
};

#include "vector.tpp"
}
