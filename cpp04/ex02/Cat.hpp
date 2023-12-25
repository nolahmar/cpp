/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:14:47 by nolahmar          #+#    #+#             */
/*   Updated: 2023/12/25 13:17:10 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal 
{
    private:
        Brain   *_brain;
    public:
        Cat();
        ~Cat();
        Cat(const Cat& src);
        Cat& operator=(const Cat& src);
        void makeSound() const;
};

#endif
