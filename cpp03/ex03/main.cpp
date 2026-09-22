#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
    ClapTrap joao("joao");
    std::cout <<"\n";;

    ScavTrap toni("toni");
    std::cout <<"\n";;

    FragTrap bob("Bob");
    std::cout <<"\n";;

    joao.attack("antonio");
    joao.takeDamage(5);
    joao.beRepaired(2);
    std::cout <<"\n";;
    
    toni.attack("antonio");
    toni.takeDamage(5);
    toni.beRepaired(2);
    std::cout <<"\n";;

    bob.attack("antonio");
    bob.takeDamage(5);
    bob.beRepaired(2);    
    bob.highFivesGuys();
    std::cout <<"\n";;
    return (0);
}