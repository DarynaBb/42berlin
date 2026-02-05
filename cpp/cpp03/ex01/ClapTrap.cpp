#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() :name("Default"), hitPoints(10), energy(10), attackDamage(0) {
	std::cout << "ClapTrap default constructor called" << std::endl;
};

ClapTrap::ClapTrap(const std::string& name) :name(name), hitPoints(10),
	energy(10), attackDamage(0) {
	std::cout << "ClapTrap " << this->name << " constructor called" << std::endl;
};

ClapTrap::ClapTrap(const ClapTrap& src) {
	std::cout << "ClapTrap copy constructor called for " << src.name << std::endl;
	*this = src;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& src) {
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	if (this != &src) {
		this->name = src.name;
		this->hitPoints = src.hitPoints;
		this->energy = src.energy;
		this->attackDamage = src.attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "ClapTrap " << this->name << " destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
	if (this->hitPoints == 0) {
		std::cout << "ClapTrap " << this->name << " is dead and cannot attack!" << std::endl;
		return;
	}
	if (this->energy == 0)
	{
		std::cout << "ClapTrap " << this->name << " has no energy to attack!" << std::endl;
		return;
	}
	this->energy--;
	std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->name << " is already dead!" << std::endl;
		return;
	}
	if (amount >= this->hitPoints)
	{
		this->hitPoints = 0;
		std::cout << "ClapTrap " << this->name << " takes " << amount 
				  << " points of damage and dies!" << std::endl;
	}
	else
		this->hitPoints -= amount;
	std::cout << "ClapTrap " << this->name << " took " << amount << " damage. Remaining hit points: " << this->hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->hitPoints > 0 && this->energy > 0) {
		this->energy--;
		this->hitPoints += amount;
		std::cout << "ClapTrap " << this->name << " repairs itself for " << amount << " points!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->name << " cannot repair: out of energy or hit points." << std::endl;
}