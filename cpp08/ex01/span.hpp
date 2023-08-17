/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:01:39 by pnolte            #+#    #+#             */
/*   Updated: 2023/08/15 20:16:52 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SPAN_H__
#define __SPAN_H__

#include <vector>

class Span{
  public:
   Span();
   Span(unsigned int N);
   Span(Span const &src);
   ~Span();

   Span   &operator=(Span const &src);
   
   void   addNumber(int new_nbr);
   void   addNumbers(std::vector<int>::const_iterator first,
                      std::vector<int>::const_iterator last);
   int    shortestSpan();
   int    longestSpan();
	 
  private:
   unsigned int			max_size;
	 std::vector<int> nbr_vec;
};

#endif // __SPAN_H__
/* ************************************************************************** */