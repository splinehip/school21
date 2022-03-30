/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 11:54:29 by cflorind          #+#    #+#             */
/*   Updated: 2022/03/30 11:56:24 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include <cstdlib>

# include "AForm.hpp"

class	Bureaucrat;

class RobotomyRequestForm : virtual public AForm
{
public:
		RobotomyRequestForm(std::string const &target);
		RobotomyRequestForm(RobotomyRequestForm const &inst);
		virtual ~RobotomyRequestForm();
		RobotomyRequestForm	&operator=(RobotomyRequestForm const &inst);

		void		execute(Bureaucrat const &executor) const;
};

#endif
