#include <iostream>
#include <cctype>
// preprocesses statements

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}

	for (int i = 1; i < argc; i++)
	{
		std::string text = argv[i];
		for (size_t j = 0; j < text.length(); j++)
		{
			std::cout << static_cast<char>(std::toupper(text[j]));
		}
	}
	std::cout << std::endl;
	return (0);
}