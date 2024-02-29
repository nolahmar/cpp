/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 09:37:17 by nolahmar          #+#    #+#             */
/*   Updated: 2024/02/29 15:13:56 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template < typename T >
void    iter( T *arr, size_t size, void (*f)(T&) ){
    for ( size_t i = 0; i < size; i++ )
        f(arr[i]);
}

template < typename T >
void    print(T &i)
{
    std::cout << i << std::endl;
}

# endif