/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:49:34 by nolahmar          #+#    #+#             */
/*   Updated: 2024/03/05 15:07:40 by nolahmar         ###   ########.fr       */
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
    std::cout << "------------------ using addRange member function ------------" << std::endl;
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
    std::cout << "----------------------------------------------------------------" << std::endl;
    std::cout << "------------------ handle overflow ------------" << std::endl;
    try
    {
        Span sp = Span(2);
        std::vector<int> v;
        v.push_back(-2147483648);
        v.push_back(2147483647);
        sp.addRange(v.begin(), v.end());
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "exception found " << e.what() << std::endl;
    }
    std::cout << "----------------------------------------------------------------" << std::endl;
    std::cout << "------------------ add large range ------------" << std::endl;
    try
    {
        Span sp = Span(1000000);
        std::vector<int> v;

        for (unsigned int i = 1; i <= 1000000; i++)
            v.push_back(i);
        sp.addRange(v.begin(), v.end());
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "exception found " << e.what() << std::endl;
    }
    std::cout << "----------------------------------------------------------------" << std::endl;
    return 0;
}
