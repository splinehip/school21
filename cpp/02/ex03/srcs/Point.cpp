/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 13:07:02 by cflorind          #+#    #+#             */
/*   Updated: 2022/03/14 14:11:27 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): x(0), y(0) {}

Point::Point(const Point &src): x(src.x), y(src.y) {}

Point::Point(float const _x, float const _y): x(_x), y(_y) {}

Point::~Point() {}

Point &Point::operator=(Point const &src)
{
	*this = Point(src);
	return (*this);
}

Fixed	Point::get_x(void) const
{
	return (this->x);
}

Fixed	Point::get_y(void) const
{
	return (this->y);
}

