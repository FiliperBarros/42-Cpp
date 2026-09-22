#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string name)
:ClapTrap(name)
{
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;

    std::cout << "FragTrap Constructor called!" << std::endl;

}

FragTrap::~FragTrap(){
    std::cout << "FragTrap Destructor called!" << std::endl;

}

void FragTrap::highFivesGuys(){
    std::cout << "FragTrap " << this->name
              << " wants a high five!" << std::endl;
}