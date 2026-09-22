#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
    public:
        DiamondTrap(const std::string &name);
        ~DiamondTrap();

        void whoAmI();
    

    private:
        std::string name;
}