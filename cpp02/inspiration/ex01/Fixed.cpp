#include "Fixed.hpp"

const int Fixed::m_fractionalBits = 8;

int Fixed::getRawBits() const {
	return m_fixedPointValue;
}

void Fixed::setRawBits(const int raw) {
	m_fixedPointValue = raw;
}

Fixed::Fixed() {
	std::cout << "Default constructor was called" << std::endl;
	m_fixedPointValue = 0;
}

Fixed::Fixed(const Fixed& other) {
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

Fixed::Fixed(const int numberToConvert) {
	std::cout << "Int constructor was called" << std::endl;
	setRawBits((int)(numberToConvert * (1 << m_fractionalBits)));
}

Fixed::Fixed(const float numberToConvert) {
	std::cout << "Float constructor was called" << std::endl;
	setRawBits((int)(numberToConvert * (float)(1 << m_fractionalBits) + (numberToConvert >= 0 ? 0.5 : -0.5)));
}

float Fixed::toFloat() const {
	return (float)(getRawBits()) / (float)(1 << m_fractionalBits);
}

int Fixed::toInt() const {
	return (int)(getRawBits()) / (int)(1 << m_fractionalBits);
}

std::ostream& operator<<(std::ostream& stream, const Fixed& fixed) {
	stream << fixed.toFloat();
	return stream;
}
