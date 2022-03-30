#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

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
	Form form2("Test form", 40, 100);
	Form form = form2;
	std::cout << form << std::endl;
	b.signForm(form);
	std::cout << form << std::endl;
	a.signForm(form);
	std::cout << form << std::endl;
	return (0);
}
