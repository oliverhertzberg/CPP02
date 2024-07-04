/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohertzbe <ohertzbe@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:00:40 by ohertzbe          #+#    #+#             */
/*   Updated: 2024/07/04 14:10:46 by ohertzbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
    
    // Test default constructor
    Fixed a;
    std::cout << "a: " << a << std::endl;

    // Test integer constructor
    Fixed b(10);
    std::cout << "b: " << b << std::endl;

    // Test float constructor
    Fixed c(10.5f);
    std::cout << "c: " << c << std::endl;

    // Test copy constructor
    Fixed d(b);
    std::cout << "d: " << d << std::endl;

    // Test copy assignment operator
    a = c;
    std::cout << "a after assignment: " << a << std::endl;

    // Test toFloat and toInt
    std::cout << "a as float: " << a.toFloat() << std::endl;
    std::cout << "a as int: " << a.toInt() << std::endl;

    // Test comparison operators
    std::cout << std::boolalpha; // Print bools as true/false
    std::cout << "a > b: " << (a > b) << std::endl;
    std::cout << "a < b: " << (a < b) << std::endl;
    std::cout << "a >= b: " << (a >= b) << std::endl;
    std::cout << "a <= b: " << (a <= b) << std::endl;
    std::cout << "a == b: " << (a == b) << std::endl;
    std::cout << "a != b: " << (a != b) << std::endl;

    // Test arithmetic operators
    Fixed e = b + c;
    std::cout << "e (b + c): " << e << std::endl;

    Fixed f = b - c;
    std::cout << "f (b - c): " << f << std::endl;

    Fixed g = b * c;
    std::cout << "g (b * c): " << g << std::endl;

    Fixed h = b / c;
    std::cout << "h (b / c): " << h << std::endl;

    // Test increment operators
    Fixed i = b;
    std::cout << "i before pre-increment: " << i << std::endl;
    std::cout << "i with pre-increment: " << ++i << std::endl;
    std::cout << "i before post-increment: " << i << std::endl;
    std::cout << "i with post-increment: " << i++ << std::endl;
    std::cout << "i after post-increment: " << i << std::endl;

    // Test min and max functions
    Fixed& minObj = Fixed::min(a, b);
    const Fixed& constMinObj = Fixed::min(static_cast<const Fixed&>(a), static_cast<const Fixed&>(b));
    std::cout << "Min of a and b: " << minObj << std::endl;
    std::cout << "Const min of a and b: " << constMinObj << std::endl;

    Fixed& maxObj = Fixed::max(a, b);
    const Fixed& constMaxObj = Fixed::max(static_cast<const Fixed&>(a), static_cast<const Fixed&>(b));
    std::cout << "Max of a and b: " << maxObj << std::endl;
    std::cout << "Const max of a and b: " << constMaxObj << std::endl;

}