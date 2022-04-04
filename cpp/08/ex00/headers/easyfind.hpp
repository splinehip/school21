/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 14:05:39 by cflorind          #+#    #+#             */
/*   Updated: 2022/04/04 12:31:52 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_H
# define EASYFIND_H
# include <algorithm>

template< template<typename, typename> class T>
int	easyfind(T<int, std::allocator<int> > &arr, int i);

# include "easyfind.tpp"
#endif
