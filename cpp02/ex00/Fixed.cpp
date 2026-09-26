/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 21:54:50 by frocha-b          #+#    #+#             */
/*   Updated: 2026/06/22 13:00:59 by frocha-b         ###   ########.fr       */
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

	std::cout << "getRawbits member function called" << std::endl;
	return this->value;
}

void Fixed::setRawBits(int const raw){

	this->value = raw;
}