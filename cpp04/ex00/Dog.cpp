/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:38:35 by nolahmar          #+#    #+#             */
/*   Updated: 2023/12/25 11:35:03 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() :Animal("Dog")
{
    std::cout <<_type << " constructed" << std::endl;
}

Dog::~Dog()
{
    std::cout <<_type << " destructed" << std::endl;
}

Dog::Dog( const Dog& src )
{
    *this = src;
}

Dog& Dog::operator=( const Dog& src )
{
    std::cout << "Dog copy called" << std::endl;
    if (this != &src)
    {
        _type = src._type;
    }
    return *this;
}

void Dog::makeSound() const 
{
    std::cout << "woooooooooof! woof!" << std::endl;
}