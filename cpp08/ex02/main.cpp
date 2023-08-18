/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 12:50:37 by pnolte            #+#    #+#             */
/*   Updated: 2023/08/18 15:01:39 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack>
#include <iostream>
#include "MutantStack.hpp"

int main() {
  MutantStack<int> mstack;
  
  mstack.push(5);
  mstack.push(17);
  std::cout << "Top element: " << mstack.top() << std::endl;
  mstack.pop();
  std::cout << "Size after pop: " << mstack.size() << std::endl;
  mstack.push(3);
  mstack.push(5);
  mstack.push(737);
  
  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();
  
  ++it;
  --it;
  std::cout << "Iterating through MutantStack:" << std::endl;
  while (it != ite)
  {
    std::cout << *it << std::endl;
    ++it;
  }
  
  // test stack implemantation 
  std::stack<int> s(mstack);
  std::cout << "Stack top element and size: " << s.top() << " | " << s.size() << std::endl;
  
  //test copy constructor
  MutantStack<int> mstackCopy(mstack);
  std::cout << "Copied stack contents:" << std::endl;
  for (MutantStack<int>::iterator cit = mstackCopy.begin(); cit != mstackCopy.end(); ++cit) {
    std::cout << *cit << std::endl;
  }
  
  //Test assignment operator
  MutantStack<int> mstackAssign;
  mstackAssign.push(99);
  mstackAssign.push(88);
  mstackAssign.push(77);
  mstackAssign = mstack;
  std::cout << "Assigned stack contents:" << std::endl;
  for (MutantStack<int>::iterator cit = mstackAssign.begin(); cit != mstackAssign.end(); ++cit) {
    std::cout << *cit << std::endl;
  }
    
  //test empty() and clear()
  MutantStack<int> empty;
  std::cout << "Is stack empty? " << (empty.empty() ? "yes" : "no") << std::endl;
  empty.swap(mstack);
  std::cout << "Is stack empty? " << (empty.empty() ? "yes" : "no") << std::endl;
  return 0;
}
/* ************************************************************************** */
