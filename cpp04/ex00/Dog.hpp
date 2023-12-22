/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:17:44 by nolahmar          #+#    #+#             */
/*   Updated: 2023/12/20 14:07:41 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
class Dog  : public Animal
{
    public:
        Dog();
        ~Dog();
        Dog( const Dog& src );
        Dog& operator=( const Dog& src );
        void makeSound() const;
};

#endif
