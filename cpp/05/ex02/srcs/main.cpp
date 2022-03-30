#include <iostream>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	Bureaucrat	a("Buro_1", 10);
	Bureaucrat	b("Buro_2", 50);

	std::cout << a << b;
	try
	{
		a.decGrade(30);
		b.incGrade(500);
	}
	catch(const Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		b.decGrade(500);
	}
	catch(const Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << a << b;
	std::cout << "Try: Bureaucrat c(\"Buro_3\", 500);" << std::endl;
	try
	{
		Bureaucrat c("Buro_3", 500);
	}
	catch(const Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << e.what() << '\n';
	}
	AForm *form = new ShrubberyCreationForm("Test");
	std::cout << *form << std::endl;
	b.signForm(*form);
	std::cout << *form << std::endl;
	a.signForm(*form);
	a.executeForm(*form);
	std::cout << *form << std::endl;
	a.decGrade(110);
	std::cout << a;
	a.executeForm(*form);
	delete form;
	a.incGrade(110);
	std::cout << std::endl;
	AForm *form2 = new RobotomyRequestForm("Test");
	std::cout << *form2 << std::endl;
	b.signForm(*form2);
	std::cout << *form2 << std::endl;
	a.signForm(*form2);
	a.executeForm(*form2);
	a.executeForm(*form2);
	std::cout << *form2 << std::endl;
	a.decGrade(110);
	std::cout << a;
	a.executeForm(*form2);
	delete form2;
	a.incGrade(145);
	std::cout << std::endl;
	AForm *form3 = new PresidentialPardonForm("Test");
	std::cout << *form3 << std::endl;
	b.signForm(*form3);
	std::cout << *form3 << std::endl;
	a.signForm(*form3);
	a.executeForm(*form3);
	std::cout << *form3 << std::endl;
	a.decGrade(110);
	std::cout << a;
	a.executeForm(*form3);
	delete form3;
	return (0);
}
