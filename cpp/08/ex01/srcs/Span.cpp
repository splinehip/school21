/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 13:31:35 by cflorind          #+#    #+#             */
/*   Updated: 2022/04/04 16:58:12 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int size): max_size(size){std::srand(std::time(NULL));}

Span::~Span(void){}

Span::Span(Span const &inst)
{
	*this = inst;
}

Span	&Span::operator=(Span const &inst)
{
	this->max_size = inst.max_size;
	this->arr = inst.arr;
	return (*this);
}

void	Span::addNumber(int num)
{
	if (this->arr.size() == this->max_size)
		throw Span::SpanIsFullException();
	this->arr.push_back(num);
}

static int	subrand(void)
{
	return (std::rand() % 1000 + 1);
}

void	Span::addRandomRange(unsigned int range)
{
	if (range > this->max_size)
		throw Span::RangeOutOfSpanMaxSizeException();
	this->arr.resize(range);
	std::generate(this->arr.begin(), this->arr.end(), subrand);
}

int		Span::shortestSpan(void)
{
	int							res;
	std::vector<int>::iterator	next;
	std::vector<int>::iterator	current;

	if (this->arr.size() < 2)
		throw Span::NotFoundException();
	current = this->arr.begin();
	next = current + 1;
	res = std::abs(*current - *next);
	while (current != this->arr.end())
	{
		while (true)
		{
			if (res > std::abs(*current - *next))
				res = std::abs(*current - *next);
			if (next != this->arr.end())
				next++;
			else
				break ;
		}
		current++;
		next = current + 1;
	}
	return (res);
}

int		Span::longestSpan(void)
{
	std::vector<int>::iterator	max;
	std::vector<int>::iterator	min;

	max = std::max_element(this->arr.begin(), this->arr.end());
	min = std::min_element(this->arr.begin(), this->arr.end());
	return (*max - *min);
}

std::vector<int>::iterator	Span::begin(void)
{
	return (this->arr.begin());
}

std::vector<int>::iterator	Span::end(void)
{
	return (this->arr.end());
}

static void	print(int i)
{
	std::cout << i << " ";
}

std::ostream	&operator<<(std::ostream &out, Span &inst)
{
	std::for_each(inst.begin(), inst.end(), print);
	out << std::endl;
	return (out);
}
