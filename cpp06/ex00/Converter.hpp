/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:26:07 by pnolte            #+#    #+#             */
/*   Updated: 2023/07/07 12:44:30 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SCALAR_H__
#define __SCALAR_H__

#include <string>

class ScalarConverter
{
    public:
        ScalarConverter(void);
        ScalarConverter(ScalarConverter const &copy);
        ~ScalarConverter(void);

        ScalarConverter &operator=(ScalarConverter const &rhs);

        void    convert(std::string const &input);
        void    print(void) const;

    private:
        std::string _input;
        char        _char;
        int         _int;
        float       _float;
        double      _double;
}   ScalarConverter;

#endif // __SCALAR_H__
/* ************************************************************************** */
