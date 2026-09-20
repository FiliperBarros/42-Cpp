#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : rawNumber(0){
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src) : rawNumber(src.rawNumber){
    std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &src){
    std::cout << "Copy assignment operator called" << std::endl;
    this->rawNumber = src.rawNumber;
    return (*this);
}
int Fixed::getRawBits(void) const{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->rawNumber);
}

void Fixed::setRawBits(int const raw){
    std::cout << "setRawBits member function called" << std::endl;
    this->rawNumber = raw;
}
