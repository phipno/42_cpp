/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:00:15 by pnolte            #+#    #+#             */
/*   Updated: 2023/08/23 17:10:31 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PMERGEME_H__
#define __PMERGEME_H__

#include <list>
#include <vector>

class Sort{
  public:
   Sort();
   Sort(const Sort &Src);
   ~Sort();
   Sort &operator=(const Sort &Src);
  
   void  Sort::printThatShit();

  private:
   std::3<int> _VecNbr;
   float            _vec_time_sort;
   std::list<int>   _ListNbr;
   float            _list_time_sort;  
};

#endif // __PMERGEME_H__
/* ************************************************************************** */
