/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 15:01:27 by cflorind          #+#    #+#             */
/*   Updated: 2022/06/28 12:03:50 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft
{
template<typename T1, typename T2>
struct pair
{
typedef T1  first_type;
typedef T2  second_type;

    first_type  first;
    second_type second;

    pair(void): first(), second(){};

    template<typename U, typename V>
    pair(const pair<U, V> &pr): first(pr.first), second(pr.second){}

    pair(const first_type &a, const second_type &b): first(a), second(b){}

    ~pair(void){}

    pair&   operator=(const pair &pr)
    {
        if (this == &pr)
            return *this;
        first = pr.first;
        second = pr.second;
        return *this;
    }

};

template<typename T1, typename T2>
ft::pair<T1, T2>    make_pair(const T1 f, const T2 s)
{
    return ft::pair<T1, T2>(f, s);
}

template <class T1, class T2>
bool operator==(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
{
    return (lhs.first == rhs.first && lhs.second == rhs.second);
}

template <class T1, class T2>
bool operator!=(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
{
    return !(lhs == rhs);
}

template <class T1, class T2>
bool operator<(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
{
    return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
}

template <class T1, class T2>
bool operator<=(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
{
    return !(rhs < lhs);
}

template <class T1, class T2>
bool operator>(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
{
    return (rhs < lhs);
}

template <class T1, class T2>
bool operator>=(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
{
    return !(lhs < rhs);
}

}
