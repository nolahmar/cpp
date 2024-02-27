/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:05:01 by nolahmar          #+#    #+#             */
/*   Updated: 2024/02/27 17:25:05 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <iostream>
#include <sstream>
#include <limits>
#include <cctype>
#include <cmath>

class ScalarConverter {
    public:
        ScalarConverter();
        ScalarConverter(ScalarConverter const& x);
        ScalarConverter& operator=(ScalarConverter const& x);
        ~ScalarConverter();
        static bool isValidNumber(const std::string& str);
        static void convert(const std::string& literal);
};

# endif