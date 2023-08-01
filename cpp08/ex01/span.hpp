/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:01:39 by pnolte            #+#    #+#             */
/*   Updated: 2023/08/01 16:06:22 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SPAN_H__
#define __SPAN_H__

class Span{
    public:
     Span();
     Span(unsigned int N);
     Span(Span const &src);
     ~Span();

     Span   &operator=(Span const &src);
     
     void   addNumber();
     int    shortestSpan();
     int    longestSpan();
    private:
}

#endif // __SPAN_H__
/* ************************************************************************** */
