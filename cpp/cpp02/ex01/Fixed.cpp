#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void): value(0) {
	std::cout << "Default constructor called" << std::endl;
};

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
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

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return out;
}

Fixed::Fixed(const int input_num) {
	std::cout << "Int constructor called" << std::endl;
	this->value = input_num << bits;
}

Fixed::Fixed(const float input_num) {
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(input_num * (1 << bits));
}

int Fixed::getRawBits(void) const {
	return this->value;
}

void Fixed::setRawBits(int const raw) {
	this->value = raw;
}

float Fixed::toFloat(void) const {
	return (float)this->value / (1 << bits);
}

int Fixed::toInt(void) const {
	return this->value >> bits;
}