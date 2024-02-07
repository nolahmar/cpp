/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 14:18:54 by nolahmar          #+#    #+#             */
/*   Updated: 2024/02/07 13:10:38 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("Presidential Pardon Form", 25, 5)
{
    _target = "default";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("Presidential Pardon Form", 25, 5)
{
    _target = target;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) : Form(src)
{
    *this = src;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
    _target = rhs._target;
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (getSigned() == false)
        throw Form::FormNotSignedException();
    else if (executor.getGrade() > getGradeToExecute())
        throw Form::GradeTooLowException();
    else
        std::cout << _target << " " << std::endl;
}

std::ostream &operator<<(std::ostream &out, const PresidentialPardonForm &pres)
{
    out << "Presidential Pardon Form: " << pres.getName() << ", grade to sign: " << pres.getGradeToSign() << ", grade to execute: " << pres.getGradeToExecute() << ", signed: " << pres.getSigned() << std::endl;
    return out;
}