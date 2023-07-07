/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:33:12 by pnolte            #+#    #+#             */
/*   Updated: 2023/07/07 17:15:21 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"

#include <string>
#include <iostream>

ScalarConverter::ScalarConverter(void)
{
    
}

ScalarConverter::ScalarConverter(ScalarConverter const &copy)
{
    
}

ScalarConverter::~ScalarConverter(void)
{
    
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &rhs) {
    if (this != &rhs)
        this->_input = rhs._input;
    return (*this);
}

static void _convertChar(std::string const &input)
{
    
}

static void _convertInt(std::string const &input)
{
    
}

static void _convertFloat(std::string const &input)
{
    
}

static void _convertDouble(std::string const &input)
{
    
}

static int _doubleOrFloat(std::string const &input)
{
    if ()
        return 2;
    else
        return 3;
}

static int _decideType(std::string const &input)
{
    bool is_int = true;
    
    if (input.length() == 1 && input[0] >= 32 && input[0] <= 126)
        return (0);
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == '.' && is_int == true)
        {
            is_int = false;
            return doubleOrFloat(input);
        } 
    }
    if (is_int == true)
        return (1);
}

void ScalarConverter::convert(std::string const &input) {
    int type = _decideType(input);
    if (type != 0)
        _convertChar(input);
    if (type != 1)
        _convertInt(input);
    if (type != 2)
        _convertFloat(input);
    if (type != 3)
        _convertDouble(input);
    std::cout << "char: " << _char << std::endl;
    std::cout << "int: " << _int << std::endl;
    std::cout << "float: " << _float << std::endl;
    std::cout << "double: " << _double << std::endl;
}

void ScalarConverter::print(void) const {
    
}

/* ************************************************************************** */
