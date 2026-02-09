#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include <iostream>

int main()
{
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
i->makeSound(); //will output the cat sound!
j->makeSound();
meta->makeSound();

std::cout << "--- RIGHT ANIMAL ---" << std::endl;
const Animal* cat = new Cat();
cat->makeSound();
delete cat;

std::cout << "\n--- WRONG ANIMAL ---" << std::endl;
const WrongAnimal* wCat = new WrongCat();
wCat->makeSound();
delete wCat;

return 0;
}