#include <iostream>
#include "Harl.hpp"

int main(int ac, char **argv)
{
    if (ac != 2)
    {
        std::cerr << "Usage: ./harlFilter <DEBUG|INFO|WARNING|ERROR>" << std::endl;
        return (1);
    }
    Harl harl;
    harl.complain(argv[1]);
    return (0);
}
