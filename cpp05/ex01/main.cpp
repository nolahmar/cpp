/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:59:59 by nolahmar          #+#    #+#             */
/*   Updated: 2024/02/19 15:31:19 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "--------------------- Bureaucrat can't sign Form ----------" << std::endl;
    try {
        Bureaucrat bureaucrat("bisbisso",11);
        Form form("Contract", 10, 20);
        bureaucrat.signForm(form);
        std::cout << form << std::endl;
    }
    catch (std::exception &error) {
        std::cout << error.what() << std::endl;
    }
    std::cout << "------------------------------------------------------------" << std::endl;
    std::cout << "--------------------- From sign grade out of range ----------" << std::endl;
    try {
        Bureaucrat bureaucrat("bisbisso",11);
        Form form("Contract", 0, 20);
        bureaucrat.signForm(form);
        std::cout << form << std::endl;
    }
    catch (std::exception &error) {
        std::cout << error.what() << std::endl;
    }
    std::cout << "------------------------------------------------------------" << std::endl;
    std::cout << "--------------------- From excute grade out of range ----------" << std::endl;
    try {
        Bureaucrat bureaucrat("bisbisso",11);
        Form form("Contract", 10, 200);
        bureaucrat.signForm(form);
        std::cout << form << std::endl;
    }
    catch (std::exception &error) {
        std::cout << error.what() << std::endl;
    }
    std::cout << "------------------------------------------------------------" << std::endl;
    return 0;
}