/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 13:56:26 by cflorind          #+#    #+#             */
/*   Updated: 2022/03/25 19:14:44 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(std::string _name, std::string _target, int _grade_to_sign,
	int _grade_to_execute): name(_name), target(_target), is_signed(false),
	grade_to_sign(checkGrade(_grade_to_sign)),
	grade_to_execute(checkGrade(_grade_to_execute)){};

AForm::AForm(AForm const &inst): name(inst.getName()), target(inst.getTarget()),
	is_signed(inst.getIsSigned()), grade_to_sign(inst.getGradeToSign()),
	grade_to_execute(inst.getGradeToExecute()){};

AForm::~AForm(void){};

/* AForm	&AForm::operator=(AForm const &inst)
{
	*this = AForm(inst.getName(), inst.getTarget(), inst.getGradeToSign(),
		inst.getGradeToExecute());
	this->is_signed = inst.getIsSigned();
	return (*this);
} */

int					AForm::checkGrade(int value)
{
	if (value < 1)
		throw AForm::GradeTooHighException();
	if (value > 250)
		throw AForm::GradeTooLowException();
	return (value);
}

const std::string	&AForm::getName(void) const
{
	return (this->name);
}

const std::string	&AForm::getTarget(void) const
{
	return (this->target);
}

const bool			&AForm::getIsSigned(void) const
{
	return (this->is_signed);
}

const int			&AForm::getGradeToSign(void) const
{
	return (this->grade_to_sign);
}

const int			&AForm::getGradeToExecute(void) const
{
	return (this->grade_to_execute);
}

void				AForm::setIsSigned(bool value)
{
	this->is_signed = value;
}

void				AForm::beSigned(Bureaucrat &inst)
{
	if (inst.getGrade() > this->getGradeToSign())
		throw AForm::GradeTooLowException();
	this->is_signed = true;
}

void				AForm::beExecuted(Bureaucrat const &inst) const
{
	if (this->getIsSigned() == false)
		throw AFormNotSignedException();
	if (inst.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
}

std::ostream	&operator<<(std::ostream &out, AForm const &inst)
{
	out << "name: " << inst.getName() << std::endl;
	out << "target: " << inst.getTarget() << std::endl;
	out << "sined: " << std::boolalpha << inst.getIsSigned() << std::endl;
	out << "grade to sign: " << inst.getGradeToSign() << std::endl;
	out << "grade to execute: " << inst.getGradeToExecute() << std::endl;
	return (out);
}
