#include <iostream>
#include <string>
#include "PhoneBook.hpp"

int main()
{
	PhoneBook phonebook;
	std::string command;
	std::cout << "Welcome to the Phone Book" << std::endl;
	
	while (1)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): " << std::endl;
		std::getline(std::cin, command);
		if (std::cin.eof())
			break;
		if (command == "ADD")
			phonebook.addContact();
		else if (command == "SEARCH")
			phonebook.searchContact();
		else if (command == "EXIT")
			break;
		else
			std::cout << "Unknown command. Use ADD, SEARCH or EXIT" << std::endl;
	}
	std::cout << "Bye-bye!" << std::endl;
	return 0;
}
