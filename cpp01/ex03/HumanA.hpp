/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:52:33 by pnolte            #+#    #+#             */
/*   Updated: 2023/04/19 18:01:30 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HUMANA_H__
#define __HUMANA_H__

#include <string>

#include "Weapon.hpp"

class HumanA {
   public:
    HumanA();
    ~HumanA();

    void attack();

   private:
    Weapon::weapon;
};

#endif // __HUMANA_H__

/* ************************************************************************** */
