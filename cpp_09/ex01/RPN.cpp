/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:02:27 by nolahmar          #+#    #+#             */
/*   Updated: 2024/03/07 16:32:33 by nolahmar         ###   ########.fr       */
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

int calcule_operation(int parti1, int parti2, char op) {
    switch (op) {
        case '+': 
            return parti1 + parti2;
        case '-':
            return parti1 - parti2;
        case '*':
            return parti1 * parti2;
        case '/':
            if (parti2 != 0)
                return parti1 / parti2;
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
    std::stack<int> part;

    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        if (isdigit(token[0]))
            part.push(ft_stoi(token));
        else if (is_operator(token[0])) {
            if (part.size() < 2) {
                std::cerr << "Error" << std::endl;
                exit(1);
            }

            int part2 = part.top();
            part.pop();
            int part1 = part.top();
            part.pop();

            int result = calcule_operation(part1, part2, token[0]);
            part.push(result);
        } else {
            std::cerr << "Error" << std::endl;
            exit(1);
        }
    }

    if (part.size() == 1)
        return part.top();
    else {
        std::cerr << "Error" << std::endl;
        exit(1);
    }
}

