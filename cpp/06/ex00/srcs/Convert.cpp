/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 12:01:32 by cflorind          #+#    #+#             */
/*   Updated: 2022/04/01 12:35:15 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

Convert::Convert(){}

Convert::Convert(const Convert &inst){*this = inst;}

Convert::Convert(const std::string &str)
{
	this->type = TYPE_NONE;
	this->str = str;
	this->precision = 1;

	if (str.length() == 1 && str[0] == ' '){type = TYPE_CHAR;}
	else if (is_special(str)){type = TYPE_SPECIAL;}
	else if (is_int(str)){type = TYPE_INT;}
	else if (is_char(str)){type = TYPE_CHAR;}
	else if (is_float(str)){type = TYPE_FLOAT;}
	else if (is_double(str)){type = TYPE_DOUBLE;}

	std::istringstream iss(str);
	if (type == TYPE_CHAR)
	{
		if (str.length() == 1 && str[0] == ' '){this->num = ' ';}
		else
		{
			char c;
			iss >> c;
			this->num = c;
	}	}
	if (type  == TYPE_INT || type == TYPE_FLOAT || type == TYPE_DOUBLE)
		iss >> this->num;
	double tmp1 = this->num - static_cast<double>(static_cast<int>(this->num));
	double tmp2 = tmp1;
	while (tmp2 > 0.00000001 && tmp2 < 0.99999999 && this->precision < 8)
	{
		std::cout << tmp2 << std::endl;
		if (tmp2 > 0.00000001 && tmp2 < 0.99999999)
		{this->precision++; tmp1 = tmp2;}
}	}

Convert &Convert::operator=(const Convert& inst)
{
	if (this == &inst){return *this;}
	this->num = inst.num;
	this->type = inst.type;
	this->str = inst.str;
	this->precision = inst.precision;
	return (*this);
}

Convert::~Convert(){}

bool Convert::is_char(const std::string &str)
{
	return (str.length() == 1 && std::isprint(str[0]));
}
bool Convert::is_int(const std::string &str)
{
	std::istringstream iss(str);
	int num;

	iss >> num;
	return (iss.eof() == 1 && iss.fail() == 0);
}
bool Convert::is_float(const std::string &str)
{
	std::istringstream iss(str);
	float num;
	std::string	symbol;

	iss >> num;
	iss >> symbol;
	return (symbol == "f" && iss.eof() == 1 && iss.fail() == 0);
}
bool Convert::is_double(const std::string &str)
{
	std::istringstream iss(str);
	double num;

	iss >> num;
	return (iss.eof() == 1 && iss.fail() == 0);
}
bool Convert::is_special(const std::string &str)
{
	std::istringstream iss("inf -inf +inf nan inff -inff +inff nanf");
	std::string tmp;

	while (iss.eof() == 0)
	{
		iss >> tmp;
		if (tmp == str){return (1);}
	}
	return (0);
}

void Convert::convert_to_char()
{
	std::cout << "char: ";
	if (type == TYPE_NONE){std::cout << "bad input" << std::endl;}
	else if (type == TYPE_SPECIAL){std::cout << "impossible" << std::endl;}
	else if (num < 0. || num > 255.){std::cout << "overflow" << std::endl;}
	else if (std::isprint(static_cast<char>(num))){std::cout << "'"
		<< static_cast<char>(num) << "'" << std::endl;}
	else {std::cout << "non displayable" << std::endl;}
}
void Convert::convert_to_int()
{
	std::cout << "int: ";
	if (type == TYPE_NONE){std::cout << "bad input" << std::endl;}
	else if (type == TYPE_SPECIAL){std::cout << "impossible" << std::endl;}
	else if (num < static_cast<double>(INT_MIN)
		|| num > static_cast<double>(INT_MAX)){std::cout << "overflow"
			<< std::endl;}
	else {std::cout << static_cast<int>(num) << std::endl;}
}
void Convert::convert_to_float()
{
	std::cout << "float: ";
	if (type == TYPE_NONE){std::cout << "bad input" << std::endl;}
	else if (type == TYPE_SPECIAL)
	{
		if (str == "inff" || str == "-inff" || str == "+inff" || str == "nanf")
		{std::cout << str << std::endl;}
		if (str == "inf" || str == "-inf" || str == "+inf" || str == "nan")
		{std::cout << str << 'f' << std::endl;}
	}
	else {std::cout << std::fixed << std::setprecision(this->precision)
		<< static_cast<float>(num) << 'f' << std::endl;}
}
void Convert::convert_to_double()
{
	std::cout << "double: ";
	if (type == TYPE_NONE){std::cout << "bad input" << std::endl;}
	else if (type  == TYPE_SPECIAL)
	{
		if (str == "inf" || str == "-inf" || str == "+inf" || str == "nan")
		{std::cout << str << std::endl;}
		if (str == "inff" || str == "-inff" || str == "+inff" || str == "nanf")
		{std::cout << str.substr(0, str.length() - 1) << std::endl;}
	}
	else {std::cout << std::fixed << std::setprecision(this->precision) << num
		<< std::endl;}
}
