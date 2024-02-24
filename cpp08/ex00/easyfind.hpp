/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 13:44:29 by nolahmar          #+#    #+#             */
/*   Updated: 2024/02/24 14:18:32 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <exception>

template <typename T>
int easyfind(T &container, int n)
{
   typename T::iterator it = std::find(container.begin(), container.end(), n);
    if (it == container.end())
        throw std::exception();
    return *it;
}

#endif


