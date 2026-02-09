#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

#include <iostream>

int main()
{
	std::cout << "=== Constructor and destructor tests ===" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;
	delete i;
	std::cout << "=== End of constructor and destructor tests ===" << std::endl;

	std::cout << "\n=== Array test (half Dogs, half Cats) ===" << std::endl;
	const int arraySize = 6;
	Animal* animals[arraySize];
	
	for (int i = 0; i < arraySize; i++)
	{
		if (i < arraySize / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	
	std::cout << "\n=== Animals making sounds ===" << std::endl;
	for (int i = 0; i < arraySize; i++)
	{
		std::cout << "Animal " << i << " (" << animals[i]->getType() << "): ";
		animals[i]->makeSound();
	}
	
	std::cout << "\n=== Deleting animals ===" << std::endl;
	for (int i = 0; i < arraySize; i++)
	{
		delete animals[i];
	}

	std::cout << "\n=== Deep copy test ===" << std::endl;
	Dog basic;
	basic.getBrain()->setIdea(0, "Original idea");
	{
		std::cout << "--- Creating tmp copy in a new scope ---" << std::endl;
		Dog tmp = basic;
		std::cout << "Tmp idea: " << tmp.getBrain()->getIdea(0) << std::endl;
		std::cout << "--- End of scope, tmp will be destroyed ---" << std::endl;
	}
	std::cout << "Basic idea after tmp is gone: " << basic.getBrain()->getIdea(0) << std::endl;
	std::cout << "=== End of deep copy test ===" << std::endl;

	return 0;
}