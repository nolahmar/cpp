/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:05:07 by nolahmar          #+#    #+#             */
/*   Updated: 2024/02/27 16:27:31 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

ScalarConverter::ScalarConverter()
{

}

ScalarConverter::ScalarConverter(ScalarConverter const& x)
{
    *this = x;
}

ScalarConverter& ScalarConverter::operator=(ScalarConverter const& rhs)
{
    (void)rhs;
    return *this;   
}

ScalarConverter::~ScalarConverter() 
{

}

bool ScalarConverter::isValidNumber(const std::string &str)
{
    if (str.empty())
        return false;

    size_t dot_count = 0;

    if (str == "nan" || str == "+inf" || str == "-inf"
        || str == "nanf" || str == "+inff" || str == "-inff")
        return true;

    for (size_t i = 0; i < str.size(); ++i)
    {
        if (!isdigit(str[i]))
        {
            if (i == 0 && (str[i] == '+' || str[i] == '-'))
                continue;

            if (str[i] == 'f')
            {
                if (i == 0 || i != str.size() - 1)
                    return false;
            }
            else if (str[i] == '.')
            {
                if (i == str.size() - 1)
                    return false;
                if (str[i + 1] == 'f')
                    return false;
                dot_count++;
            }
            else
                return false;
        }
    }
    
    return dot_count <= 1;
}

void ScalarConverter::convert(const std::string &literal)
{
    if (!isValidNumber(literal))
    {
        std::cout << "Invalid number format" << std::endl;
        return;
    }

    std::string literal_copy = literal;
    if (literal_copy.back() == 'f')
        literal_copy.pop_back();
    std::istringstream iss(literal_copy);

    if (literal == "nan" || literal == "+inf" || literal == "-inf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << literal << "f" << std::endl;
        std::cout << "double: " << literal << std::endl;
        return;
    }
    if (literal == "nanf" || literal == "+inff" || literal == "-inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << literal<< std::endl;
        std::cout << "double: " << literal_copy << std::endl;
        return;
    }

    long double input;
    if (iss >> input)
    {
        int  n = static_cast<int>(input);
        char c = static_cast<char>(input);
        float f = static_cast<float>(input);
        double d = static_cast<double>(input); 

        std::cout << "char: ";
        if (input > std::numeric_limits<char>::max() || input < std::numeric_limits<char>::lowest())
            std::cout << "impossible" << std::endl;
        else {
            if (std::isprint(c))
                std::cout << "'" << c << "'" << std::endl;
            else
                std::cout << "Non displayable" << std::endl;
        }

        std::cout << "int: ";
        if (input > std::numeric_limits<int>::max() || input < std::numeric_limits<int>::lowest())
            std::cout << "impossible" << std::endl;
        else
            std::cout << n << std::endl;
        
        std::cout << "float: ";
        if (input > std::numeric_limits<float>::max() || input < std::numeric_limits<float>::lowest())
            std::cout << "impossible" << std::endl;
        else {
            if (f == static_cast<int64_t>(f))
                std::cout << f << ".0f" << std::endl;
            else
                std::cout << f << "f" << std::endl;
        }

        std::cout << "double: ";
        if (input > std::numeric_limits<double>::max() || input < std::numeric_limits<double>::lowest())
            std::cout << "impossible" << std::endl;
        else {
            if (d == static_cast<int64_t>(d))
                std::cout << d << ".0" << std::endl;
            else
                std::cout << d << std::endl;
        }
    }
    else
        std::cout << "conversion impossible" << std::endl;
}