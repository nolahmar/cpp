/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:04:11 by nolahmar          #+#    #+#             */
/*   Updated: 2023/12/23 12:27:30 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

struct Address
{
    private:
        AMateria*   _ptr;
        Address*    _next;
    public:
        Address(AMateria *address);
        void deleteAddress(void);
        void next(Address *next_node);
        Address *getNext(void) const;
};

class Character : public ICharacter 
{
    private:
        AMateria    *_inventory[4];
        std::string _name;
        Address     *_addresses; // store the head of the list
        Address     *_tail; // store the tail of the list for ease addback
    private:
        void _addBack(Address *newNode);
    public:
        Character();
        ~Character();
        Character(Character const &);
        Character(std::string const &name);
        Character& operator=(Character const &);    
        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
};

#endif
