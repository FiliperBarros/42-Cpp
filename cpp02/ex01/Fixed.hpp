#pragma once
#include <iostream>`

class   Fixed{
    public:
        Fixed();
        Fixed(const int value);
        Fixed(const float value);
        Fixed(const Fixed &src);
        Fixed &operator=(const Fixed &src);
        ~Fixed();
        
        int getRawBits( void ) const;
        void setRawBits( int const raw );

        float toFloat( void ) const;
        int toInt( void ) const;
        
        private:
        int rawNumber;
        static const int   fractionalBits;
        
    };
    
std::ostream &operator<<(std::ostream &out, const Fixed &value);