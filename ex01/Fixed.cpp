/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohertzbe <ohertzbe@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 19:41:17 by ohertzbe          #+#    #+#             */
/*   Updated: 2024/07/03 12:43:36 by ohertzbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// constructors and the destructor

Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    this->fixedpoint = 0;
}

Fixed::Fixed(const int i) {
    std::cout << "Int constructor called" << std::endl;
    this->fixedpoint = i << this->scale;
}

Fixed::Fixed(const float f) {
    std::cout << "Float constructor called" << std::endl;
    this->fixedpoint = f * ((float)(1 << this->scale));
}

Fixed::Fixed(const Fixed& obj) {
    std::cout << "Copy constructor called" << std::endl;
    this->fixedpoint = obj.fixedpoint;
}

Fixed& Fixed::operator=(const Fixed& obj) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &obj) {
        this->fixedpoint = obj.fixedpoint;
    }
    return (*this);
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}


// methods

 int     Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return (this->fixedpoint);
 }

 
void    Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    this->fixedpoint = raw;
}

float   Fixed::toFloat(void) const {
    return (this->fixedpoint / (float)(1 << this->scale));
}

int     Fixed::toInt(void) const {
    return (this->fixedpoint / (1 << this->scale));
}

std::ostream& operator<<(std::ostream &out, const Fixed &obj) {
    
    out << obj.toFloat();
    return (out);
}
