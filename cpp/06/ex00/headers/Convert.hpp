/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 12:00:20 by cflorind          #+#    #+#             */
/*   Updated: 2022/04/01 12:01:21 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <iostream>
#include <sstream>
#include <iomanip>
#include <climits>

#define TYPE_NONE		0
#define TYPE_CHAR		1
#define TYPE_INT		2
#define TYPE_FLOAT		3
#define TYPE_DOUBLE		4
#define TYPE_SPECIAL	5

class Convert
{
	private:
		double		num;
		int			type;
		std::string	str;
		int			precision;

	public:
		Convert();
		Convert(const Convert &inst);
		Convert(const std::string &str);
		~Convert();

		Convert &operator=(const Convert &inst);

		bool is_char(const std::string &str);
		bool is_int(const std::string &str);
		bool is_float(const std::string &str);
		bool is_double(const std::string &str);
		bool is_special(const std::string &str);

		void convert_to_char();
		void convert_to_int();
		void convert_to_float();
		void convert_to_double();
};

#endif
