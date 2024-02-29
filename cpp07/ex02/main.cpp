/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:29:03 by nolahmar          #+#    #+#             */
/*   Updated: 2024/02/29 15:50:05 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
    Array<int>a(6);
    
    try
    {
        a[6] = 8;
        a[4] = 5;
        std::cout << a[6] << std::endl;
        std::cout << a[4] << std::endl;
        std::cout << a[50] << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << "index is out of range" << std::endl;
    }

     Array<char> b(10);
    
    try
    {
        b[5] = 'a';
        b[4] = 'b';
        std::cout << b[5] << std::endl;
        std::cout << b[4] << std::endl;
        std::cout << b[50] << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << "index is out of range" << std::endl;
    }
    system("leaks Array");
    return (0);
}
