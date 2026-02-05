#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main() {
	std::cout << "========== 1. FRAGTRAP CONSTR/DESTR CHAINING ==========" << std::endl;
	{
		// EVAL LIST: Check if ClapTrap message comes first, then FragTrap.
		FragTrap frag("FR-4G");
		std::cout << "FragTrap is active inside this scope." << std::endl;
	}
	// EVAL LIST: Check if FragTrap message comes first, then ClapTrap.

	std::cout << "\n========== 2. ATTRIBUTES & ATTACK (INHERITANCE) ==========" << std::endl;
	{
		FragTrap frag("Destroyer");
		ClapTrap target("PoorDummy");

		// FragTrap should have 100 HP, 100 EP, and 30 Attack Damage
		frag.attack("PoorDummy");
		target.takeDamage(30); 
		// Result: PoorDummy (10 HP) should be destroyed instantly.
		
		std::cout << "--- Testing inheritance: takeDamage & beRepaired ---" << std::endl;
		frag.takeDamage(50);   // Inherited from ClapTrap
		frag.beRepaired(20);   // Inherited from ClapTrap
		// State: Should have around 70 HP and 98 EP.
	}

	std::cout << "\n========== 3. SPECIAL FEATURE: highFivesGuys() ==========" << std::endl;
	{
		FragTrap frag("FriendlyBot");
		// EVAL LIST: Positive high-fives request on standard output.
		frag.highFivesGuys();
	}

	std::cout << "\n========== 4. ENERGY DEPLETION TEST ==========" << std::endl;
	{
		FragTrap frag("EnergyBot");
		// FragTrap has 100 Energy Points. Let's use some.
		for (int i = 0; i < 5; i++) {
			frag.attack("target");
		}
		std::cout << "FragTrap still has plenty of energy left!" << std::endl;
	}

	std::cout << "\n========== 5. ORTHODOX CANONICAL FORM ==========" << std::endl;
	{
		FragTrap original("Original");
		FragTrap copy(original);
		
		FragTrap assign("Temp");
		assign = original;
	}

	return 0;
}