#include "Harl.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: [program name] [level]" << std::endl;
		return (1);
	}
	Harl h;
	h.filter(argv[1]);
	return 0;
}