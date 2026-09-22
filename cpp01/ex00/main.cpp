#include "Zombie.hpp"

int	main(void)
{
	Zombie a("Zombie 1");
	a.announce();
	Zombie *b = newZombie("zombie 2");
	b->announce();
	randomChump("zombie 3");
	delete(b);
}
