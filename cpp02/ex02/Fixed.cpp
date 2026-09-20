#include "Fixed.hpp"
#include <cmath>
#include <iostream>

Fixed::Fixed() : rawNumber(0){
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) {
    std::cout << "Int constructor called" << std::endl;
    this->rawNumber = value * 256;
}

Fixed::Fixed(const float value) {
    std::cout << "Float constructor called" << std::endl;
    this->rawNumber = roundf(value * 256);  
}
Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src) :rawNumber(src.rawNumber){
    std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &src){
    std::cout << "Copy assignment operator called" << std::endl;
    this->rawNumber = src.rawNumber;
    return(*this);
}

std::ostream &operator<<(std::ostream &out, const Fixed &value) {
    out << value.toFloat();
    return out;
}

int Fixed::getRawBits( void ) const{
    std::cout << "getRawBits member function called" << std::endl;
    return(this->rawNumber);
}

void Fixed::setRawBits( int const raw ){
    std::cout << "setRawBits member function called" << std::endl;
    this->rawNumber = raw;
}

float Fixed::toFloat( void ) const{
    return (this->rawNumber / 256);
}

int Fixed::toInt( void ) const{
    return (roundf(this->rawNumber / 256));
};





