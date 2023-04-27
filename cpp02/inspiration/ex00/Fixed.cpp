#include "Fixed.hpp"

const int Fixed::m_fractionalBits = 8;

int Fixed::getRawBits() const {
	std::cout << "getRawBits function was called" << std::endl;
	return m_fixedPointValue;
}

void Fixed::setRawBits(const int raw) {
	std::cout << "setRawBits function was called" << std::endl;
	m_fixedPointValue = raw;
}

Fixed::Fixed() {
	std::cout << "Default constructor was called" << std::endl;
	m_fixedPointValue = 0;
}

	std::cout << "Copy constructor was called" << std::endl;
	operator=(other);
}

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assigment operator was called" << std::endl;
	m_fixedPointValue = other.getRawBits();
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor was called" << std::endl;
}
