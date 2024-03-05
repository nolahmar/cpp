/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:56:09 by nolahmar          #+#    #+#             */
/*   Updated: 2024/03/05 15:07:10 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span()
{
    
}

Span::Span(unsigned int n): _n(n)
{
    _v.reserve(n);
}

Span::~Span()
{
    
}

Span::Span(const Span &copy)
{
    *this = copy;
}

Span& Span::operator=(const Span &copy)
{
    if (this != &copy)
    {
        _n = copy._n;
        _v = copy._v;
    }  
    return (*this);
}

void Span::addNumber(int n)
{
    if (_v.size() < _n)
        _v.push_back(n);   
    else
        throw std::exception();
}

long long Span::shortestSpan()
{
    long long min;

    if (_v.size() < 2)
        throw std::exception();
    std::sort(_v.begin(), _v.end());
    min = (long long)_v[1] - (long long)_v[0];
    for (unsigned int i = 0; i < _v.size() - 1; i++)
    {
        if ((long long)_v[i + 1] - (long long)_v[i] < min)
            min = (long long)_v[i + 1] - (long long)_v[i];
    }
    return min;
}

long long Span::longestSpan()
{
    if (_v.size() < 2)
        throw std::exception();
    std::sort(_v.begin(), _v.end());
    return ((long long)_v.back() - (long long)_v.front());
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    while (begin != end)
    {
        addNumber(*begin);
        begin++;   
    }
}