/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phipno <phipno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:00:15 by pnolte            #+#    #+#             */
/*   Updated: 2023/08/26 01:08:04 by phipno           ###   ########.fr       */
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
  
   void  printThatShit();

  private:
   std::vector<int> _VecNbr;
   float            _vec_time_sort;
   std::list<int>   _ListNbr;
   float            _list_time_sort;  
};

std::vector<int> mergeInsertionSort(std::vector<int> &A);

#endif // __PMERGEME_H__
/* ************************************************************************** */
