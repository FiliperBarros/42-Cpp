#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    ClapTrap joao;
    ScavTrap toni;

    joao.attack("antonio");
    joao.takeDamage(5);
    joao.beRepaired(2);

    toni.attack("antonio");
    toni.takeDamage(5);
    toni.beRepaired(2);
    return (0);
}