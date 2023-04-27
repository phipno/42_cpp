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
	Fixed operator+(const Fixed& other);
	Fixed operator-(const Fixed& other);
	Fixed operator*(const Fixed& other);
	Fixed operator/(const Fixed& other);
	bool operator<(const Fixed& other);
	bool operator>(const Fixed& other);
	bool operator>=(const Fixed& other);
	bool operator<=(const Fixed& other);
	bool operator==(const Fixed& other);
	bool operator!=(const Fixed& other);
	Fixed& operator++();
	Fixed operator++(int);
	static const Fixed& max(const Fixed& fixed1, const Fixed& fixed2);
	static const Fixed& min(const Fixed& fixed1, const Fixed& fixed2);
	static const Fixed& max(Fixed& fixed1, Fixed& fixed2);
	static const Fixed& min(Fixed& fixed1, Fixed& fixed2);
	~Fixed();
};

std::ostream& operator<<(std::ostream& stream, const Fixed& fixed);

#endif //FIXED_HPP
