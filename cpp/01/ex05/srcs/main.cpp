/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 19:38:38 by cflorind          #+#    #+#             */
/*   Updated: 2022/03/07 19:40:04 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int main(void)
{
	Karen	karen;

	karen.complain("debug");
	karen.complain("info");
	karen.complain("warning");
	karen.complain("error");
	return (0);
}
