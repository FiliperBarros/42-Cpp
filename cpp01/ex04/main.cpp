#include <iostream>
#include <fstream>
#include <string>

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "Usage: ./sed <filename> <s1> <s2>" << std::endl;
		return 1;
	}

	std::string filename = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];
	if(s1.empty())
	{
		std::cerr << "s1 cannot be empty" << std::endl;
		return(1);
	}


	std::ifstream input(filename.c_str());
	if(!input.is_open())
	{
		std::cerr << "Could not open input file" << std::endl;
		return 1;
	}


	std::string outputName = filename + ".replace";
	std::ofstream output(outputName.c_str());
	if (!output.is_open())
	{
		std::cerr << "Could not create output file" << std::endl;
		return (1);
	}
	
	
	std::string content;
	char character;
	
	while(input.get(character))
		content += character;

	
	size_t start = 0;
	size_t	found;
	while (true)
	{
		found = content.find(s1, start);
	
		if (found == std::string::npos)
		{
			output << content.substr(start);
			return (0);
		}

		output << content.substr(start, found - start);
		output << s2;
		start = found + s1.length();
	}
	return (0);
}