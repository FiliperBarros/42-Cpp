#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class	PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();
		void		addContact();
		void		searchContact();
		std::string	truncateString(std::string);
		int			all_digit(std::string str);


	private:
		Contact	_Contacts[8];
		int		_num_Contacts;
		int		_CurrentIndex;

};

#endif