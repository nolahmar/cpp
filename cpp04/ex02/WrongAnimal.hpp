/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:57:46 by nolahmar          #+#    #+#             */
/*   Updated: 2023/12/19 16:32:39 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
    protected:
        std::string _type;
    public:
        WrongAnimal();
        WrongAnimal(std::string type);
         ~WrongAnimal();
        WrongAnimal& operator=( const WrongAnimal& rhs );
        WrongAnimal (const WrongAnimal& src);
        std::string     getType( void ) const;
        void makeSound() const;
        
};

#endif