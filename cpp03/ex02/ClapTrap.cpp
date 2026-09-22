#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string &name)
    : name(name), hitPoints(10), energyPoints(10),attackDamage(0)
{
    std::cout << "ClapTrap Constructor called!" << std::endl;
}

ClapTrap::~ClapTrap(){
    std::cout << "ClapTrap Destructor called!" << std::endl;
}
void ClapTrap::attack(const std::string& target){
    if (this->energyPoints && this->hitPoints)
    {
        this->energyPoints--;
        std::cout << "ClapTrap " << this->name << " attacks " << target << 
            " causing " << this->attackDamage << " points of damage!" << std::endl;
    }
}

 void ClapTrap::takeDamage(unsigned int amount){
    if (this->hitPoints && amount)
        std::cout << "ClapTrap " << this->name << " takes " << amount << 
            " points of damage!" << std::endl;
 }

void ClapTrap::beRepaired(unsigned int amount){
    if (amount)
    {
        this->hitPoints+= amount;
        this->energyPoints--;
        std::cout << "ClapTrap " << this->name << " repairs itself " << amount << " hit points!"<<std::endl;
    }
}