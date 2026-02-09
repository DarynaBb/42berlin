#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main() {

	
	std::cout << "========== 1. CONSTRUCTION / DESTRUCTION ORDER ==========" << std::endl;
	{
		ScavTrap scav("ST-01");
	}
	// EVAL LIST: Check if ScavTrap destructor is displayed first, then ClapTrap.

	std::cout << "\n========== 2. ATTRIBUTE INITIALIZATION ==========" << std::endl;
	{
		ScavTrap scav("ST-02");
		// ScavTrap damage is 20 (ClapTrap was 0). 
		// We test this by attacking a ClapTrap.
		ClapTrap target("Target");
		
		scav.attack("Target"); // Different message from ClapTrap
		target.takeDamage(20); // Should reduce ClapTrap to 0 HP immediately
		
		// EVAL LIST: Verification of high HP (100) and EP (50)
		// We'll spend 49 energy points to see if it still works
		std::cout << "--- Spending 49 energy points ---" << std::endl;
		for (int i = 0; i < 49; i++) {
			scav.attack("air");
		}
		scav.beRepaired(10); // 50th action: should work
		scav.attack("last bit of energy"); // 51st action: should fail
	}

	std::cout << "\n========== 3. SPECIAL FEATURE: guardGate() ==========" << std::endl;
	{
		ScavTrap scav("GateKeeper");
		scav.guardGate(); // EVAL LIST: Displays message for Gate keeper mode
	}

	std::cout << "\n========== 4. INHERITANCE & PROTECTED SCOPE ==========" << std::endl;
	{
		ScavTrap scav("Protector");
		scav.takeDamage(50);   // Uses inherited takeDamage()
		scav.beRepaired(25);   // Uses inherited beRepaired()
		
		// Note for Evaluator: 
		// If ScavTrap can modify hitPoints inside its constructor/methods, 
		// it proves ClapTrap attributes are now 'protected'.
	}

	std::cout << "\n========== 5. ORTHODOX CANONICAL FORM ==========" << std::endl;
	{
		ScavTrap original("Original");
		ScavTrap copy(original); // Should call ClapTrap(src) then ScavTrap(src)
		
		ScavTrap assign("Temp");
		assign = original; // Should call ClapTrap::operator= then ScavTrap::operator=
	}

	return 0;
}