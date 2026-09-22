#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) : _name(name) , _weapon(NULL)
{}

HumanB::~HumanB(void){}

void	HumanB::attack(void){
	if (this->_weapon == NULL)
		return ;
	std::cout 	<< this->_name << " attacks with their " 
				<< 	this->_weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon){
	this->_weapon = &weapon;
}
