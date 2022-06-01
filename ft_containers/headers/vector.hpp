/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 12:49:25 by cflorind          #+#    #+#             */
/*   Updated: 2022/06/01 21:30:28 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <cstddef>
#include <memory>

namespace ft
{
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

public:
    vector(void): arr(NULL), len(0), cap(0), alloc(allocator_type()){}
    vector(const vector &inst){*this = inst;}
    ~vector(void){clear();}

    vector          &operator=(const vector &inst);
    reference       operator[](const size_t i){return arr[i];}
    const_reference operator[](const size_t i) const {return arr[i];}

    //Capacity:
    size_type   size(void) const {return len;}
    size_type   max_size(void) const {return alloc.max_size();}
    //resize Change size (public member function )
    size_type   capacity(void) const {return cap;}
    bool        empty(void) const {return len == false;}
    //reserve Request a change in capacity (public member function )
    //shrink_to_fit Shrink to fit (public member function )

    //Modifiers:
    //assign Assign vector content (public member function )
    void    push_back(const T &value);

    //pop_back Delete last element (public member function )
    //insert Insert elements (public member function )
    //erase Erase elements (public member function )
    //swap Swap content (public member function )
    void    clear(void);

    //emplace Construct and insert element (public member function )
    //emplace_back Construct and insert element at the end (public member function )
};

#include "vector.tpp"
}
