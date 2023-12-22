/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 11:53:08 by nolahmar          #+#    #+#             */
/*   Updated: 2023/12/22 15:54:50 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{

}

Cure::Cure(Cure const & src) : AMateria("cure")
{
    *this = src;
}

Cure& Cure::operator=( const Cure& rhs ) {
    if (this != &rhs)
    {
       _type = rhs._type;
    }
    return *this;
}

Cure::~Cure()
{

}

AMateria* Cure::clone() const
{
    return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}