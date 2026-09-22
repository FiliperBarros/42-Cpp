#pragma once
#include <iostream>

class   ClapTrap{
    public:
        ClapTrap(const std::string &name);
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);        
        ~ClapTrap();
    
    protected:
        std::string name;
        int hitPoints;
        int energyPoints;
        int attackDamage;

};