/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:04:11 by nolahmar          #+#    #+#             */
/*   Updated: 2023/12/22 16:46:51 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define CHARACTER_HPP
#ifndef CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter 
{
    private:
        AMateria *_index[4];
        std::string _name;
        bool _emptySlots[4];
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
