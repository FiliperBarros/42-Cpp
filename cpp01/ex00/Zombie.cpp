#include "Zombie.hpp"

Zombie::Zombie(std::string _name){
	this->_name = _name;
}

Zombie::~Zombie(){
	std::cout << this->_name << " got shot" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}