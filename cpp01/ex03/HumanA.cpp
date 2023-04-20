/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:52:28 by pnolte            #+#    #+#             */
/*   Updated: 2023/04/20 14:41:30 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA( std::string name, Weapon &type ) : name_(name), type_(type) {}

HumanA::~HumanA( void ) {}

void HumanA::attack( void ) {
    std::cout << this->name_ << "attacks with their ";
    std::cout << this->type_.getType() << std::endl;
}

/* ************************************************************************** */
