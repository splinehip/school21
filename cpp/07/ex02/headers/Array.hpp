/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 14:05:39 by cflorind          #+#    #+#             */
/*   Updated: 2022/04/03 19:02:09 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H
# include <stdexcept>

template<typename T>
class Array
{
private:
	unsigned int	arr_size;
	T				*arr;
public:
	Array<T>(void);
	Array<T>(unsigned int size);
	Array<T>(Array<T> const &inst);
	~Array<T>(void);

	Array<T>			&operator=(Array<T> const &inst);
	T					&operator[](unsigned int i);
	const unsigned int	&size(void) const;

};

#include "Array.tpp"
#endif
