/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 10:18:58 by pnolte            #+#    #+#             */
/*   Updated: 2023/07/04 17:41:24 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <iostream>

int main() {
    Bureaucrat King(1, "King");
    Bureaucrat Me(150, "Philipp");
    PresidentailPardonForm Pardon("All Sinners");
    RobotomyRequestForm Robot("Bender");
    ShrubberyCreationForm Tree("Tree");
    
    std::cout << King << std::endl;
    std::cout << Me << std::endl;

    Pardon.beSigned(King);
    Robot.beSigned(King);
    Tree.beSigned(King);
    Pardon.execute(King);
    Robot.execute(King);
    Tree.execute(King);
    

    std::cout << "hi\n";
    King.executeForm(Pardon);
    King.executeForm(Robot);
    King.executeForm(Tree);
}

/* ************************************************************************** */
