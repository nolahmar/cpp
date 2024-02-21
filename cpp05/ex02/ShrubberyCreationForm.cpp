/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 14:17:14 by nolahmar          #+#    #+#             */
/*   Updated: 2024/02/20 16:40:01 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation Form", 145, 137)
{
    _target = "default";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery Creation Form", 145, 137)
{
    _target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src)
{
    *this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
    if (this != &rhs)
        _target = rhs._target;
    return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
    if (!getSigned())
        throw AForm::AFormNotSignedException();

    if (executor.getGrade() <= getGradeToExecute()) {
        std::ofstream outfile(_target + "_shrubbery");

        if (!outfile.is_open())
        {
            std::cerr << "Can't open the file " << _target << "_shruberry" << std::endl;
            exit(1);
        }
        outfile << "       _-_\n"; 
        outfile << "    /~~   ~~\\\n";
        outfile << " /~~         ~~\\\n";
        outfile << "{               }\n";
        outfile << " \\  _-     -_  /\n";
        outfile << "   ~  \\ //  ~\n";
        outfile << "_- -   | | _- _\n";
        outfile << "  _ -  | |   -_\n";
        outfile << "      // \\\\\n";
        outfile.close();
    }
    else {
        std::cout << executor.getName() << " couldn't execute ShrubberyCreationForm because of low grade." << std::endl;
    }
}

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &shr)
{
    out << "Shrubbery Creation Form: " << shr.getName() << ", grade to sign: " << shr.getGradeToSign() << ", grade to execute: " << shr.getGradeToExecute() << ", signed: " << shr.getSigned() << std::endl;
    return out;
}