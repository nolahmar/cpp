/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:38:35 by nolahmar          #+#    #+#             */
/*   Updated: 2023/12/25 13:18:23 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() :AAnimal("Dog")
{
    _brain = new Brain();
    std::cout <<_type << " constructed" << std::endl;
}

Dog::~Dog()
{
    delete _brain;
    std::cout <<_type << " destructed" << std::endl;
}

Dog::Dog( const Dog& src )
{
    _brain = new Brain(*src._brain);
    *this = src;
}

Dog& Dog::operator=( const Dog& src )
{
    std::cout << "Dog copy called" << std::endl;
    if (this != &src)
    {
        _type = src._type;
        delete _brain;
        _brain = new Brain(*src._brain);
    }
    return *this;
}

void Dog::makeSound() const 
{
    std::cout << "woooooooooof! woof!" << std::endl;
}