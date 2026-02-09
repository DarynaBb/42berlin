#include "Dog.hpp"
#include <iostream>

Dog:: Dog() : Animal()
{
	this->type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
};

Dog::Dog(const Dog& src) : Animal(src)
{
	std::cout << "Dog copy constructor called" << std::endl;
}
Dog& Dog::operator=(const Dog& src)
{
	if (this != &src)
		Animal::operator=(src);
	std::cout << "Dog copy assignment operator called" << std::endl;
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Gav! Gav!" << std::endl;
}
