/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:26:07 by pnolte            #+#    #+#             */
/*   Updated: 2023/07/10 18:38:29 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SCALAR_H__
#define __SCALAR_H__

#include <string>

class sValues {
    public:
    std::string prints[4];
    char        the_char;
    int         the_int;
    float       the_float;
    double      the_double;
} tValues;

class ScalarConverter {
    public:
     static int convert(std::string input);
     
    private:
     ScalarConverter(void);
     ScalarConverter(ScalarConverter const &Src);
     ~ScalarConverter(void);

     ScalarConverter &operator=(ScalarConverter const &Src);
};

#endif // __SCALAR_H__
/* ************************************************************************** */
