/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohertzbe <ohertzbe@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 19:41:17 by ohertzbe          #+#    #+#             */
/*   Updated: 2024/06/25 01:31:12 by ohertzbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// constructors and the destructor

Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    this->fixedpoint = 0;
}

Fixed::Fixed(const Fixed& obj) {
    std::cout << "Copy constructor called" << std::endl;
    this->fixedpoint = obj.fixedpoint;
}

Fixed& Fixed::operator=(const Fixed& obj) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &obj) { // prevent self assignment
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