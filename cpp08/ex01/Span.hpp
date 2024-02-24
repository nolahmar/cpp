/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:15:53 by nolahmar          #+#    #+#             */
/*   Updated: 2024/02/24 14:32:49 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <exception>
#include <algorithm>

class Span {
    private:
        int _n;
        std::vector<int> _v;
        
    public:
        Span(unsigned int n);
        Span(const Span &copy);
        ~Span();
        Span &operator=(const Span &copy);
        void addNumber(int n);
        int shortestSpan();
        int longestSpan();
};

#endif