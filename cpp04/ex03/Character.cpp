/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:03:34 by nolahmar          #+#    #+#             */
/*   Updated: 2023/12/22 16:48:58 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string const &name) : _name(name)
{
    for (int i = 0; i < 4; i++) {
        _index[i] = NULL;
        _emptySlots = 0;
    }
    std::cout << "Character " <<_name << " created" << std::endl;
}

Character::Character(Character const &src) : _name(src._name)
{
    *this = src;
    std::cout << "Character " << _name << " created" << std::endl;
}

Character& Character::operator=(Character const &rhs)
{
    if (this != &rhs)
    {
        _name = rhs._name;
        for (int i = 0; i < 4; i++)
            _index[i] = rhs._index[i];
    }
    return *this;
}

std::string const& Character::getName() const
{
    return _name;
}   

Character::~Character()
{
    for (int i = 0; i < 4; i++)
        if (_index[i])
            delete _index[i];
    std::cout << "Character " <<_name << " destroyed" << std::endl;
}

void    Character::equip( AMateria* m )
{
    for (int i = 0; i < 4; i++)
    {
        if (_emptySlots[i])
        {
            _index[i] = m;
            _emptySlots[i] = 1;
                return;
        }
    }
    std::cout << "Character " <<_name << "  " << m->getType() << std::endl;
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= 4 || !_emptySlots[idx])
    {
        std::cout << "" << std::endl;
        return ;
    }
    _emptySlots[idx] = 0;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx >= 4 || !_emptySlots[idx])
    {
        std::cout << "" << std::endl;
        return ;
    }
    _index[idx]->use(target);
}
