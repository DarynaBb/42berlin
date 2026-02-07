#include "ClapTrap.hpp"
#include <iostream>

int main()
{
	std::cout << "Constructor/Destructor" << std::endl;
	{
		ClapTrap clap1("Robot1");
		ClapTrap clap2("Robot2");
	}
	std::cout << std::endl;

	std::cout << "Default Constructor" << std::endl;
	{
		ClapTrap defaultClap;
	}
	std::cout << std::endl;

	std::cout << "Copy Constructor" << std::endl;
	{
		ClapTrap original("Original");
		ClapTrap copy(original);
	}
	std::cout << std::endl;

	std::cout << "Assignment Operator" << std::endl;
	{
		ClapTrap clap1("First");
		ClapTrap clap2("Second");
		clap2 = clap1;
	}
	std::cout << std::endl;

	std::cout << "Attack" << std::endl;
	{
		ClapTrap warrior("Warrior");
		
		warrior.attack("Enemy1");
		warrior.attack("Enemy2");
		warrior.attack("Enemy3");
	}
	std::cout << std::endl;

	std::cout << "Take Damage" << std::endl;
	{
		ClapTrap victim("Victim");
		
		victim.takeDamage(3);
		victim.takeDamage(4);
		victim.takeDamage(5);  // dies here
		victim.takeDamage(2);  // shows dead message
	}
	std::cout << std::endl;

	std::cout << "Repair" << std::endl;
	{
		ClapTrap healer("Healer");
		
		healer.takeDamage(5);
		healer.beRepaired(3);
		healer.beRepaired(2);
	}
	std::cout << std::endl;

	return 0;
}
