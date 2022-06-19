/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:52:16 by cflorind          #+#    #+#             */
/*   Updated: 2022/06/16 14:59:46 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack>
#include <deque>

namespace ft
{
    template<typename T, typename Sequence = std::deque<T> >
    class stack: public std::stack<T, Sequence>{};

}
