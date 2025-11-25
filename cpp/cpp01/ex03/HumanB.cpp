#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanB::HumanB(std::string name) : name(name), weapon(NULL) {};
HumanB::~HumanB(void) {};

void HumanB::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;
}

void HumanB::attack(void)
{
	if (weapon)
		std::cout << name << " attacks with their " << weapon->getType() << "." << std::endl;
	else
		std::cout << name << " has no weapon." << std::endl;
}