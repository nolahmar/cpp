/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:03:34 by nolahmar          #+#    #+#             */
/*   Updated: 2023/12/25 15:06:29 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string const &name) : _name(name), _addresses(NULL), _tail(NULL)
{
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
    // std::cout << "Character " <<_name << " created" << std::endl;
}

Character::Character(Character const &src)
{
    *this = src;
    // std::cout << "Character " << _name << " created" << std::endl;
}

Character& Character::operator=(Character const &rhs)
{
    if (this != &rhs)
    {
        _name = rhs._name;
        for (int i = 0; i < 4; i++) {
            if (_inventory[i])
                delete _inventory[i];
            if (rhs._inventory[i])
                _inventory[i] = rhs._inventory[i]->clone();
            else
                _inventory[i] = NULL;
        }
    }
    return *this;
}

std::string const& Character::getName() const
{
    return _name;
}   

Character::~Character()
{
    // destroy saved addresses
    while (_addresses)
    {
        _addresses->deleteAddress();
        _addresses = _addresses->getNext();
    }
    
    // destroy address from inventory
    for (int i = 0; i < 4; i++)
        if (_inventory[i])
            delete _inventory[i];
    // std::cout << "Character " <<_name << " destroyed" << std::endl;
}

void    Character::equip(AMateria* m)
{
    for (int i = 0; i < 4; i++)
    {
        if (!_inventory[i])
        {
            _inventory[i] = m;
            return;
        }
    }
    std::cout << "Can't add new AMateria, inventory is full " << std::endl;
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= 4)
    {
        std::cout << "Invalid idx: " << ((idx < 0) ? "idx < 0" : "idx out of range") << std::endl;
        return ;
    }
    if (!_inventory[idx])
    {
        std::cout << "Inventory at " << idx << " is empty" << std::endl;
        return ;
    }
    // save address
    _addBack(new Address(_inventory[idx]));
    _inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx >= 4)
    {
        std::cout << "Invalid idx: " << ((idx < 0) ? "idx < 0" : "idx out of range") << std::endl;
        return ;
    }
    if (!_inventory[idx])
    {
        std::cout << "Inventory at " << idx << " is empty" << std::endl;
        return ;
    }
    _inventory[idx]->use(target);
}

void Character::_addBack(Address *newNode)
{
    if (!_addresses)
    {
        _addresses = newNode;
        _tail = newNode;
        return;
    }
    _tail->next(newNode);
    _tail = newNode;
}


Address::Address(AMateria *address): _ptr(address), _next(NULL) {}

void Address::deleteAddress(void) { delete _ptr; }

void Address::next(Address *next_node) { _next = next_node; }

Address* Address::getNext(void) const { return _next; }
