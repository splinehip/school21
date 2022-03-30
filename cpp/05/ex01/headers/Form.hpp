/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 13:39:46 by cflorind          #+#    #+#             */
/*   Updated: 2022/03/25 14:56:08 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include <stdexcept>
# include <iostream>
# include <string>

class Bureaucrat;

class Form
{
private:
	const std::string	name;
	bool				is_signed;
	const int			grade_to_sign;
	const int			grade_to_execute;

	static int			checkGrade(int value);

public:
	Form(std::string name, int grade_to_sign, int grade_to_execute);
	Form(Form const &inst);
	~Form(void);
	Form	&operator=(Form const &inst);

	const std::string	&getName(void) const;
	const bool			&getIsSigned(void) const;
	const int			&getGradeToSign(void) const;
	const int			&getGradeToExecute(void) const;

	void				beSigned(Bureaucrat &inst);

	class GradeTooHighException: public std::runtime_error
	{
	public:
		GradeTooHighException(void): runtime_error("Grade to high"){};
	};
	class GradeTooLowException: public std::runtime_error
	{
	public:
		GradeTooLowException(void): runtime_error("Grade to low"){};
	};
};

std::ostream	&operator<<(std::ostream &out, Form const &inst);

#endif
