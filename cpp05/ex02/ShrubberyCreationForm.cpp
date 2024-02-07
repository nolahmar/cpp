/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 14:17:14 by nolahmar          #+#    #+#             */
/*   Updated: 2024/02/07 13:11:00 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("Shrubbery Creation Form", 145, 137)
{
    _target = "default";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("Shrubbery Creation Form", 145, 137)
{
    _target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : Form(src)
{
    *this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
    _target = rhs._target;
    return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
    if (!getSigned())
        throw Form::GradeTooLowException();

    if (executor.getGrade() <= getGradeToExecute()) {
        std::ofstream outfile(_target + "_shrubbery");
        outfile << "ASCII Art of Trees";  // Add your ASCII art here
        outfile.close();
        std::cout << "ShrubberyCreationForm executed successfully by " << executor.getName() << std::endl;
    } else {
        std::cout << executor.getName() << " couldn't execute ShrubberyCreationForm because of low grade." << std::endl;
    }
}

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &shr)
{
    out << "Shrubbery Creation Form: " << shr.getName() << ", grade to sign: " << shr.getGradeToSign() << ", grade to execute: " << shr.getGradeToExecute() << ", signed: " << shr.getSigned() << std::endl;
    return out;
}