/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:22:02 by nolahmar          #+#    #+#             */
/*   Updated: 2023/12/25 13:15:11 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(){
    std::cout <<_type << "constructor called" << std::endl;
}

AAnimal::AAnimal(std::string type) : _type(type)
{
    std::cout << "AAnimal " <<_type << " constructor called" << std::endl;
}

AAnimal::~AAnimal()
{
    std::cout << "AAnimal destructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& src)
{
    std::cout << "AAnimal copy destructor called" << std::endl;
    *this = src;
}

AAnimal& AAnimal::operator=(const AAnimal& rhs)
{
    std::cout << "AAnimal copy constructor called" << std::endl;
    if (this != &rhs) {
        _type = rhs._type;
    }
    return *this;
}

std::string    AAnimal::getType( void ) const
{
    return _type;
}