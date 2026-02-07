#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() {
	this->name = "Default";
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) {
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap" << this->name << " constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src): ClapTrap(src) {
	std::cout << "ScavTrap" << this->name << " copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& src) {
	std::cout << "ScavTrap assignment operator called" << std::endl;
	if (this != &src)
		ClapTrap::operator=(src);
	return *this;
}

ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap " << this->name << " destructor called" << std::endl;
};

void ScavTrap::attack(const std::string& target) {
	if (this->hitPoints == 0) {
		std::cout << "ScavTrap " << this->name << " is dead and cannot attack!" << std::endl;
		return;
	}
	if (this->energyPoints == 0)
	{
		std::cout << "ScavTrap " << this->name << " has no energy to attack!" << std::endl;
		return;
	}
	this->energyPoints--;
	std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate(void) {
	std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode." << std::endl;
}