/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:14:45 by nolahmar          #+#    #+#             */
/*   Updated: 2024/03/14 16:59:33 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2) {
        std::cout << "Usage :" << av[0] << " formula" << std::endl;
        return 1;
    }

    std::string expression = av[1];
    long long result = evaluate_rpn(expression);
    std::cout << result << std::endl;
    return 0;
}

