/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:52:55 by pnolte            #+#    #+#             */
/*   Updated: 2023/04/19 18:08:29 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#include "Weapon.hpp"

Weapon::Weapon(std::string type) {
    this->type_ = type;
    
}

Weapon::~Weapon() {}

std::string& Weapon::getType() { return this->type_ }

void Weapon::settype(std::string type) {
    this->type_ = type;
}

/* ************************************************************************** */
