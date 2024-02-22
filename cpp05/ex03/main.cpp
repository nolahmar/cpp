/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noni <noni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:59:08 by nolahmar          #+#    #+#             */
/*   Updated: 2024/02/21 16:52:14 by noni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main( void )
{

    std::cout << "---------------------- Execute Shruberry ------------------" << std::endl;
    try {
        Bureaucrat b("mimon", 100);
        AForm *tree = new ShrubberyCreationForm("home");

        b.signForm(*tree);
        b.executeForm(*tree);
    } 
    catch (std::exception &error) {
        std::cout << error.what() << std::endl;
    }
    std::cout << "-------------------------------------------------------------" << std::endl;
    std::cout << "---------------------- Can't sign Shruberry ------------------" << std::endl;
    try {
        Bureaucrat a("mimon", 149);
        Bureaucrat b("bisbisso", 100);
        AForm *tree = new ShrubberyCreationForm("home");

        a.signForm(*tree);
        b.executeForm(*tree);
    } 
    catch (std::exception &error) {
        std::cout << error.what() << std::endl;
    }
    std::cout << "-------------------------------------------------------------" << std::endl;
    std::cout << "---------------------- Can't execute Shruberry ------------------" << std::endl;
    try {
        Bureaucrat a("mimon", 120);
        Bureaucrat b("bisbisso", 140);
        AForm *tree = new ShrubberyCreationForm("home");

        a.signForm(*tree);
        b.executeForm(*tree);
    } 
    catch (std::exception &error) {
        std::cout << error.what() << std::endl;
    }
    std::cout << "-------------------------------------------------------------" << std::endl;
    std::cout << "------------------ Try to execute unsigned Shruberry ------------------" << std::endl;
    try {
        Bureaucrat a("mimon", 120);
        Bureaucrat b("bisbisso", 130);
        AForm *tree = new ShrubberyCreationForm("home");

        b.executeForm(*tree);
    } 
    catch (std::exception &error) {
        std::cout << error.what() << std::endl;
    }
    std::cout << "-------------------------------------------------------------" << std::endl;
    std::cout << "---------------------- Execute Robotomy  ------------------" << std::endl;
    try {
        Bureaucrat b("mimon", 40);
        AForm *tree = new RobotomyRequestForm("Matrix");

        b.signForm(*tree);
        b.executeForm(*tree);
    } 
    catch (std::exception &error) {
        std::cout << error.what() << std::endl;
    }
    std::cout << "-------------------------------------------------------------" << std::endl;
    std::cout << "---------------------- Execute Presidentila Pardon  ---------" << std::endl;
    try {
        Bureaucrat b("mimon", 1);
        AForm *tree = new PresidentialPardonForm("President");

        b.signForm(*tree);
        b.executeForm(*tree);
    } 
    catch (std::exception &error) {
        std::cout << error.what() << std::endl;
    }
    std::cout << "-------------------------------------------------------------" << std::endl;
    return 0;
}
