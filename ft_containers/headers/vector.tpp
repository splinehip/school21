/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:21:18 by cflorind          #+#    #+#             */
/*   Updated: 2022/06/14 17:55:13 by cflorind         ###   ########.fr       */
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

//Element acsses:
template<typename T, typename Allocator>
typename ft::vector<T, Allocator>::reference
    ft::vector<T, Allocator>::at(const size_type n)
{
    if (n < len)
        return arr[n];
    char err[128];
    snprintf(err, 128, OOR_MSG.c_str(), n, len);
    throw std::out_of_range(err);
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
    const size_type n, const value_type val)
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

//Modifiers:
template<typename T, typename Allocator>
template <typename InputIterator>
typename ft::IsBiDirIter<InputIterator>::type
ft::vector<T, Allocator>::assign(InputIterator first, InputIterator last)
{
    destroy();
    while (first != last)
        push_back(*first++);
}

template<typename T, typename Allocator>
void    ft::vector<T, Allocator>::assign(
    const size_type n, const value_type &val)
{
    destroy();
    while (len != n)
        push_back(val);
}

template<typename T, typename Allocator>
void    ft::vector<T, Allocator>::push_back(const value_type &value)
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

template<typename T, typename Allocator>
void    ft::vector<T, Allocator>::swap(vector<T, Allocator> &x)
{
    if (this == &x)
        return ;

    value_type  *xarr = x.arr;
    size_type   xlen = x.len;
    size_type   xcap = x.cap;

    x.arr = arr;
    x.len = len;
    x.cap = cap;

    arr = xarr;
    len = xlen;
    cap = xcap;
}

//Compaire operators:
template<typename T, typename Allocator>
bool    ft::operator==(
    const vector<T, Allocator> f, const vector<T, Allocator> s)
{
    if (f.size() != s.size())
        return false;
    size_t i = 0;
    while (i < f.size())
    {
        if (f[i] != s[i])
            return false;
        i++;
    }
    return true;
}

template<typename T, typename Allocator>
bool    ft::operator!=(
    const vector<T, Allocator> f, const vector<T, Allocator> s)
{
    return !(f == s);
}

template<typename T, typename Allocator>
bool    ft::operator<(
    const vector<T, Allocator> f, const vector<T, Allocator> s)
{
    return ft::lexicographical_compare(f.begin(), f.end(), s.begin(), s.end());
}

template<typename T, typename Allocator>
bool    ft::operator<=(
    const vector<T, Allocator> f, const vector<T, Allocator> s)
{
    return !(s < f);
}

template<typename T, typename Allocator>
bool    ft::operator>(
    const vector<T, Allocator> f, const vector<T, Allocator> s)
{
    return s < f;
}

template<typename T, typename Allocator>
bool    ft::operator>=(
    const vector<T, Allocator> f, const vector<T, Allocator> s)
{
    return !(s > f);
}

template<typename T, typename Allocator>
template<bool IsConst>
struct ft::vector<T, Allocator>::common_iterator
    : public iterator_base<std::random_access_iterator_tag,
            typename conditional<IsConst, value_type, const value_type>::type>
{
typedef typename common_iterator::iterator_base::difference_type    diff_type;

typedef typename conditional_t<IsConst, diff_type,
    const diff_type>::type  diff_t;

typedef typename conditional_t<IsConst, value_type,
    const value_type>::type value_t;

typedef typename conditional_t<IsConst, iterator,
    const_iterator>::type   iter_t;

private:
    value_t  *item;

public:
    common_iterator(void){item = NULL;}
    common_iterator(value_t *_item){item = _item;}
    common_iterator(const iter_t &inst){*this = inst;}
    ~common_iterator(void){}

    iter_t    &operator=(const iterator &inst)
    {
        if (item == inst.base())
            return *this;
        item = inst.base();
        return *this;
    }

    iter_t  operator+(diff_t n) const {return iter_t(item + n);}
    iter_t  operator-(diff_t n) const {return iter_t(item - n);}
    diff_t  operator-(iter_t &rhs) const {return item - rhs.item;}

    iter_t  &operator+=(diff_t n){item += n; return *this;}
    iter_t  &operator-=(diff_t n) {item -= n; return *this;}

    iter_t  &operator++(void){++item; return *this;}
    iter_t  operator++(int){return iterator(item++);}
    iter_t  &operator--(void){--item; return *this;}
    iter_t  operator--(int){return iterator(item--);}

    value_t &operator*(void) const {return *item;}
    value_t *operator->(void) const {return item;}
    value_t &operator[](diff_t n) const {return item[n];}
    value_t *base(void) const {return item;}

};
