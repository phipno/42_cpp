/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:59:59 by pnolte            #+#    #+#             */
/*   Updated: 2023/08/23 16:14:55 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <iostream>
#include <vector>
#include <list>

Sort::Sort() {
  
}

Sort::Sort(const Sort &Src) {
  *this = Src;
}

Sort::~Sort() {
  
}

Sort& Sort::operator=(const Sort &Src) {
  if (this != &Src) {
    this->_VecNbr = Src._VecNbr;
    this->_vec_time_sort = Src._vec_time_sort;
    this->_list_time_sort = Src._list_time_sort;
    this->_ListNbr = Src._ListNbr;
  }
  return *this;
}

void  Sort::printThatShit() {
  std::cout << "Before: ";
  std::cout << "After: ";
  std::cout << "Time to process a range of " << this->_VecNbr.size()
            << "with std::vector : " << this->_vec_time_sort << " us" << std::endl;
  std::cout << "Time to process a range of " << this->_ListNbr.size()
            << "with std::ist : " << this->_list_time_sort << " us" << std::endl;            
}

/* ************************************************************************** */

