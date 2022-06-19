/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 15:01:27 by cflorind          #+#    #+#             */
/*   Updated: 2022/06/16 15:20:28 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utility>

namespace ft
{
    template<class T1, class T2>
    struct pair: public std::pair<T1, T2>
    {
    };

    template<class T1, class T2>
    pair<T1, T2>    make_pair(const T1 &f, const T2 &s)
    {pair<T1, T2> res;
    res.first = f;
    res.second = s;
     return res;}
}
