/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 13:05:20 by cflorind          #+#    #+#             */
/*   Updated: 2022/03/14 14:07:00 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP
# include <iostream>
# include "Fixed.hpp"

class Point
{
	private:
		Fixed const	x;
		Fixed const	y;


	public:
		Point();
		Point(Point const &src);
		Point(float const _x, float const _y);
		~Point();

		Point	&operator=(Point const &src);
		Fixed	get_x(void) const;
		Fixed	get_y(void) const;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif
