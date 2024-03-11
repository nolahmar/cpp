/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:02:27 by nolahmar          #+#    #+#             */
/*   Updated: 2024/03/09 11:28:25 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int ft_stoi(const std::string &str)
{
    std::stringstream ss(str);
    int value;

    ss >> value;

    return value;
}

bool is_operator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int calcule_operation(int lhs, int rhs, char op) {
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
                std::cerr << "Error: Division by zero" << std::endl;
                exit(1);
            }
        default:
            std::cerr << "Error: Invalid operator" << std::endl;
            exit(1);
    }
}

int evaluate_rpn(const std::string& expression) {
    std::stack<int> stack;

    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        if (isdigit(token[0]))
            stack.push(ft_stoi(token));
        else if (is_operator(token[0])) {
            if (stack.size() < 2) {
                std::cerr << "Error" << std::endl;
                exit(1);
            }

            int rhs = stack.top();
            stack.pop();
            int lhs = stack.top();
            stack.pop();

            int result = calcule_operation(lhs, rhs, token[0]);
            stack.push(result);
        } else {
            std::cerr << "Error" << std::endl;
            exit(1);
        }
    }

    if (stack.size() == 1)
        return stack.top();
    else {
        std::cerr << "Error" << std::endl;
        exit(1);
    }
}

