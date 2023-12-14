/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noni <noni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 00:53:19 by noni              #+#    #+#             */
/*   Updated: 2023/11/28 13:35:25 by noni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
    private :
            int _fixed_value;
            static const int _fract_bits = 8;
    public :
            Fixed();
            Fixed(const Fixed& copy);
            Fixed(const int n);
            Fixed(const float n);
            ~Fixed();
            Fixed   &operator=(const Fixed &src);
            int     getRawBits( void ) const;
            void    setRawBits( int const raw );
            float   toFloat( void ) const;
            int     toInt( void ) const;
            
};
std::ostream &operator<<(std::ostream &os, Fixed const &fixed);

#endif
