/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:17:44 by nolahmar          #+#    #+#             */
/*   Updated: 2023/12/20 14:43:04 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog  : public AAnimal
{
    private:
        Brain   *_brain;
    public:
        Dog();
        ~Dog();
        Dog( const Dog& src );
        Dog& operator=( const Dog& src );
        void makeSound() const;
};

#endif
