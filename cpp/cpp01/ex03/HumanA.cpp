#include "HumanA.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon& weapon) : name(name), weapon(weapon) {};
HumanA::~HumanA(void) {};

void HumanA::attack(void)
{
	std::cout << name << " attacks with their " << weapon.getType() << "." << std::endl;
}