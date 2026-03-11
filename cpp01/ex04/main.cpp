#include <iostream>
#include <fstream>
#include <string>

int	main(int ac, char **av)
{
	if (ac == 4)
	{
		std::string filename = av[1];
		std::fstream inputFile(av[1]);

		if (!inputFile.is_open()){
			std::cerr << "Could not open the file" << std::endl;
		}

		std::ofstream outputFile(filename + ".replace");
	}
	else
		std::cout << "Invalid args" << std::endl;

}