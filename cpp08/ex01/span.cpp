/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:01:22 by pnolte            #+#    #+#             */
/*   Updated: 2023/08/15 20:19:33 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>

Span::Span() : max_size(0) {}

Span::Span(unsigned int N): max_size(N) {}

Span::Span(Span const &src) {
  *this = src;
}

Span::~Span() {}

Span& Span::operator=(Span const &src) {
    if (this != &src) {
        this->nbr_vec = src.nbr_vec;
        this->max_size = src.max_size;
    }
    return *this;
}

void Span::addNumber(int new_nbr) {
  try {
    if (this->nbr_vec.size() >= max_size)
      throw std::length_error("Vector is already full");
    else
      nbr_vec.push_back(new_nbr);  
  }
  catch (const std::exception &ex) {
    std::cerr << "Errror: " << ex.what() << std::endl;
  }
}

void Span::addNumbers(std::vector<int>::const_iterator first,
                      std::vector<int>::const_iterator last) {
  for (std::vector<int>::const_iterator it = first; it != last; it++) {
    try {
      if (this->nbr_vec.size() <= this->max_size)
        throw std::length_error("Vector is already full");
      else
        this->nbr_vec.push_back(*it);
    }
    catch (const std::exception &ex) {
      std::cerr << "Error: " << ex.what() << std::endl;
    }
  }                        
}

int Span::shortestSpan() {
  std::vector<int> sorted_vec;
  int smallest_span = std::numeric_limits<int>::max();
  int current_span;
  
  sorted_vec = this->nbr_vec;
  try {
    if (sorted_vec.size() <= 1)
      throw std::length_error("Vector needs more than 1 Element");
    else {
      std::sort(sorted_vec.begin(), sorted_vec.end());
      for(size_t i = 1; i < sorted_vec.size(); i++) {
        current_span = std::abs(sorted_vec[i] - sorted_vec[i - 1]);
        smallest_span = std::min(current_span, smallest_span);
        if (smallest_span == 0)
          return smallest_span;
      }
    }
  }
  catch (const std::exception &ex) {
    std::cerr << "Error: " << ex.what() << std::endl;
    return (-1);
  }
  return smallest_span;
}

// int Span::shortestSpan() {
  // int smallest_span = std::numeric_limits<int>::max();
  // int current_span = -1;
  
  // try {
  //   if (this->nbr_vec.size() <= 1)
  //     throw std::length_error("Vector needs more than 1 Element");
  //   else {
  //     for (size_t i = 0; i < this->nbr_vec.size(); i++) {
  //       for (size_t j = i + 1; j < this->nbr_vec.size(); j++) {
  //         current_span = std::abs(this->nbr_vec[i] - this->nbr_vec[j]);
  //         smallest_span = std::min(current_span, smallest_span);
  //         if (smallest_span == 0)
  //           return smallest_span;
  //       }
  //     }
  //   }
  // }
  // catch (const std::exception &ex) {
  //   std::cerr << "Error: " << ex.what() << std::endl;
  //   return -1;
  // } 
  // return smallest_span;
// }

int Span::longestSpan() {
  try {
    if (this->nbr_vec.size() <= 1)
      throw std::length_error("Vector needs more than 1 Element");
    else {
      return *std::max_element(this->nbr_vec.begin(), this->nbr_vec.end())
            - *std::min_element(this->nbr_vec.begin(), this->nbr_vec.end());
    }
  }
  catch (const std::exception &ex) {
    std::cerr << "Error: " << ex.what() << std::endl;
    return -1;
  }
}

/* ************************************************************************** */

