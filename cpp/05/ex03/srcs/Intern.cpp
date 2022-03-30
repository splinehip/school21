/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 12:41:37 by cflorind          #+#    #+#             */
/*   Updated: 2022/03/30 13:15:20 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Intern.hpp"

static AForm	*createPresidentialPardonForm(std::string const &target);
static AForm	*createRobotomyRequestForm(std::string const &target);
static AForm	*createShrubberyCreationForm(std::string const &target);

Intern::Intern(){};

Intern::Intern(Intern const &inst)
{
	*this = inst;
}
Intern::~Intern(){};

Intern &Intern::operator=(Intern const &inst)
{
	*this = Intern(inst);
	return (*this);
}

AForm*	Intern::makeForm(std::string const &name, std::string const &target)
{
	AForm			*form;
	typedef AForm	*(*_func)(std::string const &target);
	typedef struct	{std::string name; _func func;} FormTypes;

	form = NULL;
	FormTypes	forms[] =
	{
		{"presidential pardon", &createPresidentialPardonForm},
		{"robotomy request", &createRobotomyRequestForm},
		{"shrubbery creation", &createShrubberyCreationForm}
	};

	for (int i = 0; i < 3; i++)
	{
		if (forms[i].name == name)
		{
			form = forms[i].func(target);
			std::cout << "Intern creates " << form->getName() << std::endl;
			return (form);
		}
	}
	std::cout << "Intern can`t create the form " << name << std::endl;
	return (form);
}

static AForm	*createPresidentialPardonForm(std::string const &target)
{
	return (new PresidentialPardonForm(target));
}

static AForm	*createRobotomyRequestForm(std::string const &target)
{
	return (new RobotomyRequestForm(target));
}

static AForm	*createShrubberyCreationForm(std::string const &target)
{
	return (new ShrubberyCreationForm(target));
}
