#include <iostream>
#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed const multiplicationFixed( Fixed( 5.05f ) * Fixed( 2 ) );
	float multiplicationFloat = 5.05f * 2;
	std::cout << "Fixed: " << multiplicationFixed << " | Float: " << multiplicationFloat << std::endl;
	std::cout << std::endl;

	Fixed const additionFixed( Fixed( 5.05f ) + Fixed( 2 ) );
	float additionFloat = 5.05f + 2;
	std::cout << "Fixed: " << additionFixed << " | Float: " << additionFloat << std::endl;
	std::cout << std::endl;

	Fixed const negationFixed( Fixed( 5.05f ) - Fixed( 2 ) );
	float negationFloat = 5.05f - 2;
	std::cout << "Fixed: " << negationFixed << " | Float: " << negationFloat << std::endl;
	std::cout << std::endl;

	Fixed const divisionFixed( Fixed( 5.50f ) / Fixed( 2 ) );
	float divisionFloat = 5.50f / 2;
	std::cout << "Fixed: " << divisionFixed << " | Float: " << divisionFloat << std::endl;
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;

	Fixed num1(20.23f);
	Fixed num2(20.25f);

	std::cout << "num1: " << num1 << " | num2: " << num2 << std::endl;
	std::cout << "num1 > num2: " << (num1 > num2) << std::endl;
	std::cout << "num1 < num2: " << (num1 < num2) << std::endl;
	std::cout << "num1 >= num2: " << (num1 >= num2) << std::endl;
	std::cout << "num1 <= num2: " << (num1 <= num2) << std::endl;
	std::cout << "num1 == num2: " << (num1 == num2) << std::endl;
	std::cout << "num1 != num2: " << (num1 != num2) << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Post/Pre incrementing" << std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}
