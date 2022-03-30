#include <iostream>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
	Bureaucrat	a("Buro_1", 5);
	{
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		a.signForm(*rrf);
		a.executeForm(*rrf);
		delete rrf;
		rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
		a.signForm(*rrf);
		a.executeForm(*rrf);
		delete rrf;
		rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
		a.signForm(*rrf);
		a.executeForm(*rrf);
		delete rrf;
	}
	return (0);
}
