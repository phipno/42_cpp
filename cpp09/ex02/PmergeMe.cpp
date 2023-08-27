/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:59:59 by pnolte            #+#    #+#             */
/*   Updated: 2023/08/27 12:53:02 by pnolte           ###   ########.fr       */
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

std::vector<std::vector<int> > createPairs(const std::vector<int>& Vec) {
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

void sortEachPair(std::vector<std::vector<int> > &pairVec) {
  for (size_t i = 0; i < pairVec.size(); i++) {
    if (pairVec[i][0] < pairVec[i][1]) {
      std::swap(pairVec[i][0], pairVec[i][1]);
    }
  }
}

void sortByLargerValue(std::vector<std::vector<int> > &pairVec, size_t n) {
  std::vector<int>  keyPair;
  int               j = n - 2;
  
  if (n <= 1)
    return;
  sortByLargerValue(pairVec, n - 1);
  keyPair = pairVec[n - 1];
  while (j >= 0 && pairVec[j][0] > keyPair[0]) {
    pairVec[j + 1] = pairVec[j];
    j--;
  }
  pairVec[j + 1] = keyPair;
}


//0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923 ...
int jacobsthal(int n) {
  if (n == 0)
    return 0;
  if (n == 1)
    return 1;
  return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
} 


std::vector<int> jacobsthalSequence(const std::vector<int> &Pend) {
  std::vector<int>  sequence;
  int               jacob_index = 3;
  
  while (jacobsthal(jacob_index) < static_cast<int>(Pend.size())) {
    sequence.push_back(jacobsthal(jacob_index));
    jacob_index++;
  }
  return sequence;
}

std::vector<int> createMain(std::vector<std::vector<int> > &pairVec, int struggler) {
  std::vector<int>            Pend;
  std::vector<int>            Main;
  std::vector<int>            insertionSequence;
  std::vector<int>            indexSequence;
  std::string                 Last = "default";
  std::vector<int>::iterator  insertion_pos;
  int                         nbr;
  
  for (size_t i = 0; i < pairVec.size(); ++i) {
    Main.push_back(pairVec[i][0]);
    Pend.push_back(pairVec[i][1]);
  }
  Main.insert(Main.begin(), Pend[0]);
  indexSequence.push_back(Pend[0]);
  insertionSequence = jacobsthalSequence(Pend);
  printContainer(Pend);
  printContainer(insertionSequence);
  for (std::vector<int>::iterator It = Pend.begin(); It != Pend.end(); It++) {
    if (insertionSequence.size() != 0 && Last != "jacob") {
      indexSequence.push_back(insertionSequence[0]);
      nbr = Pend[insertionSequence[0] - 1];
      insertionSequence.erase(insertionSequence.begin());
      Last = "jacob";
    }
    else {
      if (std::find(indexSequence.begin(), indexSequence.end(), *It) != indexSequence.end())
        It++;
      nbr = *It;
      indexSequence.push_back(*It);
      Last = "not-jacob";
    }
    insertion_pos = std::upper_bound(Main.begin(), Main.end(), nbr);
    Main.insert(insertion_pos, nbr);    
  }
  if (struggler != -1) {
    insertion_pos = std::lower_bound(Main.begin(), Main.end(), struggler);
    Main.insert(insertion_pos, struggler);
  }
  return Main;
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


  this->_struggler = -1;
  if (this->_vecNbr.size() % 2 != 0) {
    this->_struggler = this->_vecNbr.back();
    this->_vecNbr.pop_back();
    this->_listNbr.pop_back();
  }
  std::cout << this->_struggler << std::endl;

  
  std::cout << (std::is_sorted(this->_vecNbr.begin(), this->_vecNbr.end())
               ? "Sorted" : "Not Sorted") << std::endl;
  std::cout << (std::is_sorted(this->_listNbr.begin(), this->_listNbr.end())
               ? "Sorted" : "Not Sorted") << std::endl;

  std::vector<std::vector<int> > pairVec = createPairs(this->_vecNbr);
  sortEachPair(pairVec);
  sortByLargerValue(pairVec, pairVec.size());
  this->_vecNbr = createMain(pairVec, this->_struggler);
  
  std::cout << "Size: " << pairVec.size() << std::endl;
  for (size_t i = 0; i < pairVec.size(); i++) {
    std::cout << i << ". [" << pairVec[i][0] << " , " << pairVec[i][1] << "]   "; 
  }
  std::cout << std::endl;
  printContainer(this->_vecNbr);
  std::cout << (std::is_sorted(this->_vecNbr.begin(), this->_vecNbr.end())
               ? "Sorted" : "Not Sorted") << std::endl;
}

/* ************************************************************************** */

