/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 10:21:22 by pnolte            #+#    #+#             */
/*   Updated: 2023/08/21 17:12:05 by pnolte           ###   ########.fr       */
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
  std::getline(inputFile, Line);
  while (std::getline(inputFile, Line)) {
    size_t pos = Line.find('|');
    if (size_t != std::string::npos) {
      Date = Line.substr(0, pos);
      nbr = std::stof(Line.substr(pos + 1));
      this->_Input[Date] = nbr;
      std::cout << Date << nbr << std::endl;    
    }
    else 
      throw std::runtime_error("Error: bad input => " + Line);
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

