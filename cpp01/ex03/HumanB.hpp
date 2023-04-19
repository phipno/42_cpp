/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:52:23 by pnolte            #+#    #+#             */
/*   Updated: 2023/04/19 18:10:01 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HUMANB_H__
#define __HUMANB_H__

#include <string>

#include "Weapon.hpp"

class HumanA {
   public:
    HumanB();
    ~HumanB();

    void attack();

   private:
    Weapon::weapon;
};


#endif // __HUMANB_H__

/* ************************************************************************** */
