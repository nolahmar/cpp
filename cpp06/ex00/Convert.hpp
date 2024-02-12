/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:05:01 by nolahmar          #+#    #+#             */
/*   Updated: 2024/02/12 12:00:55 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <iostream>
#include <sstream>
#include <limits>
#include <cctype>
#include <cmath>

class ScalarConvertert {
    public:
       static bool isValidNumber(const std::string& str);
       static void convert(const std::string& literal);
};

# endif