/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:38:19 by nolahmar          #+#    #+#             */
/*   Updated: 2023/12/20 14:18:55 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() :Animal("Cat")
{
    std::cout << _type << " constructor called" << std::endl;
    _brain = new Brain();
}

Cat::~Cat()
{
    std::cout << _type << " destructor called" << std::endl;
    delete _brain;
}

Cat::Cat( const Cat& src )
{
    *this = src;
}

Cat& Cat::operator=( const Cat& src )
{
    std::cout << "Cat copy called." << std::endl;
    if (this != &src)
    {
       _type = src._type;
       _brain = new Brain( *src._brain );
    }
    return *this;
}

void Cat::makeSound() const 
{
    std::cout << "Meeeeoooooooooooooooooooow !" << std::endl;
}