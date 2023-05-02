/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:19:20 by pnolte            #+#    #+#             */
/*   Updated: 2023/05/02 17:58:00 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
    ClapTrap clap("clap");
    ClapTrap trap("trap");
    ClapTrap def;

    trap.attack("clap");
    clap.takeDamage(0);
    for (int i = 0; i < 10; i++)
    {
        clap.attack("trap");
        trap.takeDamage(1);
    }
    trap.beRepaired(1);
    def.attack("crap");
    clap.takeDamage(9);
    clap.beRepaired(5);
    clap.attack("default");
    def.attack("clap");
    clap.takeDamage(9);
    def.attack("clap");
    clap.takeDamage(9);
    clap.beRepaired(1);
    clap.attack("default");
}

/* ************************************************************************** */
