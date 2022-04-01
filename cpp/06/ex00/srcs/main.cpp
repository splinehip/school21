/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 12:18:15 by cflorind          #+#    #+#             */
/*   Updated: 2022/04/01 12:19:29 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Convert.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: one argument required." << std::endl;
		return (1);
	}
	else if (argv[1][0] == 0)
	{
		std::cerr << "Error: empty argument." << std::endl;
		return (1);
	}
	Convert	str(argv[1]);
	str.convert_to_char();
	str.convert_to_int();
	str.convert_to_float();
	str.convert_to_double();
	return (0);
}
