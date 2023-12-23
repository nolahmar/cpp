/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 11:11:28 by nolahmar          #+#    #+#             */
/*   Updated: 2023/12/23 11:01:10 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
    
}

AMateria::AMateria(std::string const &type) : _type(type)
{
    std::cout << "AMateria " << _type << " created" << std::endl;
}

AMateria::~AMateria()
{
    
}

AMateria::AMateria(AMateria const & src)
{
    *this = src;
}

AMateria& AMateria::operator=(const AMateria& rhs) 
{
    if (this != &rhs) 
        _type = rhs._type;
    return *this;
}


std::string const & AMateria::getType() const
{
    return _type;
}


void AMateria::use(ICharacter& target)
{
    std::cout << "AMateria " << _type << " used on " << target.getName() << std::endl;
}
