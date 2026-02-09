#include "Dog.hpp"
#include <iostream>

Dog:: Dog() : Animal()
{
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "Dog default constructor called" << std::endl;
};

Dog::Dog(const Dog& src) : Animal(src)
{
	this->brain = new Brain(*src.brain);
	// this->brain = src.brain;
	std::cout << "Dog copy constructor called" << std::endl;
}
Dog& Dog::operator=(const Dog& src)
{
	if (this != &src) {
		Animal::operator=(src);
		delete this->brain;
		this->brain = new Brain(*src.brain);
	}
	std::cout << "Dog copy assignment operator called" << std::endl;
	return *this;
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Gav! Gav!" << std::endl;
}

Brain* Dog::getBrain() const
{
	return this->brain;
}
