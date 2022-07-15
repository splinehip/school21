/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 12:49:25 by cflorind          #+#    #+#             */
/*   Updated: 2022/07/15 12:46:17 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <cstddef>
#include <memory>
#include <stdexcept>
#include <cstdio>

#include "utils.hpp"
#include "iterators.hpp"

namespace ft
{
const std::string OOR_MSG =
    "vector::at: n (which is %lu) >= this->size() (which is %lu)";

template<typename T, typename Allocator = std::allocator<T> >
class vector
{
template<bool IsConst>
struct common_iterator;

public:
typedef T                                           value_type;
typedef Allocator                                   allocator_type;
typedef typename allocator_type::reference          reference;
typedef typename allocator_type::const_reference    const_reference;
typedef typename allocator_type::pointer            pointer;
typedef typename allocator_type::const_pointer      const_pointer;
typedef typename allocator_type::size_type          size_type;

typedef vector::common_iterator<NotConst>           iterator;
typedef vector::common_iterator<Const>              const_iterator;
typedef common_reverse_iterator<iterator>           reverse_iterator;
typedef common_reverse_iterator<const_iterator>     const_reverse_iterator;


private:
    value_type     *arr;
    size_type       len;
    size_type       cap;
    allocator_type  alloc;

private:
    //Utils:
    void    uptocap(size_type newcap);
    void    destroy(void);

public:
    vector(const allocator_type &_alloc = allocator_type())
        : arr(NULL), len(0), cap(0), alloc(_alloc){}

    vector(const size_type n, const value_type &val = value_type(),
            const allocator_type &_alloc = allocator_type());

    template <class InputIterator>
    vector(InputIterator first, typename IsInputIter<InputIterator>::type last,
            const allocator_type &_alloc = allocator_type())
            : arr(NULL), len(0), cap(0), alloc(_alloc){assign(first, last);}

    vector(const vector &inst)
        : arr(NULL), len(0), cap(0), alloc(allocator_type()){*this = inst;}

    ~vector(void){clear();}

    vector  &operator=(const vector &inst);

    //Iterators:
    iterator                begin(void);
    const_iterator          begin(void) const;
    iterator                end(void);
    const_iterator          end(void) const;
    reverse_iterator        rbegin(void);
    const_reverse_iterator  rbegin(void) const;
    reverse_iterator        rend(void);
    const_reverse_iterator  rend(void) const;
    const_iterator          cbegin(void) const;
    const_iterator          cend(void) const;
    const_reverse_iterator  crbegin(void) const;
    const_reverse_iterator  crend(void) const;

    //Element access:
    reference       operator[](const size_type i) {return arr[i];}
    const_reference operator[](const size_type i) const {return arr[i];}
    reference       at(const size_type n);
    const_reference at(const size_type n) const;
    reference       front(void){return *arr;}
    const_reference front(void) const {return *arr;}
    reference       back(void){return arr[len - 1];}
    const_reference back(void) const {return arr[len - 1];}

    //Capacity:
    size_type   size(void) const {return len;}
    size_type   max_size(void) const {return alloc.max_size();}
    void        resize(const size_type n, const value_type val = value_type());
    size_type   capacity(void) const {return cap;}
    bool        empty(void) const {return len == false;}
    void        reserve(const size_type n){if (n <= cap) return; uptocap(n);}
    void        shrink_to_fit(void){if (len == cap) return; uptocap(len);}

    //Modifiers:
    template <typename InputIterator>
    typename IsInputIter<InputIterator, ft::setVoid>::type
    assign(InputIterator first, InputIterator last);

    void        assign(const size_type n, const value_type &val);
    void        push_back(const value_type &value);
    void        pop_back(void){if (len) alloc.destroy(&arr[--len]);}

    iterator    insert(iterator position, const value_type &val);

    void        insert(iterator position, size_t n, const value_type &val);

    template <typename InputIterator>
    void        insert(iterator position, InputIterator first,
                    typename IsInputIter<InputIterator>::type last);

    template <typename InputIterator>
    typename IsInputIter<InputIterator>::type
    erase(InputIterator position);

    template <typename InputIterator>
    typename IsInputIter<InputIterator>::type
    erase(InputIterator first, InputIterator last);

    allocator_type  get_allocator(void) const {return alloc;}

    void    swap(vector &x);
    void    clear(void);

};

//Compaire operators:
template<typename T, typename Allocator>
bool    operator==(const vector<T, Allocator> &f, const vector<T, Allocator> &s)
{
    return equal(f.begin(), f.end(), s.begin(), s.end());
}

template<typename T, typename Allocator>
bool    operator!=(const vector<T, Allocator> &f, const vector<T, Allocator> &s)
{
    return !(f == s);
}

template<typename T, typename Allocator>
bool    operator<(const vector<T, Allocator> &f, const vector<T, Allocator> &s)
{
    return ft::lexicographical_compare(f.begin(), f.end(), s.begin(), s.end());
}

template<typename T, typename Allocator>
bool    operator<=(const vector<T, Allocator> &f, const vector<T, Allocator> &s)
{
    return (f < s) || (f == s);
}

template<typename T, typename Allocator>
bool    operator>(const vector<T, Allocator> &f, const vector<T, Allocator> &s)
{
    return !(f < s) && (f != s);
}

template<typename T, typename Allocator>
bool    operator>=(const vector<T, Allocator> &f, const vector<T, Allocator> &s)
{
    return (f > s) || (f == s);
}

//std::swap:
template<typename T, typename Allocator>
void    swap(vector<T, Allocator> &f, vector<T, Allocator> &s){f.swap(s);}

#include "vector.tpp"
}
