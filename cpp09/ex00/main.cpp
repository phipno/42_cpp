/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:17:31 by pnolte            #+#    #+#             */
/*   Updated: 2023/08/18 15:28:23 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <iostream>
#include <cstdlib> //for EXIT_FAILURE

int main(char *argv[], int argc) {
  if (argc != 2) {
    std::cout << "Usage: ./btc [input_file]" << std::endl;
    return EXIT_FAILLURE;
  }
  return bitcoin_evaluation(argv[1]);
}

/* ************************************************************************** */
