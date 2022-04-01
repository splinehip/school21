/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 12:49:19 by cflorind          #+#    #+#             */
/*   Updated: 2022/04/01 12:49:23 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.hpp"

int	main(void)
{
	Data	*data1 = new Data;
	uintptr_t raw;

	std::cout << std::endl << "# ====== Create ====== #" << std::endl;
	data1->name = "Pushkin";
	data1->age = 42;
	std::cout << "name = " << data1->name << "; age = " << data1->age << std::endl;

	std::cout << std::endl << "# ========= Serialize ========= #" << std::endl;
	raw = serialize(data1);
	std::cout << "ptr = " << data1 << std::endl;
	std::cout << "raw = " << raw << std::endl;
	std::cout << "hex-raw = " << std::hex << raw << std::dec << std::endl;
	std::cout << "name = " << data1->name << "; age = " << data1->age << std::endl;

	std::cout << std::endl << "# ======= Deserialize 1 ======= #" << std::endl;
	data1 = deserialize(raw);
	std::cout << "ptr = " << data1 << std::endl;
	std::cout << "raw = " << raw << std::endl;
	std::cout << "hex-raw = " << std::hex << raw << std::dec << std::endl;
	std::cout << "name = " << data1->name << "; age = " << data1->age << std::endl;

	std::cout << std::endl << "# ======= Deserialize 2 ======= #" << std::endl;
	Data *data2 = deserialize(raw);
	std::cout << "ptr = " << data2 << std::endl;
	std::cout << "raw = " << raw << std::endl;
	std::cout << "hex-raw = " << std::hex << raw << std::dec << std::endl;
	std::cout << "name = " << data2->name << "; age = " << data2->age << std::endl;

	std::cout << std::endl;
	delete data1;
	return (0);
}
