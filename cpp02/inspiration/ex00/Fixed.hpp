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


	Fixed();
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);
	~Fixed();
};


#endif //FIXED_HPP
