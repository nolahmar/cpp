/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 14:17:14 by nolahmar          #+#    #+#             */
/*   Updated: 2024/02/03 16:25:18 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():Form("Shrubbery", 145, 137)
{
    this->_target = "default";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
{
    this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : Form(src)
{
    *this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    this->_target = other._target;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const ShrubberyCreationForm &shr)
{
    os << "Shrubbery Creation Form: " << shr.getName() << ", grade to sign: " << shr.getGradeToSign() << ", grade to execute: " << shr.getGradeToExec() << ", signed: " << shr.getSigned() << std::endl;
    return os;
}