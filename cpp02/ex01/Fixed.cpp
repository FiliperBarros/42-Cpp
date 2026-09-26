/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 11:18:24 by frocha-b          #+#    #+#             */
/*   Updated: 2026/06/22 14:34:14 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(){
	
	std::cout << "Default constructor called" << std::endl;
	value = 0;
}

Fixed::~Fixed(){

	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int number){

	std::cout << "Int constructor called" << std::endl;
	value = number << fractionalBits;
}

Fixed::Fixed(const float number){

	std::cout << "Float constructor called" << std::endl;
	value = roundf(number * (1 << fractionalBits));
}

Fixed::Fixed(const Fixed& other){

	std::cout << "Copy contructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other){

	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		value = other.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const{

	return this->value;
}

void Fixed::setRawBits(int const raw){

	this->value = raw;
}

float Fixed::toFloat( void ) const{

	float	new_value;
	
	new_value = static_cast<float>(value) / (1 << fractionalBits);
	return (new_value);
}

int	Fixed::toInt( void ) const{

	int	new_value;

	new_value = this->value >> fractionalBits;
	return (new_value);
}


std::ostream& operator<<(std::ostream& out, const Fixed& obj){

	out << obj.toFloat();
	return out;
}