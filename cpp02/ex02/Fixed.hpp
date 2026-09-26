/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 21:37:16 by frocha-b          #+#    #+#             */
/*   Updated: 2026/06/26 14:40:41 by frocha-b         ###   ########.fr       */
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

		Fixed();
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		~Fixed();
		Fixed(const int number);
		Fixed(const float number);
		
		int getRawBits(void) const;
		void setRawBits(int const raw);
		
		float toFloat( void ) const;
		int toInt( void ) const;
		
		bool operator>(const Fixed& other) const;
		bool operator<(const Fixed& other) const;
		bool operator>=(const Fixed& other) const;
		bool operator<=(const Fixed& other) const;
		bool operator==(const Fixed& other) const;
		bool operator!=(const Fixed& other) const;

		Fixed operator+(const Fixed& other) const;
		Fixed operator-(const Fixed& other) const;
		Fixed operator*(const Fixed& other) const;
		Fixed operator/(const Fixed& other) const;

		Fixed operator++(int);
		Fixed operator--(int);
		Fixed &operator++(void);
		Fixed &operator--(void);

		static Fixed &max(Fixed& firstParam, Fixed& secondParam);
		static Fixed &min(Fixed& firstParam, Fixed& secondParam);
		static const Fixed &max(const Fixed& firstParam, const Fixed& secondParam);
		static const Fixed &min(const Fixed& firstParam, const Fixed& secondParam);
};

std::ostream& operator<<(std::ostream& out, const Fixed& obj);