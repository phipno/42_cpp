/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:01:22 by pnolte            #+#    #+#             */
/*   Updated: 2023/08/14 15:02:40 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

#include <stdexcept>
#include <iostream>
#include <algorithm>

Span::Span() : max_size(0) {}

Span::Span(unsigned int N): max_size(N) {}

Span::Span(Span const &src) {
  *this = src;
}

Span::~Span() {
    
}

Span& Span::operator=(Span const &src) {
    if (this != &src) {
        
    }
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

int Span::shortestSpan()
{
    
}

int Span::longestSpan() {
  try {
    if (this->nbr_vec.size() <= 1)
      throw std::length_error("Vector needs more than 1 Element")
    else {
      return std::max_element(this->nbr_vec.begin(), this->nbr_vec.end())
            - std::min_element(this->nbr_vec.begin(), this->nbr_vec.end());
    }
  }
    
}

/* ************************************************************************** */

