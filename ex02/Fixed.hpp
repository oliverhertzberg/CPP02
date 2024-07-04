/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohertzbe <ohertzbe@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:01:38 by ohertzbe          #+#    #+#             */
/*   Updated: 2024/07/04 14:15:48 by ohertzbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed {

    private:
        static const int scale = 8;
        // with a 8 fractional bits we get:
        // 0000 0000 0000 0000 0000 0000 . 0000 0000
        // the 8 rightmost digits will be our decimal value
        int              fixedpoint;
        
    public:
        // constructors and deconstructor
        Fixed();
        Fixed(const int);
        Fixed(const float f);
        ~Fixed();
        Fixed(const Fixed &obj);
        Fixed&  operator=(const Fixed& obj);
        
        // get or set fixed point value
        int     getRawBits(void) const;
        void    setRawBits(int const raw);
        
        // fixed to float and fixed to int
        float   toFloat(void) const;
        int     toInt(void) const;

        // public overload methods
        // >, <, >=, <=, ==, !=
        bool    operator>(const Fixed& other) const;
        bool    operator<(const Fixed& other) const;
        bool    operator>=(const Fixed& other) const;
        bool    operator<=(const Fixed& other) const;
        bool    operator==(const Fixed& other) const;
        bool    operator!=(const Fixed& other) const;
        // +, -, *, /
        Fixed    operator+(const Fixed& other) const;
        Fixed    operator-(const Fixed& other) const;
        Fixed    operator*(const Fixed& other) const;
        Fixed    operator/(const Fixed& other) const;
        // ++, --
        Fixed&    operator++(void);
        Fixed     operator++(int);
        // min and max methods
        static Fixed&          min(Fixed& obj1, Fixed& obj2);
        static const Fixed&    min(const Fixed& obj1, const Fixed& obj2);
        static Fixed&          max(Fixed& obj1, Fixed& obj2);
        static const Fixed&    max(const Fixed& obj1, const Fixed& obj2);
};

std::ostream& operator<<(std::ostream &out, const Fixed &obj);

#endif