/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:49:34 by nolahmar          #+#    #+#             */
/*   Updated: 2024/03/03 17:38:50 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
     std::cout << "------------------ using addNumber member function ------------------" << std::endl;
    try
    {
        Span sp = Span(5);
        sp.addNumber(1);
        sp.addNumber(1);
        sp.addNumber(1);
        sp.addNumber(9);
        sp.addNumber(1);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "exception found " << e.what() << std::endl;
    }
    std::cout << "----------------------------------------------------------------" << std::endl;
    std::cout << "------------------ using addRange memeber function ------------" << std::endl;
    
    try
    {
        Span sp = Span(5);
        std::vector<int> v;
        v.push_back(6);
        v.push_back(3);
        v.push_back(1);
        v.push_back(9);
        v.push_back(11);
        sp.addRange(v.begin(), v.end());
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "exception found " << e.what() << std::endl;
    }
    return 0;
}