/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:02:16 by pnolte            #+#    #+#             */
/*   Updated: 2023/04/26 19:53:30 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_H__
#define __FIXED_H__

class Fixed {
   public:
    Fixed();
    Fixed();
    ~Fixed();

    Fixed &operator = (const Fixed &other);

   private:
    int                 i;
    static const int    sci;
};

#endif // __FIXED_H__

/* ************************************************************************** */
