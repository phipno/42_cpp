/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 10:21:22 by pnolte            #+#    #+#             */
/*   Updated: 2023/08/21 22:06:11 by pnolte           ###   ########.fr       */
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
  if (nbr < 0) {
    throw std::runtime_error("Error: not a positive number => " + Line);
    return false;
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
  std::string Line;
  std::string Date;
  float       nbr;
  size_t      pos;
  
  std::getline(inputFile, Line);
  while (std::getline(inputFile, Line)) {
    try {
      if ((pos = Line.find('|')) != std::string::npos) {
        Date = Line.substr(0, pos);
        nbr = std::stof(Line.substr(pos + 1));
        if (validationOfFloation(Line, nbr) && validateDateDate(Date))
          this->_Input[Date] = nbr;
        std::cout << Date << nbr << std::endl;    
      }
      else 
        throw std::runtime_error("Error: bad input => " + Line);  
    }
    catch (std::exception &e) {
      std::cerr << e.what() << std::endl;
    }
  }
  std::getline(dataFile, Line);
  while (std::getline(dataFile, Line)) {
    size_t pos = Line.find(',');
    this->_Data[Line.substr(0, pos)] =  std::stof(Line.substr(pos + 1));
    std::cout << Line.substr(0, pos) << Line.substr(pos + 1) << std::endl;  
  }
  std::map<std::string, float>::iterator pair = _Input.end();
  std::map<std::string, float>::iterator pair1 = _Input.begin();
  std::cout << pair1->first << " " << pair1->second << std::endl;
  std::cout << pair->first << " " << pair->second << std::endl;
  std::cout << _Data.end()->first << std::endl;
  std::cout << _Data.end()->second << std::endl;
  std::cout << _Input.begin()->first << std::endl;
  std::cout << _Input.begin()->first << std::endl;
  inputFile.close();
  dataFile.close();
  return 0;
}


/* ************************************************************************** */

