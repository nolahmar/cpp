/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:38:35 by nolahmar          #+#    #+#             */
/*   Updated: 2023/12/20 14:08:22 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() :Animal("Dog")
{
    std::cout <<_type << "constructor called" << std::endl;
}

Dog::~Dog()
{
    std::cout <<_type << " destructor called" << std::endl;
}

Dog::Dog( const Dog& src )
{
    *this = src;
}

Dog& Dog::operator=( const Dog& src )
{
    std::cout << "Dog copy called." << std::endl;
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