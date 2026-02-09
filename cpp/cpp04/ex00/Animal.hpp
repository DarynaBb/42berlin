#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal {
	protected:
		std::string type;
	public:
		Animal();
		Animal(const Animal& src);
		Animal& operator=(const Animal& src);
		~Animal();

		virtual void makeSound();
		std::string getType() const;
};

#endif