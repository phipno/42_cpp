/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:33:12 by pnolte            #+#    #+#             */
/*   Updated: 2023/07/10 13:29:25 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

#include <string>
#include <iostream>

ScalarConverter::ScalarConverter(std::string input) : _input(input) {
    for (int i = 0; i < 4; i++)
        this->_prints[i] = "NULL";
}

ScalarConverter::ScalarConverter(ScalarConverter const &Src) {
    *this = Src;
}

ScalarConverter::~ScalarConverter(void) {}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &Src) {
    if (this != &Src) {
        for (int i = 0; i < 4; i++)
            this->_prints[i] = "NULL";
        this->_input = Src._input;
    }
    return (*this);
}

void ScalarConverter::convertChar() {
    int check = std::atoi(this->_input.c_str());
     
    if (check >= 32 && check <= 126 ) {
        this->_prints[0] = "NULL";
        this->_char = check;
    }
    else
        this->_prints[0] = "Non displayable";
        
}

void ScalarConverter::convertInt() {
    if (_input.length() == 1 && _input[0] >= 32 && _input[0] <= 126) {
        this->_float = _input[0];
    }
    else 
        this->_int = std::atoi(_input.c_str());
}

void ScalarConverter::convertFloat() {
    if (_input.length() == 1 && _input[0] >= 32 && _input[0] <= 126) {
        this->_float = _input[0];
    }
    else {
        try {
            this->_float = std::stof(_input.c_str());
        }
        catch (std::exception& e) {
            this->_prints[2] = "Non displayable";
        }    
    }
}

void ScalarConverter::convertDouble() {
    if (_input.length() == 1 && _input[0] >= 32 && _input[0] <= 126) {
        this->_float = _input[0];
    }
    else {    
        try {
            this->_double = std::stof(_input.c_str());
        }
        catch (std::exception& e) {
            this->_prints[3] = "Non displayable";
        }
    }
}

int ScalarConverter::doubleOrFloat()
{
    for (int i = 0; i < _input[i] != '\0'; i++) {
        if (_input[i] == 'f' || _input[i] == 'F') {
            convertFloat();
            return 2;
        }
    }
    convertDouble();
    return 3;
}

int ScalarConverter::decideType()
{
    bool    is_int = true;
    
    if (_input.length() == 1 && _input[0] >= 32 && _input[0] <= 126) {
        this->_char = _input[0];
        return 0;
    }
    else
        _prints[0] = "Non displayable";
    for (int i = 0; _input[i] != '\0'; i++) {
        if (_input[i] == '.' && is_int == true)
        {
            is_int = false;
            return doubleOrFloat();
        }
    }
    if (is_int == true) {
        convertInt();
        return 1;
    }
    return 5;
}

void ScalarConverter::convert() {
    int type = decideType();
    if (type != 0)
        convertChar();
    if (type != 1)
        convertInt();
    if (type != 2)
        convertFloat();
    if (type != 3)
        convertDouble();
}

void ScalarConverter::print(void) const {
    if (this->_prints[0] == "NULL")
        std::cout << "char: " << _char << std::endl;
    else
        std::cout << "char: " << this->_prints[0] << std::endl;
    if (this->_prints[1] == "NULL")
        std::cout << "int: " << _int << std::endl;
    else
        std::cout << "int: " << this->_prints[1] << std::endl;
    if (this->_prints[2] == "NULL")
        std::cout << "float: " << _float << "f" << std::endl;
    else
        std::cout << "float: " << this->_prints[2] << std::endl;
    if (this->_prints[3] == "NULL")
        std::cout << "double: " << _double << std::endl;
    else
        std::cout << "double: " << this->_prints[3] << std::endl;
    
}

/* ************************************************************************** */
