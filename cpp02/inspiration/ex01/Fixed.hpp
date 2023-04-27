#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>


class Fixed {
private:
	int m_fixedPointValue;
	static const int m_fractionalBits;

public:

	int getRawBits() const;
	void setRawBits(int const raw);
	float toFloat() const;
	int toInt() const;

	Fixed();
	Fixed(const int numberToConvert);
	Fixed(const float numberToConvert);
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);
	~Fixed();
};

std::ostream& operator<<(std::ostream& stream, const Fixed& fixed);

#endif //FIXED_HPP
