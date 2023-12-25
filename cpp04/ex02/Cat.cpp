/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:38:19 by nolahmar          #+#    #+#             */
/*   Updated: 2023/12/25 13:17:56 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() :AAnimal("Cat")
{
    _brain = new Brain();
    std::cout <<_type << " constructed" << std::endl;
}

Cat::~Cat()
{
    delete _brain;
    std::cout <<_type << " destructed" << std::endl;
}

Cat::Cat( const Cat& src )
{
    _brain = new Brain(*src._brain);
    *this = src;
}

Cat& Cat::operator=( const Cat& src )
{
    std::cout << "Cat copy called" << std::endl;
    if (this != &src)
    {
       _type = src._type;
       delete _brain;
       _brain = new Brain(*src._brain);
    }
    return *this;
}

void Cat::makeSound() const 
{
    std::cout << "Meeeeoooooooooooooooooooow !" << std::endl;
}