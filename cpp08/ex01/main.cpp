/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:01:08 by pnolte            #+#    #+#             */
/*   Updated: 2023/08/15 20:26:34 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

#include <iostream>

int main(void) {
  Span sp = Span(5);
  
  std::cout << "S U B J E C T  T E S T I N G" << std::endl;
  sp.addNumber(6);
  sp.addNumber(3);
  sp.addNumber(17);
  sp.addNumber(9);
  sp.addNumber(11);
  std::cout << sp.shortestSpan() << std::endl;
  std::cout << sp.longestSpan() << std::endl;
  std::cout << "S U B J E C T  T E S T I N G" << std::endl;
  std::cout << "A D D I N G  V E C T O R" << std::endl;
  std::vector<int> add_vec = {1, 3, 0 , -1, 3, 100};
  Span Sp2(5);
  Span Sp3(Sp2);

  Sp3.addNumbers(add_vec.begin(), add_vec.end());
  std::cout << Sp3.shortestSpan() << std::endl;
  std::cout << Sp3.longestSpan() << std::endl;
  
  
  

  
}

/* ************************************************************************** */
