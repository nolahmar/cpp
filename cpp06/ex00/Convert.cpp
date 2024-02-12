/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:05:07 by nolahmar          #+#    #+#             */
/*   Updated: 2024/02/12 12:01:13 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

 bool ScalarConvertert::isValidNumber(const std::string& str) {
    if (str.empty()) return false;

    size_t f_count = 0;
    size_t dot_count = 0;

    if (str == "nan" || str == "+inf" || str == "-inf") {
        return true;
    }

    for (size_t i = 0; i < str.size(); ++i) {
        if (!isdigit(str[i])) {
            if (i == 0 && (str[i] == '+' || str[i] == '-')) {
                continue;
            }
            
            if (str[i] == 'f') {
                if (i != str.size() - 1 && (str[i + 1] != '.' || f_count > 0)) {
                    return false;
                }
                f_count++;
            } else if (str[i] == '.') {
                if (dot_count > 0)
                    return false;
                dot_count++;
            } else 
                return false;
        }
    }
    return true;
}

 void ScalarConvertert::convert(const std::string& literal) {
    if (!isValidNumber(literal)) {
            std::cout << "Invalid number format" << std::endl;
            return;
        }

            std::string floatLiteral = literal;
            if (floatLiteral.back() == 'f')
                floatLiteral.pop_back();
        std::istringstream iss(floatLiteral);

        if (literal == "nan" || literal == "+inf" || literal == "-inf") {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: " << literal << "f" << std::endl;
            std::cout << "double: " << literal << std::endl;
            return;
        }

        if (literal.find('.') != std::string::npos || literal.find('f') != std::string::npos) {
        // Float or double
        float f;
        if (iss >> f) {
            int i = static_cast<int>(f);
            char c = std::isprint(static_cast<unsigned char>(i)) ? static_cast<char>(i) : ' ';

            std::cout << "char: ";
            if (std::isprint(c))
                std::cout << "'" << c << "'" << std::endl;
            else
                std::cout << "Non displayable" << std::endl;

            std::cout << "int: " << i << std::endl;
            std::cout << "float: ";

            if (f == static_cast<int>(f))
                std::cout << f << ".0f" << std::endl;
            else
                std::cout << f << "f" << std::endl;

            std::cout << "double: " << static_cast<double>(f) << std::endl;
        } else {
            std::cout << "Conversion impossible" << std::endl;
        }

        } else {
            // Int or char
          int i;
        if (iss >> i) {
            char c = std::isprint(static_cast<unsigned char>(i)) ? static_cast<char>(i) : ' ';

            std::cout << "char: ";
            if (std::isprint(static_cast<unsigned char>(c)))
                std::cout << "'" << c << "'" << std::endl;
            else
                std::cout << "Non displayable" << std::endl;

            std::cout << "int: " << i << std::endl;
            std::cout << "float: " << static_cast<float>(i) << std::endl;
            std::cout << "double: " << static_cast<double>(i) << std::endl;
        } else 
            std::cout << "Conversion impossible" << std::endl;
        }
}