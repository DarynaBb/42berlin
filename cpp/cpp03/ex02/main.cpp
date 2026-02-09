#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main() {
	std::cout << "== Fragtrap constr/destr ==" << std::endl;
	{
		FragTrap frag("frag");
	}

	std::cout << "\n== Attributes & attack ==" << std::endl;
	{
		FragTrap frag("Frag");
		ClapTrap target("Target");

		frag.attack("Target");
		target.takeDamage(30); 
		
		std::cout << "--- Testing inheritance: takeDamage & beRepaired ---" << std::endl;
		frag.takeDamage(50);
		frag.beRepaired(20);
	}

	std::cout << "\n== highFivesGuys ==" << std::endl;
	{
		FragTrap frag("Five");
		frag.highFivesGuys();
	}

	std::cout << "\n== Energy depletion test==" << std::endl;
	{
		FragTrap frag("EnergyBot");
		for (int i = 0; i < 5; i++) {
			frag.attack("target");
		}
		std::cout << "FragTrap still has plenty of energy left!" << std::endl;
	}

	std::cout << "\n== Orthodox canonical form ==" << std::endl;
	{
		FragTrap original("Original");
		FragTrap copy(original);
		
		FragTrap assign("Temp");
		assign = original;
	}

	return 0;
}