/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:38:50 by pnolte            #+#    #+#             */
/*   Updated: 2023/04/17 21:55:23 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#include "Zombie.hpp"


Zombie::Zombie* newZombie( std::string name ) {
    Zombie *rotten_flesh;

    new (rotten_flesh)
    _name = name;
    return rotten_flesh;
}

/* ************************************************************************** */
