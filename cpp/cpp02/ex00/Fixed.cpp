#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(void) {
	value = 0;
	std::cout << "Default constructor called" << std::endl;
};

Fixed::~Fixed(void) {
	std::cout << "Desctructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src) {
	std::cout << "Copy constructor called" << std::endl;
	this->value = src.getRawBits();
};

Fixed &Fixed::operator=(const Fixed &src) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->value = src.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->value;
}

void Fixed::setRawBits(int const raw) {
	this->value = raw;
}