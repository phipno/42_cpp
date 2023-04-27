/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:02:24 by pnolte            #+#    #+#             */
/*   Updated: 2023/04/27 20:23:23 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>

#include "Fixed.hpp"

Fixed::Fixed() : fp_(0) {
    std::cout << "Deafault constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src) {
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed::Fixed(const int value) {
    std::cout << "Int constructor called " << std::endl;
    this->fp_ = value << this->fractional_bits_;
}

Fixed::Fixed(const float value) {
    std::cout << "Float constructor called" << std::endl;
    this->fp_ = (roundf(value * (1 << this->fractional_bits_)));
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator = (const Fixed &src) {
    if (this != &src) {
        std::cout << "Copy assignment operattor called" << std::endl;
        this->fp_ = src.getRawBits();
    }
    return *this;
}

Fixed& Fixed::operator > (const Fixed &src)
{

}

Fixed& Fixed::operator < (const Fixed &src)
{

}

Fixed& Fixed::operator >= (const Fixed &src)
{

}

Fixed& Fixed::operator <= (const Fixed &src)
{

}

Fixed& Fixed::operator == (const Fixed &src)
{

}

Fixed& Fixed::operator != (const Fixed &src)
{

}

Fixed& Fixed::operator + (const Fixed &src)
{
}

Fixed& Fixed::operator - (const Fixed &src)
{

}

Fixed& Fixed::operator * (const Fixed &src)
{

}

Fixed& Fixed::operator / (const Fixed &src)
{

}

Fixed& Fixed::operator -- ()
{

}

Fixed& Fixed::operator -- (int i)
{

}

Fixed& Fixed::operator ++ ()
{

}

Fixed& Fixed::operator ++ (int i)
{

}


float Fixed::toFloat(void) const {
    return ((float)this->fp_ / (float)(1 << this->fractional_bits_));
}

int Fixed::toInt(void) const {
    return this->fp_ >> this->fractional_bits_;
}

int Fixed::getRawBits(void) const { return this->fp_; }

void Fixed::setRawBits(int const raw) {
    this->fp_ = raw;
}

int Fixed::min(Fixed &rfp1, Fixed &rfp2)
{

}

int Fixed::min(const Fixed &rfp1, const Fixed &rfp2)
{

}

int Fixed::max(Fixed &rfp1, Fixed &rfp2)
{

}

int Fixed::max(const Fixed &rfp1, const Fixed &rfp2)
{

}

std::ostream& operator << (std::ostream &os, const Fixed &src) {
    os << src.toFloat();
    return os;
}

/* ************************************************************************** */
