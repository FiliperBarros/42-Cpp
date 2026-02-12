#include "PhoneBook.hpp"
#include <iomanip>
#include <iostream>

PhoneBook::PhoneBook(){
	this->_CurrentIndex = 0;
	this->_num_Contacts = 0;
}

PhoneBook::~PhoneBook(){
	
}
std::string PhoneBook::truncateString(std::string str)
{
	if (str.size() > 10)
		return (str.substr(0, 9) + '.');
	return (str);
}

int		PhoneBook::all_digit(std::string str)
{
	int	i = 0;
	while (str[i])
	{
		if  (!std::isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	PhoneBook::addContact()
{
	std::string	input;

	int	i = this->_CurrentIndex % 8;
	
	while (input.empty())
	{
		std::cout << "Enter First Name: ";
		if (!std::getline(std::cin, input))
			return ;
	}	
	this->_Contacts[i].set_firstName(input);
	input.clear();
	
	while (input.empty())
	{
		std::cout << "Enter Last Name: ";
		if (!std::getline(std::cin, input))
			return ;
	}	
	this->_Contacts[i].set_lastName(input);
	input.clear();
	
	while (input.empty())
	{
		std::cout << "Enter _nickName: ";
		if (!std::getline(std::cin, input))
			return ;
	}	
	this->_Contacts[i].set_nickName(input);
	input.clear();
	
	while (input.empty() || !PhoneBook::all_digit(input))
	{
		std::cout << "Enter Phone Number: ";

		if (!std::getline(std::cin, input))
			return ;
	}	
	this->_Contacts[i].set_phoneNumber(input);
	input.clear();
	
	while (input.empty())
	{
		std::cout << "Enter Darkest Secret: ";
		if (!std::getline(std::cin, input))
			return ;
	}	
	this->_Contacts[i].set_secret(input);
	input.clear();
	
	this->_CurrentIndex++;
	this->_num_Contacts++;
}

void	PhoneBook::searchContact()
{
	if (this->_num_Contacts == 0)
	{
		std::cout << "Phonebook is empty" << std::endl;
		return ;
	}

	std::cout << "|" << std::setw(10)<< "Index" << "|"; 
	std::cout << std::setw(10)<< "First Name"<< "|";  
	std::cout << std::setw(10)<< "Last Name"<< "|";  
	std::cout << std::setw(10)<< "_nickName"<<  "|\n";
	
	if (this->_num_Contacts > 8)
		this->_num_Contacts = 8;
		
	for (int i = 0; i < this->_num_Contacts ; i++)
	{
		std::cout << "|" << std::setw(10) << i << '|';
		std::cout << std::setw(10) << PhoneBook::truncateString(this->_Contacts[i].get_firstName()) << "|";
		std::cout << std::setw(10) << PhoneBook::truncateString(this->_Contacts[i].get_lastName()) << "|";
		std::cout << std::setw(10) << PhoneBook::truncateString(this->_Contacts[i].get_nickName()) << "|\n";
	}

	std::string	input;
	std::cout << "Input index for more details : " << std::endl;
	if (!std::getline(std::cin, input) || input.empty())
		return ;

	
	if (input.length() == 1 && PhoneBook::all_digit(input))
	{
		int	index = input[0] - '0';
		if (index < this->_num_Contacts)
		{
			std::cout << "First Name: " << this->_Contacts[index].get_firstName() << std::endl;
			std::cout << "Last Name:  " << this->_Contacts[index].get_lastName() << std::endl;
			std::cout << "_nickName    " << this->_Contacts[index].get_nickName() << std::endl;
			std::cout << "Phone:      " << this->_Contacts[index].get_phoneNumber() << std::endl;
			std::cout << "Secret:     " << this->_Contacts[index].get_secret() << std::endl;
		}
		else
			std::cout << "Index out of range\n";
	}
	else
		std::cout << "Error: Invalid index input." << std::endl;
}
