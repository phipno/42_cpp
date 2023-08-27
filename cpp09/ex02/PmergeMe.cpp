/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:59:59 by pnolte            #+#    #+#             */
/*   Updated: 2023/08/27 08:59:27 by pnolte           ###   ########.fr       */
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

std::vector<std::vector<int> > create_pairs(const std::vector<int>& Vec) {
    std::vector<std::vector<int> >  pairVec;
    std::vector<int>                Pair;
    
    for (size_t i = 0; i < Vec.size(); i += 2) {
      Pair.clear();
      Pair.push_back(Vec[i]);
      Pair.push_back(Vec[i + 1]);
      pairVec.push_back(Pair);
    }
    return pairVec;
}

void sort_each_pair(std::vector<std::vector<int> > &pairVec) {
  for (size_t i = 0; i < pairVec.size(); i++) {
    if (pairVec[i][0] < pairVec[i][1]) {
      std::swap(pairVec[i][0], pairVec[i][1]);
    }
  }
}


void Sort::fordJohnsosMergeInsertSort(char *argv[]) {
  int tmp;
  
  for (int i = 1; argv[i] != NULL; ++i) {
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

  
  this->_struggler = 0;
  this->_has_struggler = this->_vecNbr.size() % 2 != 0;
  if (this->_has_struggler) {
    this->_struggler = this->_vecNbr.back();
    this->_vecNbr.pop_back();
    this->_listNbr.pop_back();
  }
  std::cout << this->_struggler << std::endl;

  
  std::cout << (std::is_sorted(this->_vecNbr.begin(), this->_vecNbr.end())
               ? "Sorted" : "Not Sorted") << std::endl;
  std::cout << (std::is_sorted(this->_listNbr.begin(), this->_listNbr.end())
               ? "Sorted" : "Not Sorted") << std::endl;

  std::vector<std::vector<int> > pairVec = create_pairs(this->_vecNbr);
  sort_each_pair(pairVec);

  std::cout << "Size: " << pairVec.size() << std::endl;
  for (size_t i = 0; i < pairVec.size(); i++) {
    std::cout << i << ". [" << pairVec[i][0] << " , " << pairVec[i][1] << "]   "; 
  }
  std::cout << std::endl;
}

/* ************************************************************************** */

