/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noni <noni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 23:29:49 by noni              #+#    #+#             */
/*   Updated: 2023/11/29 15:37:15 by noni             ###   ########.fr       */
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
    // Comparison Operators
		    bool operator>(Fixed fixed)const;
		    bool operator<(Fixed fixed)const;
		    bool operator>=(Fixed fixed)const;
		    bool operator<=(Fixed fixed)const;
		    bool operator==(Fixed fixed)const;
		    bool operator!=(Fixed fixed)const;

	// Arithmetic Operators
		    float operator+(Fixed fixed)const;
		    float operator-(Fixed fixed)const;
		    float operator*(Fixed fixed)const;
		    float operator/(Fixed fixed)const;

	// pre-increment Operators
		    Fixed operator++();
		    Fixed operator--();
	// post-increment Operators
		    Fixed operator++(int);
		    Fixed operator--(int);

            int     getRawBits( void ) const;
            void    setRawBits( int const raw );
            float   toFloat( void ) const;
            int     toInt( void ) const;
            static Fixed &min(Fixed &first, Fixed &second);
		    static const Fixed &min(Fixed const &first, Fixed const &second);
		    static Fixed &max(Fixed &first, Fixed &second);
		    static const Fixed &max(Fixed const &first, const Fixed &second);
            
};
std::ostream	&operator<<(std::ostream &o, Fixed const &fixed);

#endif
