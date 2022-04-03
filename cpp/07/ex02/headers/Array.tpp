/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 18:05:30 by cflorind          #+#    #+#             */
/*   Updated: 2022/04/03 19:21:03 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template<typename T>
Array<T>::Array(void): arr_size(0), arr(NULL){}

template<typename T>
Array<T>::Array(unsigned int size): arr_size(size), arr(new T[size]()){}

template<typename T>
Array<T>::Array(Array<T> const &inst)
{
	*this = inst;
}

template<typename T>
Array<T>::~Array()
{
	delete[] this->arr;
}

template<typename T>
Array<T>			&Array<T>::operator=(Array<T> const &inst)
{
	unsigned int	i;

	this->arr = new T[inst.size()]();
	if (this->arr)
	{
		i = 0;
		while (i < inst.size())
		{
			this->arr[i] = inst.arr[i];
			i++;
		}
	}
	return (*this);
}

template< typename T>
T					&Array<T>::operator[](unsigned int i)
{
	if (i >= this->size() || this->size() == false)
		throw std::runtime_error("Index out of range");
	return(this->arr[i]);
}

template< typename T>
const unsigned int	&Array<T>::size(void) const
{
	return (this->arr_size);
}
