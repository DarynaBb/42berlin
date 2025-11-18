#include "Contact.hpp"
#include <iostream>
#include <iomanip> //std::setw

Contact::Contact() {};

bool	isDigit(std::string input)
{
	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] < '0' || input[i] > '9')
			return false;
	}
	return true;
}

static std::string	getInput(const std::string &message) {
	std::string input;

	while(1)
	{
		std::cout << message << std::endl;
		std::getline(std::cin, input);
		if(std::cin.eof()) exit(1);
		if (input.empty())
		{
			std::cout << "Error: this field can not be empty." << std::endl;
			continue;
		}
		else if (message == "Phone number: " && !isDigit(input))
		{
			std::cout << "Your number should contain only digits" << std::endl;
			continue;
		}
		return input;
	}
}

void	Contact::setContact()
{
	firstName = getInput("First name: ");
	lastName = getInput("Last name: ");
	nickname = getInput("Nickname");
	phoneNumber = getInput("Phone number: ");
	darkestSecret = getInput("Darkest secret: ");
}

std::string	strTrunc(std::string &str)
{
	std::string truncString;

	if (str.length() > 9)
	{
		truncString = str.substr(0, 9) + ".";
		return truncString;
	}
	return str;
}

void	Contact::getContactsShort(int i)
{
	std::cout << "|" << std::setw(10) << i << "|"
			<< std::setw(10) << strTrunc(firstName) << "|"
			<< std::setw(10) << strTrunc(lastName) << "|"
			<< std::setw(10) << strTrunc(nickname) << "|"
			<< std::endl;
			std::cout << std::endl;
}

void	Contact::getContactLong()
{
	std::cout << "First name: " << firstName << std:: endl;
	std::cout << "Last name: " << lastName << std:: endl;
	std::cout << "Nickname: " << nickname << std:: endl;
	std::cout << "Phone number: " << phoneNumber << std:: endl;
	std::cout << "Darkest secret: " << darkestSecret << std:: endl;
	std::cout << std::endl;
}
