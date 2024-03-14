/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:02:27 by nolahmar          #+#    #+#             */
/*   Updated: 2024/03/14 17:01:28 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

long long ft_stoi(const std::string &str)
{
    std::stringstream ss(str);
    long long value;

    ss >> value;

    return value;
}

bool is_operator(const std::string& token)
{
    if (token.size() != 1)
        return false;
    return token == "+" || token == "-" || token == "*" || token == "/";
}

bool is_valid_dig(const std::string& token)
{
    size_t minus_count = 0;

    for (size_t i = 0; i < token.size(); i++)
    {
        if (token[i] == '-')
            ++minus_count;
        else if (!isdigit(token[i]))
            return false;
    }

    return (!minus_count || (minus_count == 1 && token[0] == '-'));
}

long long calcule_operation(long long lhs, long long rhs, char op) {
    switch (op) {
        case '+': 
            return lhs + rhs;
        case '-':
            return lhs - rhs;
        case '*':
            return lhs * rhs;
        case '/':
            if (rhs != 0)
                return lhs / rhs;
            else {
                std::cout << "Error: Division by zero" << std::endl;
                exit(1);
            }
        default:
            std::cout << "Error: Invalid operator" << std::endl;
            exit(1);
    }
}

long long evaluate_rpn(const std::string& expression) {
    std::stack<long long> stack;

    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        if (is_operator(token)) {
            if (stack.size() < 2) {
                std::cout << "Error: not enough operands" << std::endl;
                exit(1);
            }
            long long rhs = stack.top();
            stack.pop();
            long long lhs = stack.top();
            stack.pop();

            long long result = calcule_operation(lhs, rhs, token[0]);
            stack.push(result);
            continue;
        }
        if (!is_valid_dig(token)) {
            std::cout << "Error: Invalid operand" << std::endl;
            exit(1);
        }
        stack.push(ft_stoi(token));
    }
    if (stack.size() == 1)
        return stack.top();
    else {
        std::cout << "Error: Invalid formula" << std::endl;
        exit(1);
    }
}

