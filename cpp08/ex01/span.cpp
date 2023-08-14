/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:01:22 by pnolte            #+#    #+#             */
/*   Updated: 2023/08/14 14:41:43 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

#include <stdexcept>
#include <iostream>

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

int Span::longestSpan()
{
    
}

/* ************************************************************************** */

