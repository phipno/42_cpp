/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:24:07 by pnolte            #+#    #+#             */
/*   Updated: 2023/04/17 21:55:36 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ZOMBIE_H__
#define __ZOMBIE_H__

#include <string>

class Zombie {
   public:
    Zombie();
    ~Zombie();

    void announce( void );
    Zombie* newZombie( std::string name );

   private:
    std::string name_;
};

void    randomChump( std::string name );

#endif // __ZOMBIE_H__

/* ************************************************************************** */
