/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohertzbe <ohertzbe@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 19:41:19 by ohertzbe          #+#    #+#             */
/*   Updated: 2024/06/25 01:37:10 by ohertzbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed {

    private:
        static const int bits = 8;
        int              fixedpoint;
        
    public:
        Fixed();
        Fixed(const int);
        Fixed(const float f);
        ~Fixed();
        Fixed(const Fixed &obj);
        Fixed&  operator=(const Fixed& obj);
        
        int     getRawBits(void) const;
        void    setRawBits(int const raw);
        int     toInt(void) const;
};

std::ostream& operator<<(std::ostream &out, const Fixed &obj);

#endif