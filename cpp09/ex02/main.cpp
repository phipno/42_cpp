/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:59:54 by pnolte            #+#    #+#             */
/*   Updated: 2023/08/26 13:33:08 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <list>
#include <iostream>
#include <stdexcept>

#include "PmergeMe.hpp"

int main(int argc, char *argv[]) {
  Sort Logo;  
  
  std::cout << "Begin: ";
  for (int i = 1; i < argc; ++i)
    std::cout << argv[i] << " ";
  std::cout << std::endl;
  try {
    Logo.fordJohnsosMergeInsertSort(argv);
  }
  catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}

/* ************************************************************************** */
