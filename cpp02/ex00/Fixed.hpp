/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noni <noni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:14:56 by noni              #+#    #+#             */
/*   Updated: 2023/11/27 00:21:59 by noni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
    private :
            int _fixed_value;
            static const int _fract_bits = 8;
    public :
            Fixed();
            Fixed(const Fixed& copy);
            ~Fixed();
            Fixed &operator=(const Fixed &src);
            int     getRawBits( void ) const;
            void    setRawBits( int const raw );
};

#endif
