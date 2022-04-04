/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 14:05:39 by cflorind          #+#    #+#             */
/*   Updated: 2022/04/04 18:44:30 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_H
# define MUTANTSTACK_H
# include <algorithm>
# include <stack>
# include <list>

template<typename T>
class MutantStack: public std::stack<T>
{
public:
	typedef typename std::stack<T>::container_type::iterator		iterator;
	typedef typename std::stack<T>::container_type::const_iterator	c_iterator;
	typedef typename\
		std::stack<T>::container_type::reverse_iterator				r_iterator;
	typedef typename\
		std::stack<T>::container_type::const_reverse_iterator		cr_iterator;

	MutantStack(void): std::stack<T>(){};
	MutantStack(MutantStack const &inst): std::stack<T>(inst){};
	~MutantStack(){};

	MutantStack	&operator=(MutantStack const &inst)
	{
		std::stack<T>::operator=(inst);
		return (*this);
	}

	iterator	begin(void){return (std::stack<T>::c.begin());};
	c_iterator	begin(void) const {return (std::stack<T>::c.begin());};
	iterator	end(void){return (std::stack<T>::c.end());};
	c_iterator	end(void) const {return (std::stack<T>::c.end());};

	r_iterator	rbegin(void){return (std::stack<T>::c.rbegin());};
	cr_iterator	rbegin(void) const {return (std::stack<T>::c.rbegin());};
	r_iterator	rend(void){return (std::stack<T>::c.rend());};
	cr_iterator	rend(void) const {return (std::stack<T>::c.rend());};
};

#endif
