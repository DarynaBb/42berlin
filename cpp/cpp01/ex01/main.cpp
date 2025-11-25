#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int main()
{
	int N = 7;
	Zombie* zombies = zombieHorde(N, "Zombie from horde");
	for (int i = 0; i < N; i++)
		zombies->announce();
	delete[] zombies;
	return 0;
}