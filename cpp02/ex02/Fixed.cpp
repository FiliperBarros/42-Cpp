/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 11:18:24 by frocha-b          #+#    #+#             */
/*   Updated: 2026/06/25 18:12:34 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(){

	value = 0;
}

Fixed::~Fixed(){}

Fixed::Fixed(const int number){

	value = number << fractionalBits; //conversao de int para fixed point.
}

Fixed::Fixed(const float number){

	value = roundf(number * (1 << fractionalBits)); // mesmo que number * 256
}

Fixed::Fixed(const Fixed& other){

	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other){

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
	
	new_value = static_cast<float>(value) / (1 << fractionalBits); // mesmo que value / 256
	return (new_value);
}

int	Fixed::toInt( void ) const{

	int	new_value;

	new_value = this->value >> fractionalBits;
	return (new_value);
}

bool Fixed::operator>(const Fixed& other) const{

	return (this->value > other.value);
}

bool Fixed::operator<(const Fixed& other) const{

	return (this->value < other.value);
}

bool Fixed::operator>=(const Fixed& other) const{

	return (this->value >= other.value);
}

bool Fixed::operator<=(const Fixed& other) const{

	return (this->value <= other.value);
}

bool Fixed::operator==(const Fixed& other) const{

	return (this->value == other.value);
}

bool Fixed::operator!=(const Fixed& other) const{

	return (this->value != other.value);
}


Fixed Fixed::operator+(const Fixed& other) const{

	Fixed result;
	result.setRawBits(this->value + other.value);
	return (result);
}

Fixed Fixed::operator-(const Fixed& other) const{

	Fixed result;
	result.setRawBits(this->value - other.value);
	return (result);
}

Fixed Fixed::operator*(const Fixed& other) const{

	Fixed result;
	result.setRawBits((this->value * other.value) >> fractionalBits);
	return (result);
}

Fixed Fixed::operator/(const Fixed& other) const{

	Fixed result;
	result.setRawBits((this->value << fractionalBits) / other.value);
	return (result);
}

Fixed Fixed::operator++(int){

	Fixed temp(*this);
	this->value++;
	return (temp);
}

Fixed Fixed::operator--(int){

	Fixed temp(*this);
	this->value--;
	return (temp);
}

Fixed &Fixed::operator++(){

	this->value++;
	return *this;
}

Fixed &Fixed::operator--(){

	this->value--;
	return *this;
}

Fixed &Fixed::max(Fixed& firstParam, Fixed& secondParam){

	return (firstParam > secondParam) ? firstParam : secondParam;
}

Fixed &Fixed::min(Fixed& firstParam, Fixed& secondParam){

	return (firstParam < secondParam) ? firstParam : secondParam;
}

const Fixed &Fixed::max(const Fixed& firstParam, const Fixed& secondParam){

	return (firstParam > secondParam) ? firstParam : secondParam;
}

const Fixed &Fixed::min(const Fixed& firstParam, const Fixed& secondParam){

	return (firstParam < secondParam) ? firstParam : secondParam;
}

std::ostream& operator<<(std::ostream& out, const Fixed& obj){

	out << obj.toFloat();
	return out;
}