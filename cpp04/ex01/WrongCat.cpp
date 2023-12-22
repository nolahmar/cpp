/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:55:42 by nolahmar          #+#    #+#             */
/*   Updated: 2023/12/19 16:40:01 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() :WrongAnimal("WrongCat")
{
    std::cout << this->_type << "constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << this->_type << " destructor called" << std::endl;
}

void WrongCat::makeSound() const 
{
    std::cout << "Meeeeoooooooooooooooooooow !" << std::endl;
}