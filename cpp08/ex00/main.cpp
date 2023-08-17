/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:43:01 by pnolte            #+#    #+#             */
/*   Updated: 2023/08/01 15:58:14 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

#include <vector>
#include <list>
#include <set>

int main(void) {
    std::vector<int> Vec = {1, 2, 3, 4, 5};
    easyfind(Vec, 3);
    easyfind(Vec, 6);
    easyfind(Vec, 0);
    easyfind(Vec, -1);
    std::list<int> List = {10, 20, 30, 40, 50};
    easyfind(List, 50);
    easyfind(List, 2923097);
    std::set<int> Set = {100, 200, 300, 400, 500};
    easyfind(Set, 100);
    easyfind(Set, 400);
}

/* ************************************************************************** */
