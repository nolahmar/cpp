/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:59:17 by nolahmar          #+#    #+#             */
/*   Updated: 2024/02/19 14:42:01 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
    std::cout << "------------------ Normal test ------------------" << std::endl;
    try {
        Bureaucrat bureaucrat("mimon", 85);
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
    std::cout << "-------------------------------------------------" << std::endl;
    std::cout << "---------------- Increment out of range ---------" << std::endl;
    try {
        Bureaucrat bureaucrat("mimon", 1);
        std::cout << bureaucrat << std::endl;
        bureaucrat.incrementGrade();
    } 
    catch (const std::exception& error) {
        std::cerr << "Error: " << error.what() << std::endl;
    }
    std::cout << "-------------------------------------------------" << std::endl;
    std::cout << "------------------ Decrement out of range -------" << std::endl;
    try {
        Bureaucrat bureaucrat("mimon", 150);
        std::cout << bureaucrat << std::endl;
        bureaucrat.decrementGrade();
    } 
    catch (const std::exception& error) {
        std::cerr << "Error: " << error.what() << std::endl;
    }
    std::cout << "-------------------------------------------------" << std::endl;
    return 0;
}
