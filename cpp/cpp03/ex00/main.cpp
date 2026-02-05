#include "ClapTrap.hpp"
#include <iostream>

int main()
{
	std::cout << "===== TEST 1: INITIALIZATION & BASICS =====" << std::endl;
	{
		ClapTrap clippy("Clippy");
		// State: HP 10, Energy 10, Damage 0
		clippy.attack("a training dummy");
		// Result: Should print attack message, Energy becomes 9.
		clippy.beRepaired(5);
		// Result: HP becomes 15, Energy becomes 8.
	}

	std::cout << "\n===== TEST 2: ENERGY DEPLETION =====" << std::endl;
	{
		ClapTrap tired("TiredBot");
		// Exhaust all 10 energy points
		for (int i = 0; i < 10; i++) {
			tired.attack("target");
		}
		// 11th action: Should fail because Energy is 0
		std::cout << "--- 11th action attempt ---" << std::endl;
		tired.attack("target");
		tired.beRepaired(10);
	}

	std::cout << "\n===== TEST 3: HIT POINTS & DEATH =====" << std::endl;
	{
		ClapTrap fragile("FragileBot");
		fragile.takeDamage(5); // HP: 5
		fragile.takeDamage(10); // HP: 0 (should handle overflow and not go to -5)
		
		// Should not be able to act with 0 HP
		std::cout << "--- Actions after death ---" << std::endl;
		fragile.attack("someone");
		fragile.beRepaired(5);
	}

	std::cout << "\n===== TEST 4: ORTHODOX CANONICAL FORM =====" << std::endl;
	{
		ClapTrap original("Original");
		ClapTrap copy(original); // Copy constructor
		ClapTrap assignee("ToAssign");
		assignee = original;	 // Assignment operator
	}

	std::cout << "=== ClapTrap Tests ===" << std::endl;
	std::cout << std::endl;

	std::cout << "--- Test 1: Constructor/Destructor ---" << std::endl;
	{
		ClapTrap clap1("Robot1");
		ClapTrap clap2("Robot2");
	}
	std::cout << std::endl;

	std::cout << "--- Test 2: Default Constructor ---" << std::endl;
	{
		ClapTrap defaultClap;
	}
	std::cout << std::endl;

	std::cout << "--- Test 3: Copy Constructor ---" << std::endl;
	{
		ClapTrap original("Original");
		ClapTrap copy(original);
	}
	std::cout << std::endl;

	std::cout << "--- Test 4: Assignment Operator ---" << std::endl;
	{
		ClapTrap clap1("First");
		ClapTrap clap2("Second");
		clap2 = clap1;
	}
	std::cout << std::endl;

	std::cout << "--- Test 5: Attack Tests ---" << std::endl;
	{
		ClapTrap warrior("Warrior");
		
		warrior.attack("Enemy1");
		warrior.attack("Enemy2");
		warrior.attack("Enemy3");
	}
	std::cout << std::endl;

	std::cout << "--- Test 6: Take Damage Tests ---" << std::endl;
	{
		ClapTrap victim("Victim");
		
		victim.takeDamage(3);
		victim.takeDamage(4);
		victim.takeDamage(5);  // die here
		victim.takeDamage(2);  // shows dead message
	}
	std::cout << std::endl;

	std::cout << "--- Test 7: Repair Tests ---" << std::endl;
	{
		ClapTrap healer("Healer");
		
		healer.takeDamage(5);
		healer.beRepaired(3);
		healer.beRepaired(2);
	}
	std::cout << std::endl;

	std::cout << "--- Test 8: Energy Depletion ---" << std::endl;
	{
		ClapTrap tired("Tired");

		// Exhaust energy points (10 attacks/repairs)
		for (int i = 0; i < 11; i++)
		{
			tired.attack("Target");
		}

		// Try to repair with no energy
		tired.beRepaired(5);
	}
	std::cout << std::endl;

	std::cout << "--- Test 9: Dead Robot Tests ---" << std::endl;
	{
		ClapTrap doomed("Doomed");
		
		doomed.takeDamage(10);  // Kills
		doomed.attack("Someone");  // Should fail
		doomed.beRepaired(5);  // Should fail
	}
	std::cout << std::endl;

	std::cout << "--- Test 10: Mixed Scenario ---" << std::endl;
	{
		ClapTrap fighter("Fighter");
		
		fighter.attack("Monster");
		fighter.takeDamage(6);
		fighter.beRepaired(4);
		fighter.attack("Monster");
		fighter.takeDamage(8);
		fighter.attack("Monster");  // Should have no energy or be dead
	}
	std::cout << std::endl;

	std::cout << "=== End of Tests ===" << std::endl;
	return 0;
}
