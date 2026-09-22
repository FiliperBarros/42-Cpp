#include <iostream>
#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap joao;

    joao.attack("antonio");
    joao.takeDamage(5);
    joao.beRepaired(2);
    return (0);
}