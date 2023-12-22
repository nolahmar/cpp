/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:52:58 by nolahmar          #+#    #+#             */
/*   Updated: 2023/12/19 15:35:49 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
    protected:
        std::string _type;
    public:
        Animal();
        Animal(std::string type);
        virtual ~Animal();
        Animal& operator=( const Animal& rhs );
        Animal (const Animal& src);
        std::string     getType( void ) const;
        virtual void makeSound() const;
        
};

#endif