/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:19:20 by pnolte            #+#    #+#             */
/*   Updated: 2023/05/04 17:01:30 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

static void TestDiamondTrap( void ) {
    DiamondTrap clap("clap");
    DiamondTrap trap("trap");

    trap.attack("clap");
    clap.takeDamage(trap.getAttackDamage());
    clap.beRepaired(trap.getAttackDamage());
    for (int i = 0; i < 5; i++) {
        clap.attack("trap");
        trap.takeDamage(clap.getAttackDamage());
    }
    trap.beRepaired(1);
    clap.whoAmI();
}

int main() {
    std::cout << "DIAMOND TRAP DIAMOND TRAP DIAMOND TRAP DIAMOND TRAP DIAMOND TRAP DIAMOND TRAP DIAMOND TRAP\n";
    TestDiamondTrap();
    std::cout << "DIAMOND TRAP DIAMOND TRAP DIAMOND TRAP DIAMOND TRAP DIAMOND TRAP DIAMOND TRAP DIAMOND TRAP\n";
}

/* ************************************************************************** */
