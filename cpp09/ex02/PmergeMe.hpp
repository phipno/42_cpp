/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:00:15 by pnolte            #+#    #+#             */
/*   Updated: 2023/08/26 13:35:40 by pnolte           ###   ########.fr       */
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
  
   void fordJohnsosMergeInsertSort(char *argv[]);

  private:
   std::vector<int> _vecNbr;
   float            _vec_time_sort;
   std::list<int>   _listNbr;
   float            _list_time_sort; 
   int              _straggler;
   bool             _has_straggler;
   
   std::list<int> sortList(std::list<int> &List);
   std::vector<int> sortVector(std::vector<int> &Vec);
};

#endif // __PMERGEME_H__
/* ************************************************************************** */
