#include "FragTrap.hpp"

#include <iostream>

FragTrap::FragTrap() : ClapTrap("Default") {
	this->hitPoints = 100;
	this->energy = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
	this->hitPoints = 100;
	this->energy = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap" << this->name << " constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& src) : ClapTrap(src) {
	std::cout << "FragTrap" << this->name << " copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& src) {
	if (this != &src)
		ClapTrap::operator=(src);
	return *this;
}

FragTrap::~FragTrap(void) {
	std::cout << "FragTrap " << this->name << " destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << this->name << " requests a high five!" << std::endl;
}