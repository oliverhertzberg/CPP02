/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohertzbe <ohertzbe@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:01:55 by ohertzbe          #+#    #+#             */
/*   Updated: 2024/07/04 14:25:20 by ohertzbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// NON-MEMBER FUNCTION
std::ostream& operator<<(std::ostream &out, const Fixed &obj) {
    
    out << obj.toFloat();
    return (out);
}

// CONSTRUCTORS AND DECONSTRUCTOR

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


// METHODS

// get fixedpoint value
 int     Fixed::getRawBits(void) const {
    return (this->fixedpoint);
 }
 
// set fixed point value
void    Fixed::setRawBits(int const raw) {
    this->fixedpoint = raw;
}

// convert fixedpoint to float
float   Fixed::toFloat(void) const {
    return (this->fixedpoint / (float)(1 << this->scale));
}

// convert fixed point to int
int     Fixed::toInt(void) const {
    return (this->fixedpoint / (1 << this->scale));
}

// operator overload methods

bool    Fixed::operator>(const Fixed& other) const {
    return (this->fixedpoint > other.getRawBits());
}

bool    Fixed::operator<(const Fixed& other) const {
    return (this->fixedpoint < other.getRawBits());
}

bool    Fixed::operator>=(const Fixed& other) const {
    return (this->fixedpoint >= other.getRawBits());
}

bool    Fixed::operator<=(const Fixed& other) const {
    return (this->fixedpoint <= other.getRawBits());
}

bool    Fixed::operator==(const Fixed& other) const {
    return (this->fixedpoint == other.getRawBits());
}

bool    Fixed::operator!=(const Fixed& other) const {
    return (this->fixedpoint != other.getRawBits());
}

Fixed    Fixed::operator+(const Fixed& other) const {
    Fixed result;
    
    result.setRawBits(this->fixedpoint + other.getRawBits());
    return (result);
}

Fixed    Fixed::operator-(const Fixed& other) const {
    Fixed result;
    
    result.setRawBits(this->fixedpoint - other.getRawBits());
    return (result);
}

Fixed    Fixed::operator*(const Fixed& other) const {
    Fixed result;
    
    result.setRawBits((this->fixedpoint * other.getRawBits()) >> this->scale);
    return (result);
}

Fixed    Fixed::operator/(const Fixed& other) const {
    Fixed result;
    
    result.setRawBits((this->fixedpoint << this->scale) / other.getRawBits());
    return (result);
}

Fixed&  Fixed::operator++(void) {
    this->fixedpoint += 1;
    return (*this);
}

Fixed   Fixed::operator++(int) {
    Fixed temp = *this;
    this->fixedpoint += 1;
    return (temp);
}

Fixed&    Fixed::min(Fixed& obj1, Fixed& obj2) {
    return (obj1.getRawBits() <= obj2.getRawBits() ? obj1 : obj2);
}

const Fixed&    Fixed::min(const Fixed& obj1, const Fixed& obj2) {
    return (obj1.getRawBits() <= obj2.getRawBits() ? obj1 : obj2);   
}

Fixed&    Fixed::max(Fixed& obj1, Fixed& obj2) {
    return (obj1.getRawBits() >= obj2.getRawBits() ? obj1 : obj2);
}

const Fixed&    Fixed::max(const Fixed& obj1, const Fixed& obj2) {
    return (obj1.getRawBits() >= obj2.getRawBits() ? obj1 : obj2);   
}