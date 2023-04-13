/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneybook.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:08:32 by pnolte            #+#    #+#             */
/*   Updated: 2023/04/13 17:23:38 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "phoneybook.hpp"

PhoneBook::PhoneBook(void)
{
	std::cout << "Constructor called" << std::endl;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}
