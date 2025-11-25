#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int	main()
{
	Zombie *heapZombie = newZombie("Tom");
	heapZombie->announce();
	delete heapZombie;

	randomChump("Jerry");
	return 0;
}