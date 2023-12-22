/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:12:23 by nolahmar          #+#    #+#             */
/*   Updated: 2023/12/20 13:46:10 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain( void )
{
    std::cout << "Brain default constrector created." << std::endl;
}

Brain::~Brain( void )
{
    std::cout << "Brain destroyed." << std::endl;
}

Brain::Brain( const Brain& src )
{
    std::cout << "copy constrector called !" << std::endl;
    *this = src;
}

Brain& Brain::operator=( const Brain& src )
{
    std::cout << "Brain copy called." << std::endl;
    if ( this != &src ) {
        for ( int i = 0; i < 100; i++ ) {
            this->_ideas[i] = src._ideas[i];
        }
    }
    return *this;
}
