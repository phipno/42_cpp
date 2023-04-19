/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:53:01 by pnolte            #+#    #+#             */
/*   Updated: 2023/04/19 18:03:29 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WEAPON_H__
#define __WEAPON_H__

#inlcude <string>

class Weapon {
   public:
    Weapon(std::string type);
    ~Weapon();

    std::string &getType();
    void        settype(std::string type);

   private:
    std::string type_;
};

#endif // __WEAPON_H__

/* ************************************************************************** */
