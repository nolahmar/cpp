/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:55:42 by nolahmar          #+#    #+#             */
/*   Updated: 2023/12/25 11:41:44 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() :WrongAnimal("WrongCat")
{
    std::cout <<_type << " constructed" << std::endl;
}

WrongCat::WrongCat(const WrongCat& src)
{
    *this = src;    
}

WrongCat& WrongCat::operator=( const WrongCat& src )
{
    std::cout << "WrongCat copy called" << std::endl;
    if (this != &src)
    {
       _type = src._type;
    }
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout <<_type << " destructed" << std::endl;
}

void WrongCat::makeSound() const 
{
    std::cout << "Meeeeoooooooooooooooooooow !" << std::endl;
}