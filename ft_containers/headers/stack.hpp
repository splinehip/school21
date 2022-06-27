/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:52:16 by cflorind          #+#    #+#             */
/*   Updated: 2022/06/27 16:59:51 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "vector.hpp"

namespace ft
{
template<typename T, typename Container = ft::vector<T> >
class stack
{
public:
typedef T                               value_type;
typedef Container                       container_type;
typedef typename Container::size_type   size_type;

protected:
    Container   c;

public:
    stack(const container_type &cnt = container_type()): c(cnt){};
    stack(const stack &inst){*this = inst;}
    ~stack(void){}

    stack   &operator=(const stack &inst)
    {
        if (this == &inst)
            return *this;
        c = inst.c;
        return (*this);
    }

    bool                empty(void) const {return c.empty();}
    size_type           size(void) const {return c.size();}
    value_type          &top(void){return c.back();}
    const value_type    &top(void) const {return c.back();}
    void                push(const value_type& val){c.push_back(val);}
    void                pop(void){c.pop_back();}

    void    swap(stack &x){c.swap(x.c);}

    friend bool operator==(
        const stack<T, Container> &lhs, const stack<T, Container> &rhs)
    {
        return static_cast<container_type>(lhs.c)
                == static_cast<container_type>(rhs.c);
    }

    friend bool operator!=(
        const stack<T, Container> &lhs, const stack<T, Container> &rhs)
    {
        return static_cast<container_type>(lhs.c)
                != static_cast<container_type>(rhs.c);
    }

    friend bool operator<(
        const stack<T, Container> &lhs, const stack<T, Container> &rhs)
    {
        return static_cast<container_type>(lhs.c)
                < static_cast<container_type>(rhs.c);
    }

    friend bool operator<=(
        const stack<T, Container> &lhs, const stack<T, Container> &rhs)
    {
        return static_cast<container_type>(lhs.c)
                <= static_cast<container_type>(rhs.c);
    }

    friend bool operator>(
        const stack<T, Container> &lhs, const stack<T, Container> &rhs)
    {
        return static_cast<container_type>(lhs.c)
                > static_cast<container_type>(rhs.c);
    }

    friend bool operator>=(
        const stack<T, Container> &lhs, const stack<T, Container> &rhs)
    {
        return static_cast<container_type>(lhs.c)
                >= static_cast<container_type>(rhs.c);
    }
};

template<typename T, typename Container>
void    swap(stack<T, Container> &x, stack<T, Container> &y){x.swap(y);}

}
