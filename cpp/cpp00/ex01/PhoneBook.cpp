#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <limits>

PhoneBook::PhoneBook() {
	contacts_count = 0;
	oldest = 0;
}

void PhoneBook::addContact()
{
	if (contacts_count == 8)
	{
		contacts[oldest].setContact();
		oldest = (oldest + 1) % 8;
	}
	else
	{
		contacts[contacts_count].setContact();
		contacts_count++;
	}
	std::cout << "Contact saved!" <<std::endl;
	std::cout << std::endl;
}

void PhoneBook::searchContact()
{
	std::string index;

	if (contacts_count == 0)
	{
		std::cout << "No contacts in the phone book yet." << std::endl;
		return;
	}
	std::cout << "|" << std::setw(10) << "Index" << "|"
			 << std::setw(10) << "First Name" << "|"
			 << std::setw(10) << "Last Name" << "|"
			 << std::setw(10) << "Nickname" << "|" << std::endl;
	for (int i = 0; i < contacts_count; i++)
		contacts[i].getContactsShort(i);
	
	std::cout << "Enter the index of the contact (from 0 to 7): " << std::endl;
	std::getline(std::cin, index);
	if (std::cin.eof()) return;
	if (index.length() != 1 || index[0] < '0' || index[0] > '7')
	{
		std::cout << "Invalid index." << std::endl;
		std::cout << std::endl;
		return ;
	}
	else if ((index[0] - '0') >= contacts_count)
	{
		std::cout << "No contact at this index." << std::endl;
		std::cout << std::endl;
		return;
	}
	else
		contacts[index[0] - '0'].getContactLong();
}
