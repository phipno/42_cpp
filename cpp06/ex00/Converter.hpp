/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:26:07 by pnolte            #+#    #+#             */
/*   Updated: 2023/07/10 13:16:14 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SCALAR_H__
#define __SCALAR_H__

#include <string>

class ScalarConverter
{
    public:
     ScalarConverter(std::string input);
     ScalarConverter(ScalarConverter const &Src);
     ~ScalarConverter(void);

     ScalarConverter &operator=(ScalarConverter const &Src);
     
     int    decideType(void);
     int    doubleOrFloat(void);
     void   convert(void);
     void   print(void) const;
     void   convertChar(void);
     void   convertInt(void);
     void   convertFloat(void);
     void   convertDouble(void);
     
    private:
     std::string    _input;
     std::string    _prints[4];
     char           _char;
     int            _int;
     float          _float;
     double         _double;
};

#endif // __SCALAR_H__
/* ************************************************************************** */
