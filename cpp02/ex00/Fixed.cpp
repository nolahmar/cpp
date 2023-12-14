/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noni <noni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:14:41 by noni              #+#    #+#             */
/*   Updated: 2023/11/28 14:23:29 by noni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixed_value(0) 
{
    std::cout << "Fixed Default Constructor called" << std::endl;
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
    // Vérifie l'auto-affectation
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

// Fonction d'accès pour définir la valeur brute
void Fixed::setRawBits(int const raw) 
{
    std::cout << "setRawBits member function called" << std::endl;
    _fixed_value = raw;
}


