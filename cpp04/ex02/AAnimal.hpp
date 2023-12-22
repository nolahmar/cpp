/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:52:58 by nolahmar          #+#    #+#             */
/*   Updated: 2023/12/20 15:28:19 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>

class AAnimal {
    protected:
        std::string _type;
    public:
        AAnimal();
        AAnimal(std::string type);
        virtual ~AAnimal();
        AAnimal& operator=(const AAnimal& rhs);
        AAnimal (const AAnimal& src);
        std::string     getType( void ) const;
        virtual void makeSound() const=0;
        
};

#endif