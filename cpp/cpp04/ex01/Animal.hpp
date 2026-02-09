#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		Animal(const Animal& src);
		Animal& operator=(const Animal& src);
		virtual ~Animal(); // Dynamic Binding, static binding

		virtual void makeSound() const;
		std::string getType() const;
};

#endif