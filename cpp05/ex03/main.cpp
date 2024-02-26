/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:59:08 by nolahmar          #+#    #+#             */
/*   Updated: 2024/02/26 17:53:55 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main( void )
{

    std::cout << "---------------------- Execute Shruberry ------------------" << std::endl;
    try {
        Bureaucrat b("mimon", 100);
        Intern bisbisso;
        AForm *tree = bisbisso.makeForm("shrubbery creation", "home");

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
        Intern brownie;
        AForm *tree = brownie.makeForm("shrubbery creation", "home");

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
        Intern brownie;
        AForm *tree = brownie.makeForm("shrubbery creation", "home");

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
        Intern brownie;
        AForm *tree = brownie.makeForm("shrubbery creation", "home");

        b.executeForm(*tree);
    } 
    catch (std::exception &error) {
        std::cout << error.what() << std::endl;
    }
    std::cout << "-------------------------------------------------------------" << std::endl;
    std::cout << "---------------------- Execute Robotomy  ------------------" << std::endl;
    try {
        Bureaucrat b("mimon", 40);
        Intern bisbisso;
        AForm *robot = bisbisso.makeForm("robotomy request", "Matrix");

        b.signForm(*robot);
        b.executeForm(*robot);
    } 
    catch (std::exception &error) {
        std::cout << error.what() << std::endl;
    }
    std::cout << "-------------------------------------------------------------" << std::endl;
    std::cout << "---------------------- Execute Presidentila Pardon  ---------" << std::endl;
    try {
        Bureaucrat b("mimon", 1);
        Intern bisbisso;
        AForm *prd = bisbisso.makeForm("presidential pardon", "President");

        b.signForm(*prd);
        b.executeForm(*prd);
    } 
    catch (std::exception &error) {
        std::cout << error.what() << std::endl;
    }
    std::cout << "-------------------------------------------------------------" << std::endl;
    std::cout << "---------------------- Create invalid form  ---------" << std::endl;
    try {
        Bureaucrat b("mimon", 1);
        Intern bisbisso;
        AForm *prd = bisbisso.makeForm("presidential pardondxd", "President");

        (void)prd;
    } 
    catch (std::exception &error) {
        std::cout << error.what() << std::endl;
    }
    std::cout << "-------------------------------------------------------------" << std::endl;
    return 0;
}
