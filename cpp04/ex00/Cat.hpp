/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:14:47 by nolahmar          #+#    #+#             */
/*   Updated: 2023/12/20 14:06:01 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "Animal.hpp"
class Cat : public Animal 
{
    public:
        Cat();
        ~Cat();
        Cat( const Cat& src );
        Cat& operator=( const Cat& src );
        void makeSound() const;
};

#endif
