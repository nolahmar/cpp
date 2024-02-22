/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noni <noni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 14:17:14 by nolahmar          #+#    #+#             */
/*   Updated: 2024/02/21 16:17:39 by noni             ###   ########.fr       */
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

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src): AForm(src)
{
    *this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
    AForm::operator=(rhs);
    if (this != &rhs)
        _target = rhs._target;
    return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
    if (!getSigned())
        throw AForm::AFormNotSignedException();
    if (executor.getGrade() > getGradeToExecute())
        throw AForm::CouldNotExecuteException();

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
