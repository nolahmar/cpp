/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:59:17 by nolahmar          #+#    #+#             */
/*   Updated: 2024/02/07 11:59:20 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat bureaucrat("mimon", 22);
        std::cout << bureaucrat << std::endl;
        bureaucrat.incrementGrade();
        std::cout << bureaucrat << std::endl;
        bureaucrat.decrementGrade();
        std::cout << bureaucrat << std::endl;
        Bureaucrat invalidBureaucrat("Invalid", 0);
    } 
    catch (const std::exception& error) {
        std::cerr << "Error: " << error.what() << std::endl;
    }
    return 0;
}