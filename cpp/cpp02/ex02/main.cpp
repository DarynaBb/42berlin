#include "Fixed.hpp"

#include <iostream>

int main( void ) {
	Fixed a; //0
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed c(5.5f);
	Fixed d(20);

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << "---------------------------------------" << std::endl;

	// (==)
	std::cout << "a == b: " << (a == b) << " (Expected: 0)" << std::endl;

	// (!=)
	std::cout << "a != c: " << (a != c) << " (Expected: 1)" << std::endl;
	std::cout << "a != b: " << (a != b) << " (Expected: 1)" << std::endl;

	// (>)
	std::cout << "d > a : " << (d > a) << " (Expected: 1)" << std::endl;
	std::cout << "c > a : " << (c > a) << " (Expected: 1)" << std::endl;

	// (<)
	std::cout << "c < a : " << (c < a) << " (Expected: 0)" << std::endl;

	// (>=)
	std::cout << "a >= b: " << (a >= b) << " (Expected: 0)" << std::endl;
	std::cout << "d >= a: " << (d >= a) << " (Expected: 1)" << std::endl;

	// (<=)
	std::cout << "a <= b: " << (a <= b) << " (Expected: 1)" << std::endl;
	std::cout << "c <= a: " << (c <= a) << " (Expected: 0)" << std::endl;

	// +
	std::cout << "c + d = " << (c + d) << " (Expected: 25.5)" << std::endl;

	// -
	std::cout << "d - c = " << (d - c) << " (Expected: 14.5)" << std::endl;
	std::cout << "a - d = " << (a - d) << " (Expected: -19.9922)" << std::endl;

	// *
	std::cout << "c * 2 = " << (c * Fixed(2)) << " (Expected: 11)" << std::endl;
	std::cout << "b * c = " << (b * c) << " (Expected: ~55.55)" << std::endl;

	// /
	std::cout << "d / c = " << (d / c) << " (Expected: ~3.636)" << std::endl;
	std::cout << "d / 2 = " << (d / Fixed(2)) << " (Expected: 10)" << std::endl;

	std::cout << "c / a: " << (c / 0) << std::endl;

	// min/max
	std::cout << "max(a, d): " << Fixed::max(a, d) << " (Expected: 20)" << std::endl;
	std::cout << "min(a, d): " << Fixed::min(a, d) << " (Expected: value of a)" << std::endl;

	return 0;
}