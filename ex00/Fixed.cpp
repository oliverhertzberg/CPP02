/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohertzbe <ohertzbe@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 19:41:17 by ohertzbe          #+#    #+#             */
/*   Updated: 2024/06/24 22:10:54 by ohertzbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// constructors and the destructor

Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    this->fixedpoint_value = 0;
}

Fixed::Fixed(const Fixed& obj) {
    std::cout << "Copy constructor called" << std::endl;
    this->fixedpoint_value = obj.fixedpoint_value;
}

Fixed& Fixed::operator=(const Fixed& obj) {
    std::cout << "Copy assignement operator called" << std::endl;
    return (*this);
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}


// methods

 int     Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return (this->fixedpoint_value);
 }

 
void    Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    this->fixedpoint_value = raw;
}