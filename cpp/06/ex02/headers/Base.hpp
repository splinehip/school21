/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 12:51:56 by cflorind          #+#    #+#             */
/*   Updated: 2022/04/01 13:02:03 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <cstdlib>

class Base {public: virtual ~Base();};

class A : public Base {};

class B : public Base {};

class C : public Base {};

Base *generate(void);
void identify(Base *ptr);
void identify(Base &ref);

#endif
