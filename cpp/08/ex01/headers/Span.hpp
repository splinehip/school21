/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 14:05:39 by cflorind          #+#    #+#             */
/*   Updated: 2022/04/04 16:32:22 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_H
# define SPAN_H
# include <iostream>
# include <algorithm>
# include <vector>
# include <stdexcept>
# include <ctime>
# include <cstdlib>

class Span
{
private:
	Span(void);

protected:
	unsigned int		max_size;
	std::vector<int>	arr;

public:
	Span(unsigned int size);
	Span(Span const &inst);
	~Span();

	Span	&operator=(Span const &inst);
	void	addNumber(int num);
	void	addRandomRange(unsigned int range);
	int		shortestSpan(void);
	int		longestSpan(void);
	std::vector<int>::iterator	begin(void);
	std::vector<int>::iterator	end(void);

	class NotFoundException: public std::runtime_error
	{
	public:
		NotFoundException(void): std::runtime_error("Not found"){};
	};
	class RangeOutOfSpanMaxSizeException: public std::runtime_error
	{
	public:
		RangeOutOfSpanMaxSizeException(void)
		: std::runtime_error("Range biggets than max_size"){};
	};
	class SpanIsFullException: public std::runtime_error
	{
	public:
		SpanIsFullException(void): std::runtime_error("Span size is maximum"){};
	};
};

std::ostream	&operator<<(std::ostream &out, Span &inst);

#endif
