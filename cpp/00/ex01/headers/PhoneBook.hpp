/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:28:40 by cflorind          #+#    #+#             */
/*   Updated: 2022/02/21 21:30:12 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP
# define SEARCH_HADER "\
---------------------------------------------\n\
|     Index|First name| Last name|  Nickname|\n\
---------------------------------------------\n"
# define SEARCH_FOOTER "\
---------------------------------------------\n"
# include "Contact.hpp"

class PhoneBook
{
private:
	Contact contacts[8];
	int		count;
public:
	PhoneBook();
	void	add(std::string first_name, std::string last_name,
		std::string nickname, std::string phone_number,
		std::string darkest_secret);
	void	search();
	void	display_contact(void);
};

#endif
