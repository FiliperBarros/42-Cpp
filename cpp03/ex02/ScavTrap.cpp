#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(const std::string name)
:ClapTrap(name)
{
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;

    std::cout << "ScavTrap Constructor called!" << std::endl;
}

ScavTrap::~ScavTrap(){
    std::cout << "ScavTrap Destructor called!" << std::endl;

}

void ScavTrap::attack(const std::string& target){
    if (!this->hitPoints || !this->energyPoints)
        return ;
    this->energyPoints--;
    std::cout << "ScavTrap " << this->name << " attacks " << target << 
        " causing " << this->attackDamage << " points of damage!" << std::endl;

}
void ScavTrap::guardGate(){
    std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}
