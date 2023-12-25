/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:52:30 by nolahmar          #+#    #+#             */
/*   Updated: 2023/12/25 11:43:10 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main()
{
    std::cout << "-----------[ Animal ]----------" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();
    delete meta;
    delete j;
    delete i;

    std::cout << "-----------[ WrongAnimal ]----------" << std::endl;
    const WrongAnimal *mimon = new WrongAnimal();
    const WrongAnimal *bassabisso = new WrongCat();
    
    std::cout << "WrongCat type " <<  bassabisso->getType() << " " << std::endl;
    mimon->makeSound();
    bassabisso->makeSound();
    
    delete mimon;
    delete bassabisso;

    return 0;
}