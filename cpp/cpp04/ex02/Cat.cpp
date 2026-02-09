#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal()
{
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& src) : Animal(src)
{
	this->brain = new Brain(*src.brain); //otherwise shared thoughts, double free
	std::cout << "Cat copy constructor called" << std::endl;
}
Cat& Cat::operator=(const Cat& src)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	// otherwise shared thoughts, double free, memory leak
	if (this != &src)
	{
		Animal::operator=(src);
		delete this->brain;
		this->brain = new Brain(*src.brain);
	}
	return *this;
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Miau! Miau!" << std::endl;
}

Brain* Cat::getBrain() const
{
	return this->brain;
}