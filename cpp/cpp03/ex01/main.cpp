#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main() {

	
	std::cout << "== Construction/destruction order ==" << std::endl;
	{
		ScavTrap scav("Robot");
	}

	std::cout << "\n== Attribute initialization ==" << std::endl;
	{
		ScavTrap scav("Robot");
		ClapTrap target("Target");
		
		target.attack("Robot");
		scav.attack("Target");
		target.takeDamage(20);
		scav.beRepaired(10);
		target.attack("Robot");
	}

	std::cout << "\n== guardGate() ==" << std::endl;
	{
		ScavTrap scav("GateKeeper");
		scav.guardGate();
	}

	std::cout << "\n== Inheritance & protected scope ==" << std::endl;
	{
		ScavTrap scav("Protector");
		scav.takeDamage(50);
		scav.beRepaired(25);
	}

	std::cout << "\n== Orthodox canonical form ==" << std::endl;
	{
		ScavTrap original("Original");
		ScavTrap copy(original);
		
		ScavTrap assign("Temp");
		assign = original;
	}

	return 0;
}