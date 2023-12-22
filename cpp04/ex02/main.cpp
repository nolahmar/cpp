/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:52:30 by nolahmar          #+#    #+#             */
/*   Updated: 2023/12/22 10:19:36 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "AAnimal.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main( void )
{
    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();

    j->makeSound();
    i->makeSound();

    delete j;//should not create a leak
    delete i;

    const AAnimal* animals[2] = {new Dog(), new Cat()};
    for ( int i = 0; i < 2; i++ ) {
        delete animals[i];
    }

    return 0;
}