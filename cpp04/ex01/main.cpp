/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:52:30 by nolahmar          #+#    #+#             */
/*   Updated: 2023/12/25 13:09:43 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    j->makeSound();
    i->makeSound();
    delete i;
    delete j;
    
    const Animal* animals[2] = {new Dog(), new Cat()};
    for ( int i = 0; i < 2; i++ ) {
        delete animals[i];
    }
    
    std::cout << "---------------------- deep copy test --------------------" << std::endl;
    Dog* d = new Dog();
    Dog* s = new Dog(*d);

    delete d;
    delete s;
    system("leaks Animal");
    return 0;
}