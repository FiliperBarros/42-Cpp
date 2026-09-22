#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string &name)
:ScavTrap(name),FragTrap(name), name(name)
{
    this->hitPoints = FragTrap::hitPoints;
    this->energyPoints = ScavTrap::energyPoints;
    this->attackDamage = FragTrap::attackDamage;

    std::cout << "DiamondTrap Constructor called!" << std::endl;

}

DiamondTrap::DiamondTrap()
{
    std::cout << "DiamondTrap Destructor called!" << std::endl;

}

void DiamondTrap::whoAmI()
{
    std::cout << "My name is " << this->name << 
        "and my ClapTrap name is " << this->ClapTrapName << std::endl;
}