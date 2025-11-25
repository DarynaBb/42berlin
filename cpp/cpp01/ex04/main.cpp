#include <iostream>
#include <fstream>
#include <string>

int	error_handling(std::string message)
{
	std::cerr << message << std::endl;
	return 1;
}

int	replace(std::ifstream& infile, std::ofstream& outfile, std::string s1, std::string s2)
{
	std::string line;
	size_t found;

	if (infile.peek() == std::ifstream::traits_type::eof())
	{
		infile.close();
		outfile.close();
		return (error_handling("No permission or file is empty!"));
	}
	while(std::getline(infile, line))
	{
		found = line.find(s1);
		while (found != std::string::npos)
		{
			line = line.substr(0, found) + s2 + line.substr(found + s1.length());
			found = line.find(s1, found+s2.length());
		}
		outfile << line << std::endl;
	}
	infile.close();
	outfile.close();
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Usage: " << argv[0] << " filename s1 s2" << std::endl;
		return 1;
	}
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	std::ifstream infile(filename);
	
	if (filename.empty() || s1.empty())
		return (error_handling("Filename or s1 cannot be empty!"));
	if (!infile.is_open())
		return (error_handling("Cannot open file!"));
	std::ofstream outfile(filename +".replace");
	if (!outfile.is_open())
	{
		infile.close();
		return (error_handling("Cannot create file!"));
	}
	if (replace(infile, outfile, s1, s2))
		return (1);
	return (0);
}
