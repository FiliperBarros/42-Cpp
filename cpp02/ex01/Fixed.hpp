/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 21:37:16 by frocha-b          #+#    #+#             */
/*   Updated: 2026/06/22 13:47:28 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		
		int value;
		static const int fractionalBits = 8;

	public:

		Fixed(); //initializes the fixed-point number value to 0
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		~Fixed();
		Fixed(const int number);
		Fixed(const float number);
		
		int getRawBits(void) const; //returns the raw value of the fixed-point value.
		void setRawBits(int const raw); //sets the raw value of the fixed-point number.
		float toFloat( void ) const; //converts the fixed-point value to a floating-point value.
		int toInt( void ) const; // converts the fixed-point value to an integer value
};

std::ostream& operator<<(std::ostream& out, const Fixed& obj); 