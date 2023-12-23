/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 11:47:27 by nolahmar          #+#    #+#             */
/*   Updated: 2023/12/23 12:09:34 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{

}

Ice::Ice(Ice const & src)
{
    *this = src;
}

Ice&   Ice::operator=(const Ice& rhs) {
    if (this != &rhs)
        _type = rhs._type;
    return *this;
}

Ice::~Ice()
{
    
}

AMateria* Ice::clone() const
{
    return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

