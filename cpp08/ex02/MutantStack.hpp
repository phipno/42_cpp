/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:59:40 by pnolte            #+#    #+#             */
/*   Updated: 2023/08/17 19:03:12 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack>
#include <vector>

template <typename T, typename c = std::vector<T> > 
class MutantStack : public std::stack<T, std::vector> {
  public:
   typedef typename c::iterator iterator;

   iterator begin() { return this->c.begin(); };
   iterator end() { return this->c.end(); };
   bool     empty() const{};
   T        size() const{};
   MutantStack& top() const{};
   void         push(const T &val) {};
   
   
};

