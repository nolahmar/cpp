/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:54:59 by nolahmar          #+#    #+#             */
/*   Updated: 2023/12/25 15:08:25 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
    std::cout << "--------------------- subject tests ----------------" << std::endl;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    delete bob;
    delete me;
    delete src;
    
    std::cout << "------------------------ other tests ------------------------" << std::endl;
    IMateriaSource* m = new MateriaSource();
    m->learnMateria(new Ice());
    m->learnMateria(new Ice());
    m->learnMateria(new Cure());
    m->learnMateria(new Cure());
    ICharacter* c = new Character("test");
    tmp = m->createMateria("ice");
    c->equip(tmp);
    tmp = m->createMateria("ice");
    c->equip(tmp);
    tmp = m->createMateria("cure");
    c->equip(tmp);
    tmp = m->createMateria("cure");
    c->equip(tmp);
    tmp = m->createMateria("ice");
    c->equip(tmp); // should not equip because inventory is full
    c->unequip(0); // should unequip the first element
    c->equip(tmp); // should equip tmp in index 0
    c->unequip(1);
    c->unequip(2);
    tmp = m->createMateria("ice");
    c->equip(tmp);
    ICharacter *target = new Character("noni");
    
    c->use(0, *target);
    
    system("leaks AMateria");
    return 0;
}