/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 13:04:31 by cflorind          #+#    #+#             */
/*   Updated: 2022/03/24 13:51:31 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdexcept>
#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->name = name;
	this->grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &inst)
{
	*this = inst;
}
Bureaucrat::~Bureaucrat(){};

Bureaucrat			&Bureaucrat::operator=(Bureaucrat const &inst)
{
	this->name = inst.name;
	this->grade = inst.grade;
	return (*this);
}

const std::string	&Bureaucrat::getName(void) const
{
	return (this->name);
}

const int			&Bureaucrat::getGrade(void) const
{
	return (this->grade);
}

void				Bureaucrat::incGrade(unsigned int value)
{
	if (this->grade - (int)value < 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade -= value;
}

void				Bureaucrat::decGrade(unsigned int value)
{
	if (this->grade + value > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade += value;
}

void				Bureaucrat::signForm(Form &inst)
{
	try
	{
		inst.beSigned(*this);
		std::cout << this->name << " signed " << inst.getName() << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << this->name << " couldn’t sign " << inst.getName()
			<< " because " << e.what() << std::endl;
	}

}

std::ostream		&operator<<(std::ostream &out, Bureaucrat const &inst)
{
	out << inst.getName() << ", bureaucrat grade " << inst.getGrade()
		<< std::endl;
	return (out);
}
