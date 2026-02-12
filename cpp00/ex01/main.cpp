#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	myPhoneBook;
	std::string	command;

	while (1)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, command))
			return (1);
		if (command == "ADD")
			myPhoneBook.addContact();
		else if (command == "SEARCH")
			myPhoneBook.searchContact();
		else if (command == "EXIT")
			break;
	}
	return (0);

}