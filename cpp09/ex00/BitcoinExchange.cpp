/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 10:21:22 by pnolte            #+#    #+#             */
/*   Updated: 2023/08/22 14:30:41 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <string>
#include <fstream>
#include <iostream>
#include <exception>

myBitCoin::myBitCoin() {}

myBitCoin::myBitCoin(const myBitCoin &src) {
  *this = src;
}

myBitCoin& myBitCoin::operator=(const myBitCoin &src) {
  if (this != &src) {
    this->_Data = src._Data;
    this->_Input = src._Input;
  }
  return *this;
}

myBitCoin::~myBitCoin() {}

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool validateDateDate(std::string Date) {
  int year, month, day;
  static const int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  if (sscanf(Date.c_str(), "%d-%d-%d", &year, &month, &day) == 3) {
    if (year < 0 || month < 1 || month > 12 || day < 1) {
      throw std::runtime_error("Error: Invalid date format => " + Date);
      return false;
    }
    if (month == 2 && isLeapYear((year)))
      return day <= 29;
    else
      return day <= daysInMonth[month];
  }
  else {
    throw std::runtime_error("Error: Invalid date format => " + Date);
    return false;
  }
}


bool validationOfFloation(std::string Line, float nbr) {
  if (nbr < 0 && nbr > std::numeric_limits<int>::max()) {
    throw std::runtime_error("Error: not a positive number => " + Line);
    return false;
  }
  return true;
}

void  myBitCoin::readerOfCoins(std::ifstream &File, char delimiter, std::map<std::string, float> &Fill) {
  std::string Line;
  std::string Date;
  float       nbr;
  size_t      pos;
  
  std::getline(File, Line);
  while (std::getline(File, Line)) {
    try {
      if ((pos = Line.find(delimiter)) != std::string::npos) {
        Date = Line.substr(0, pos);
        nbr = std::stof(Line.substr(pos + 1));
        if (validationOfFloation(Line, nbr) && validateDateDate(Date))
          Fill[Date] = nbr;
        // std::cout << Date << nbr << std::endl;    
      }
      else 
        throw std::runtime_error("Error: bad input => " + Line);  
    }
    catch (std::exception &e) {
      std::cerr << e.what() << std::endl;
    }
  }
}

int myBitCoin::bitcoinEvaluation(std::string const file) {
  std::ifstream inputFile;
  std::ifstream dataFile;

  inputFile.open(file);
  dataFile.open("data.csv");
  if (!inputFile.is_open() || !dataFile.is_open()) {
    if (!inputFile.is_open())
      std::cerr << "Error: Unable to open: " << file << std::endl;
    if (!dataFile.is_open())
      std::cerr << "Error: Unable to open: data.csv" << std::endl;
    return EXIT_FAILURE;
  }

  readerOfCoins(inputFile, '|', this->_Input);
  readerOfCoins(dataFile, ',', this->_Data);

  

  std::cout << this->_Data.begin()->first << this->_Data.begin()->second << std::endl;
  std::cout << this->_Input.begin()->first << this->_Input.begin()->second << std::endl;
  inputFile.close();
  dataFile.close();
  return 0;
}


/* ************************************************************************** */

