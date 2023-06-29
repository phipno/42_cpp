/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 10:18:58 by pnolte            #+#    #+#             */
/*   Updated: 2023/06/29 14:55:20 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#include "Bureaucrat.hpp"

std::ostream &operator << (std::ostream &os, const Bureaucrat &src) {
      os << src.getName() << ", bureaucrat grade " << src.getGrade() << std::endl;
      return os;
}

Bureaucrat::Bureaucrat() { return ; }

Bureaucrat::Bureaucrat(int grade, std::string name) : _name(name) {
    if (grade < 1)
        throw("grade is best already");
    else if (grade > 150)
        throw("grade is worst already");
    else
        this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) { *this = src; }

Bureaucrat::~Bureaucrat() {}

Bureaucrat& Bureaucrat::operator = (const Bureaucrat &src) {
    if (this != &src)
        this->_grade = getGrade();
    return *this;
}

void Bureaucrat::incrementGrade(void) { 
    if (this->_grade > 1)
        this->_grade--;
    else
        throw("Huh, you already got the best grade!");    
}

void Bureaucrat::decrementGrade(void) { 
    if (this->_grade < 150)
        this->_grade++; 
    else
        throw("Huh, you wanna get that worse grade?!");    
}

std::string const Bureaucrat::getName(void) const { return _name; }

int Bureaucrat::getGrade(void) const { return _grade; }

/* ************************************************************************** */
