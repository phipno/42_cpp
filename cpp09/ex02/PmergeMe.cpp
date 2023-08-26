/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:59:59 by pnolte            #+#    #+#             */
/*   Updated: 2023/08/26 14:14:32 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <iostream>
#include <vector>
#include <list>
#include <stdexcept>
#include <algorithm>

Sort::Sort() {
  
}

Sort::Sort(const Sort &Src) {
  *this = Src;
}

Sort::~Sort() {
  
}

Sort& Sort::operator=(const Sort &Src) {
  if (this != &Src) {
    this->_vecNbr = Src._vecNbr;
    this->_vec_time_sort = Src._vec_time_sort;
    this->_list_time_sort = Src._list_time_sort;
    this->_listNbr = Src._listNbr;
  }
  return *this;
}

template<typename T>
void printContainer(T Con) {
  for (typename T::iterator it = Con.begin(); it != Con.end(); ++it)
    std::cout << *it << " ";
  std::cout << std::endl;
}

std::list<int> Sort::sortList(std::list<int> &List) {
  std::list<int> sortedList;
  (void)List;
  return sortedList;
}

std::vector<int> Sort::sortVector(std::vector<int> &Vec) {
  std::vector<int> sortedVec;
  (void)Vec;
  return sortedVec;    
}

void Sort::fordJohnsosMergeInsertSort(char *argv[]) {
  int tmp;
  
  for (int i = 0; argv[i] != NULL; i++) {
    tmp = atoi(argv[i]);  
    if (tmp < 0) {
      throw std::invalid_argument("Error: No negativ Number");
      return ;
    }
    this->_vecNbr.push_back(tmp);
    this->_listNbr.push_back(tmp);
  }
  std::cout << "V E C T O R:" << std::endl;
  printContainer(this->_vecNbr);
  std::cout << "L I S T:" << std::endl;
  printContainer(this->_listNbr);
  if (this->_vecNbr.size() % 2 == 0)
    this->_has_straggler = true;
  else
    this->_has_straggler = false;
  this->_straggler = 0;
  if (this->_has_straggler) {
    this->_straggler = this->_vecNbr.back();
    this->_vecNbr.pop_back();
    this->_listNbr.pop_back();
  }
  std::cout << this->_straggler << std::endl;
  std::cout << (std::is_sorted(this->_vecNbr.begin(), this->_vecNbr.end())
               ? "Sorted" : "Not Sorted") << std::endl;
  std::cout << (std::is_sorted(this->_listNbr.begin(), this->_listNbr.end())
               ? "Sorted" : "Not Sorted") << std::endl;
}

/* ************************************************************************** */

