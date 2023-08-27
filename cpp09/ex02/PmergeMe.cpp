/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:59:59 by pnolte            #+#    #+#             */
/*   Updated: 2023/08/27 18:17:11 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <iostream>
#include <vector>
#include <deque>
#include <stdexcept>
#include <algorithm>

Sort::Sort() : _vecNbr(0), _vec_time_sort(0), _dequeNbr(0),
               _deque_time_sort(0), _struggler(-1), _error(false) {
}

Sort::Sort(char *argv[]) : _struggler(-1), _error(false) {
  int   tmp;
  
  for (int i = 1; argv[i] != NULL; i++) {
    try {
      tmp = atoi(argv[i]);   
      if (tmp < 0)
        throw std::invalid_argument("Error: No negativ Number");
      this->_vecNbr.push_back(tmp);
      this->_dequeNbr.push_back(tmp); 
      this->_tester.push_back(tmp);
    }
    catch (std::exception &e) {
      std::cout << e.what() << std::endl;
      this->_error = true;
    }  
  }
  if (!this->_error && this->_vecNbr.size() != 1 && this->_vecNbr.size() % 2 != 0) {
    this->_struggler = this->_vecNbr.back();
    this->_vecNbr.pop_back();
    this->_dequeNbr.pop_back();
  }
  std::sort(this->_tester.begin(), this->_tester.end());
}

Sort::Sort(const Sort &Src) {
  *this = Src;
}

Sort::~Sort() {}

Sort& Sort::operator=(const Sort &Src) {
  if (this != &Src) {
    this->_vecNbr = Src._vecNbr;
    this->_vec_time_sort = Src._vec_time_sort;
    this->_deque_time_sort = Src._deque_time_sort;
    this->_dequeNbr = Src._dequeNbr;
  }
  return *this;
}

template<typename T>
void printContainer(T Con) {
  for (typename T::iterator it = Con.begin(); it != Con.end(); ++it)
    std::cout << *it << " ";
  std::cout << std::endl;
}

std::deque<std::deque<int> > createPairs(const std::deque<int>& Deque) {
    std::deque<std::deque<int> >  pairDeque;
    std::deque<int>               Pair;
    
    for (size_t i = 0; i < Deque.size(); i += 2) {
      Pair.clear();
      Pair.push_back(Deque[i]);
      Pair.push_back(Deque[i + 1]);
      pairDeque.push_back(Pair);
    }
    return pairDeque;
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

void sortEachPair(std::deque<std::deque<int> > &pairDeque) {
  for (size_t i = 0; i < pairDeque.size(); i++) {
    if (pairDeque[i][0] < pairDeque[i][1]) {
      std::swap(pairDeque[i][0], pairDeque[i][1]);
    }
  }
}

void sortEachPair(std::vector<std::vector<int> > &pairVec) {
  for (size_t i = 0; i < pairVec.size(); i++) {
    if (pairVec[i][0] < pairVec[i][1]) {
      std::swap(pairVec[i][0], pairVec[i][1]);
    }
  }
}

void sortByLargerValue(std::deque<std::deque<int> > &pairDeque, size_t n) {
  std::deque<int>   keyPair;
  int               j = n - 2;
  
  if (n <= 1)
    return;
  sortByLargerValue(pairDeque, n - 1);
  keyPair = pairDeque[n - 1];
  while (j >= 0 && pairDeque[j][0] > keyPair[0]) {
    pairDeque[j + 1] = pairDeque[j];
    j--;
  }
  pairDeque[j + 1] = keyPair;
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

std::deque<int> jacobsthalSequence(const std::deque<int> &Pend) {
  std::deque<int> sequence;
  int             jacob_index = 3;
  
  while (jacobsthal(jacob_index) < static_cast<int>(Pend.size())) {
    sequence.push_back(jacobsthal(jacob_index));
    jacob_index++;
  }
  return sequence;
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

std::deque<int> createMain(std::deque<std::deque<int> > &pairDeque, int struggler) {
  std::deque<int>           Pend;
  std::deque<int>           Main;
  std::deque<int>           insertionSequence;
  std::deque<int>           indexSequence;
  std::string               Last = "default";
  std::deque<int>::iterator insertion_pos;
  int                       nbr;
  
  for (size_t i = 0; i < pairDeque.size(); i++) {
    Main.push_back(pairDeque[i][0]);
    Pend.push_back(pairDeque[i][1]);
  }
  Main.insert(Main.begin(), Pend[0]);
  printContainer(Main);
  indexSequence.push_back(Pend[0]);
  insertionSequence = jacobsthalSequence(Pend);
  if (pairDeque.size() > 1) {
    for (std::deque<int>::iterator It = Pend.begin(); It != Pend.end(); ++It) { {
        if (insertionSequence.size() != 0 && Last != "jacob") {
          indexSequence.push_back(insertionSequence[0]);
          nbr = Pend[insertionSequence[0]];
          insertionSequence.erase(insertionSequence.begin());
          Last = "jacob";
          insertion_pos = std::upper_bound(Main.begin(), Main.end(), nbr);
          Main.insert(insertion_pos, nbr);    
        }
        else if (std::distance(Pend.begin(), It) != 0 &&
              (indexSequence[indexSequence.size() - 1]) != std::distance(Pend.begin(), It)) { 
            nbr = *It;
            Last = "not-jacob";
            insertion_pos = std::upper_bound(Main.begin(), Main.end(), nbr);
            Main.insert(insertion_pos, nbr); 
        }
        std::cout << "It is: " << *It << std::endl;
      }
    }
  }
  if (struggler != -1) {
    insertion_pos = std::lower_bound(Main.begin(), Main.end(), struggler);
    Main.insert(insertion_pos, struggler);
  }
  return Main;
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
  if (pairVec.size() > 1) {
    for (std::vector<int>::iterator It = Pend.begin(); It != Pend.end(); ++It) { {
        if (insertionSequence.size() != 0 && Last != "jacob") {
          indexSequence.push_back(insertionSequence[0]);
          nbr = Pend[insertionSequence[0]];
          insertionSequence.erase(insertionSequence.begin());
          Last = "jacob";
          insertion_pos = std::upper_bound(Main.begin(), Main.end(), nbr);
          Main.insert(insertion_pos, nbr);    
        }
        else if (std::distance(Pend.begin(), It) != 0 &&
              (indexSequence[indexSequence.size() - 1]) != std::distance(Pend.begin(), It)) { 
          nbr = *It;
          Last = "not-jacob";
          insertion_pos = std::upper_bound(Main.begin(), Main.end(), nbr);
          Main.insert(insertion_pos, nbr);    
        }
      }
    }
  }
  if (struggler != -1) {
    insertion_pos = std::lower_bound(Main.begin(), Main.end(), struggler);
    Main.insert(insertion_pos, struggler);
  }
  return Main;
}

void Sort::fordJohnsosMergeInsertSort() {  
  if (!this->_error) {
    if (this->_vecNbr.size() > 1) {
      std::vector<std::vector<int> > pairVec = createPairs(this->_vecNbr);
      sortEachPair(pairVec);
      sortByLargerValue(pairVec, pairVec.size());
      this->_vecNbr = createMain(pairVec, this->_struggler);
      if (std::is_sorted(this->_vecNbr.begin(), this->_vecNbr.end())) {
        this->_vec_time_sort = 1;  
        std::cout << "After Vector:  ";
        printContainer(this->_vecNbr);
        std::cout << "Time to process a range of " << this->_vecNbr.size() 
        << " elements with std::[vector] : " << this->_vec_time_sort << std::endl;
      }
    }
    if (this->_dequeNbr.size() > 1) {
      std::deque<std::deque<int> > pairDeque = createPairs(this->_dequeNbr);
      for (size_t i = 0; i < pairDeque.size(); i++) {
        std::cout << i << ". [" << pairDeque[i][0] << " , " << pairDeque[i][1] << "]   "; 
      }
      std::cout << std::endl;
      sortEachPair(pairDeque);
      sortByLargerValue(pairDeque, pairDeque.size());
      this->_dequeNbr = createMain(pairDeque, this->_struggler);
      if (std::is_sorted(this->_dequeNbr.begin(), this->_dequeNbr.end())) {
        this->_deque_time_sort = 1;
        std::cout << "After Deque:  ";
        printContainer(this->_dequeNbr);
        std::cout << "Time to process a range of " << this->_dequeNbr.size() 
        << " elements with std::[deque] : " << this->_deque_time_sort << std::endl;   
      }
    }
    // for (size_t i = 0; i < _tester.size(); i++) {
    //   if (_tester[i] != _vecNbr[i])
    //     std::cout << "failed vec" << std::endl;
    //   if (_tester[i] != _dequeNbr[i])
    //     std::cout << "failed Degue" << std::endl;
    // }
  }
}
  
/* ************************************************************************** */

