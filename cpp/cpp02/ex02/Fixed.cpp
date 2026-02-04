#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void): value(0) {};

Fixed::~Fixed(void) {};

Fixed::Fixed(const Fixed &src) {
	this->value = src.getRawBits();
};

Fixed &Fixed::operator=(const Fixed &src) {
	if (this != &src)
		this->value = src.getRawBits();
	return *this;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return out;
}

Fixed::Fixed(const int input_num) {
	this->value = input_num << bits;
}

Fixed::Fixed(const float input_num) {
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

bool Fixed::operator>(const Fixed &src) const {
	return this->value > src.value;
}

bool Fixed::operator<(const Fixed &src) const {
	return this->value < src.value;
}

bool Fixed::operator>=(const Fixed &src) const {
	return this->value >= src.value;
}

bool Fixed::operator<=(const Fixed &src) const {
	return this->value <= src.value;
}

bool Fixed::operator==(const Fixed &src) const {
	return this->value == src.value;
}

bool Fixed::operator!=(const Fixed &src) const {
	return this->value != src.value;
}

Fixed Fixed::operator+(const Fixed &src) const {
	return Fixed(this->toFloat() + src.toFloat());
}

Fixed Fixed::operator-(const Fixed &src) const {
	return Fixed(this->toFloat() - src.toFloat());
}

Fixed Fixed::operator*(const Fixed &src) const {
	return Fixed(this->toFloat() * src.toFloat());
}

Fixed Fixed::operator/(const Fixed &src) const {
	return Fixed(this->toFloat() / src.toFloat());
}

Fixed &Fixed::operator++() {
	this->value++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp(*this); //copy of old, change the orig, return copy
	this->value++;
	return temp;
}

Fixed &Fixed::operator--() {
	this->value--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed temp(*this);
	this->value--;
	return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	if (a < b)
		return a;
	return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	if (a < b)
		return a;
	return b;
}
Fixed &Fixed::max(Fixed &a, Fixed &b) {
	if (a > b)
		return a;
	return b;
}
const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	if (a > b)
			return a;
	return b;
}