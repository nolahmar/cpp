/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:38:35 by nolahmar          #+#    #+#             */
/*   Updated: 2023/12/20 14:39:23 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() :AAnimal("Dog")
{
    std::cout <<_type << " constructor called" << std::endl;
    _brain = new Brain();
}

Dog::~Dog()
{
    std::cout <<_type << " destructor called" << std::endl;
    delete _brain;
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
       _brain = new Brain( *src._brain );
    }
    return *this;
}

void Dog::makeSound() const 
{
    std::cout << "woooooooooof! woof!" << std::endl;
}