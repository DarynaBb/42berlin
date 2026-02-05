#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main()
{
	std::cout << "===== TEST 1: CONSTRUCTION CHAINING =====" << std::endl;
	{
		ScavTrap rob1("Monica");
	}
	std::cout << "\n===== TEST 2: ATTACK AND ENERGY =====" << std::endl;
	{
		ScavTrap s1("Ross"); // Output: ClapTrap Slayer created! -> ScavTrap Slayer constructed!
		ClapTrap c1("Joey"); // Output: ClapTrap PunyHuman created!

		s1.attack("Joey");
		// Result: "ScavTrap Slayer ferociously attacks PunyHuman, causing 20 points of damage!"
		// State: Slayer's EP: 49

		c1.takeDamage(20); 
		// Result: "ClapTrap PunyHuman took 20 damage. Remaining HP: 0"
		// State: PunyHuman's HP: 0 (Dead)

		std::cout << "\n--- Testing energy depletion ---" << std::endl;
		for (int i = 0; i < 50; i++) {
			s1.attack("the air");
		}
		// Result: Last attack (when EP is 0) should print:
		// "ScavTrap Slayer is out of energy/HP to attack!"
		// State: Slayer's EP: 0

		s1.beRepaired(10); 
		// Result: "ScavTrap Slayer cannot repair: out of energy or HP."
	}

	std::cout << "\n===== TEST 3: SPECIAL CAPACITY =====" << std::endl;
	{
		ScavTrap guard("Phoebe");
		guard.guardGate();
		// Result: "ScavTrap Sentinel is now in Gate keeper mode."
		
		guard.takeDamage(99);
		// Result: "ClapTrap Sentinel took 99 damage. Remaining HP: 1"
		
		guard.beRepaired(50); 
		// Result: "ScavTrap Sentinel repairs itself for 50 points!"
		// State: HP = 51, EP = 49
	}

	std::cout << "\n===== TEST 4: ASSIGNMENT AND COPY =====" << std::endl;
	{
		ScavTrap original("Original");
		
		std::cout << "--- Copy Constructor ---" << std::endl;
		ScavTrap copy(original);
		// Result:
		// 1. "ClapTrap copy constructor called"
		// 2. "ScavTrap copy constructor called"
		// State: copy has HP=100, EP=50, Name="Original"

		std::cout << "--- Assignment Operator ---" << std::endl;
		ScavTrap assign("Temp");
		assign = original;
		// Result:
		// 1. "ClapTrap assignment operator called"
		// 2. "ScavTrap assignment operator called"
		// State: assign attributes now match original
	}

	return 0;
}
