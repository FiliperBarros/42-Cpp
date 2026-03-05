#include "Zombie.hpp"

int	main(void)
{
	int	n = 5;
	Zombie *z;
	
	z = zombieHorde(n, "joao");
	for(int i = 0; i < n; i++)
		z[i].announce();
	delete[] z;
}