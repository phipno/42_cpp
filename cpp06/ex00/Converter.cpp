/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:33:12 by pnolte            #+#    #+#             */
/*   Updated: 2023/07/10 18:37:55 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

#include <string>
#include <iostream>

#define T_Char 0
#define T_Int 1
#define T_Float 2
#define T_Double 3
#define FAIL 4

static int detectType(std::string input, tValues **Values) {
    bool is_int = true;

    if (input.length() == 1 && input[0] >= 32 && input[1] <= 126) {
        return T_Char;
    }
    if (input == "-inff" || input == "+inff" || input == "inff")
    {
        Values->prints[T_Float] = input;
        Values->prints[T_Double] = input.erase(input.length() - 1);
        return T_Float;
    }
    if (input == "-inf" || input == "+inf" || input == "inf")
    {
        Values->prints[T_Double] = input;
        Values->prints[T_Float] = input + "f";
        return T_Double;
    }
        return T_Double;
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == '.') {
            is_int = false;
        }
    }
    if (is_int == false && input[input.length()] == 'f')
        return T_Float;
    else if (is_int == false)
        return T_Double;
    else if (is_int == true)
        return T_Int;
    else
        return FAIL;
}

// static char convertChar(const std::string input, std::string *prints, const int type) {
//     char    value;
    
//     return value;
// }

// static int  convertInt(const std::string input, std::string *prints, const int type) {
//     int value;
    
//     return value;
// }

// static float    convertFloat(const std::string input, std::string *prints, const int type){
//     int value;
    
//     return value;
// }

// static double   convertDouble(const std::string input, std::string *prints, const int type){
//     int the_double;
    
//     return the_double;
// }

int ScalarConverter::convert(std::string input) {
    tValues     Values;
    int         type;
    
    for (int i = 0; i < 4; i++)
        Values.prints[i] = "NULL";
    type = detectType(input, Values.prints);
    std::cout << Values.prints[2] << std::endl;
    std::cout << Values.prints[3] << std::endl;
    if (type == T_Char)
        Values.the_char = input[0];    
    else if (type == T_Int)
        Values.the_int = std::stoi(input);
    else if (type == T_Float)
        Values.the_float = std::stof(input);
    else if (type == T_Double)
        Values.the_double = std::stod(input);
    else if (type == FAIL)
        return 1;
    return 0;
    
    // if (type != T_Char)
    //     Values.the_char = convertChar(input, prints, type);    
    // else if (type != T_Int)
    //     Values.the_int = convertInt(input, prints, type);
    // else if (type != T_Float)
    //     Values.the_float = convertFloat(input, prints, type);
    // else if (type != T_Double)
    //     Values.the_double = convertDouble(input, prints, type);
}

/* ************************************************************************** */
