/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:12:06 by cflorind          #+#    #+#             */
/*   Updated: 2022/03/07 18:14:24 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

void	do_replace(
	std::ifstream &in, std::ofstream &out, std::string s1, std::string s2)
{
	char		buf[1024];
	std::string	tmp;
	std::size_t	pos;

	(void)out;
	while (in.getline(buf, 1024, '\n'))
	{
		tmp = std::string(buf);
		pos = tmp.find(s1);
		if (pos != std::string::npos)
		{
			tmp = tmp.substr(0, pos);
			tmp.append(s2);
			pos += s1.length();
			tmp.append(std::string(buf).substr(pos));
		}
		out << tmp << std::endl;
	}
}

int main(int argc, char **argv)
{
	std::ifstream	in;
	std::ofstream	out;
	std::string		out_file_name;

	if (argc != 4)
	{
		std::cout << "Argument error, ned 3: <filename> <s1> <s2>" << std::endl;
		return (0);
	}
	out_file_name = std::string(argv[1]) + ".replace";
	in.open(argv[1], std::ios_base::in);
	if (!in.is_open())
	{
		std::cout << "Error: " << argv[1] << " file not found" << std::endl;
		return (1);
	}
	out.open(out_file_name.c_str(), std::ios_base::out | std::ios_base::trunc);
	if (!out.is_open())
	{
		std::cout << "Error: cant open file, " << out_file_name << std::endl;
		in.close();
		return (1);
	}
	do_replace(in, out, std::string(argv[2]), std::string(argv[3]));
	in.close();
	out.close();
	return (0);
}
