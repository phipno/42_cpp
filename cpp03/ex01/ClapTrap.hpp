/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:19:42 by pnolte            #+#    #+#             */
/*   Updated: 2023/05/02 16:26:17 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CLAPTRAP_H__
#define __CLAPTRAP_H__

#include <string>

class ClapTrap{
   public:
    ClapTrap( void );
    ClapTrap( std::string name );
    ClapTrap( const ClapTrap &src);

    ~ClapTrap();

    ClapTrap&   operator = ( const ClapTrap &src );

    void        attack( const std::string& target );
    void        takeDamage( unsigned int amount );
    void        beRepaired( unsigned int amount );

   private:
    std::string name_;
    int         hit_points_;
    int         energy_points_;
    int         attack_damage_;

};

#endif // __CLAPTRAP_H__
/* ************************************************************************** */
