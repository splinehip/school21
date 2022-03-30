/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 13:56:26 by cflorind          #+#    #+#             */
/*   Updated: 2022/03/25 14:56:03 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(std::string _name, int _grade_to_sign, int _grade_to_execute)
: name(_name), is_signed(false), grade_to_sign(checkGrade(_grade_to_sign)),
grade_to_execute(checkGrade(_grade_to_execute)){};

Form::Form(Form const &inst): name(inst.getName()), is_signed(inst.getIsSigned()),
grade_to_sign(inst.getGradeToSign()),
grade_to_execute(inst.getGradeToExecute()){};

Form::~Form(void){};

Form	&Form::operator=(Form const &inst)
{
	*this = Form(inst.getName(), inst.getGradeToSign(), inst.getGradeToExecute());
	this->is_signed = inst.getIsSigned();
	return (*this);
}

int					Form::checkGrade(int value)
{
	if (value < 1)
		throw Form::GradeTooHighException();
	if (value > 250)
		throw Form::GradeTooLowException();
	return (value);
}

const std::string	&Form::getName(void) const
{
	return (this->name);
}

const bool			&Form::getIsSigned(void) const
{
	return (this->is_signed);
}

const int			&Form::getGradeToSign(void) const
{
	return (this->grade_to_sign);
}

const int			&Form::getGradeToExecute(void) const
{
	return (this->grade_to_execute);
}

void				Form::beSigned(Bureaucrat &inst)
{
	if (inst.getGrade() > this->getGradeToSign())
		throw Form::GradeTooLowException();
	this->is_signed = true;
}

std::ostream	&operator<<(std::ostream &out, Form const &inst)
{
	out << "name: " << inst.getName() << std::endl;
	out << "sined: " << std::boolalpha << inst.getIsSigned() << std::endl;
	out << "grade to sign: " << inst.getGradeToSign() << std::endl;
	out << "grade to execute: " << inst.getGradeToExecute() << std::endl;
	return (out);
}
