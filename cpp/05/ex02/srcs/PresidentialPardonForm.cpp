/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 12:20:19 by cflorind          #+#    #+#             */
/*   Updated: 2022/03/30 12:21:32 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const &target):
	AForm("PresidentialPardonForm", target, 25, 5){};

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &inst):
	AForm(inst.getName(), inst.getTarget(), inst.getGradeToSign(),
		inst.getGradeToExecute())
{
	this->setIsSigned(inst.getIsSigned());
}

PresidentialPardonForm::~PresidentialPardonForm(){};

PresidentialPardonForm &PresidentialPardonForm::operator=(
	PresidentialPardonForm const &inst)
{
	*this = PresidentialPardonForm(inst);
	return (*this);
}

void		PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	try
	{
		this->beExecuted(executor);
		std::cout << this->getTarget() << " was pardonned by Zafod Beeblebrox."
			<< std::endl;

	}
	catch(const AForm::AFormNotSignedException& e)
	{
		throw e;
	}
	catch(const AForm::GradeTooLowException& e)
	{
		throw e;
	}
}
