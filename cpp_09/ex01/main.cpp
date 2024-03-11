/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:14:45 by nolahmar          #+#    #+#             */
/*   Updated: 2024/03/08 12:14:07 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2) {
        std::cerr << "Usage :" << av[0] << " expression" << std::endl;
        return 1;
    }

    std::string expression = av[1];
    int result = evaluate_rpn(expression);
    std::cout << result << std::endl;
    return 0;
}

