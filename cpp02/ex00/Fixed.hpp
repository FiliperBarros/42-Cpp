/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 21:37:16 by frocha-b          #+#    #+#             */
/*   Updated: 2026/06/21 22:24:34 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Fixed
{
	private:
		
		int value;
		static const int fractional = 8;

	public:

		Fixed(); //initializes the fixed-point number value to 0
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		~Fixed();
		
		int getRawBits(void) const; //that returns the raw value of the fixed-point value.
		void setRawBits(int const raw); //that sets the raw value of the fixed-point number.
};