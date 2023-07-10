/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 16:03:40 by pnolte            #+#    #+#             */
/*   Updated: 2023/07/10 10:45:54 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

#include <iostream>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Usage: ./convert [input]" << std::endl;
        return (1);
    }
    
    ScalarConverter Bob(argv[1]);
    
    Bob.convert();
    Bob.print();
}

/* ************************************************************************** */
