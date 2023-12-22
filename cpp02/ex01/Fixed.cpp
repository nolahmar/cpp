/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 00:53:05 by noni              #+#    #+#             */
/*   Updated: 2023/12/15 10:48:15 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed():_fixed_value(0)
{
    std::cout << "Fixed Default Constructor called" << std::endl;
}

Fixed::Fixed(const int n)
{
    std::cout << "Fixed Int Constructor called" << std::endl;
	this->_fixed_value = n << this->_fract_bits;
}

Fixed::Fixed(const float n)
{
	std::cout << "Fixed Float Constructor called" << std::endl;
	this->_fixed_value = roundf(n * (1 << this->_fract_bits));
}

Fixed::Fixed(const Fixed& copy) : _fixed_value(copy._fixed_value)
{
    std::cout << "Fixed Copy Constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Fixed Deconstructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& src) 
{
    std::cout << "Fixed Assignation operator called" << std::endl;
    if (this != &src) {
        // Copie les valeurs depuis l'objet source vers l'objet actuel
        this->_fixed_value = src._fixed_value;
    }
    return *this;
}

int Fixed::getRawBits() const 
{
    std::cout << "getRawBits member function called" << std::endl;
    return _fixed_value;
}

void Fixed::setRawBits(int const raw) 
{
    std::cout << "setRawBits member function called" << std::endl;
    _fixed_value = raw;
}

float	Fixed::toFloat(void)const
{
	return ((float)this->_fixed_value / (float)(1 << this->_fract_bits));
}

int	Fixed::toInt(void)const
{
	return (this->_fixed_value >> this->_fract_bits);
}

std::ostream	&operator<<(std::ostream &o, Fixed const &fixed)
{
	o << fixed.toFloat();
	return (o);
}
