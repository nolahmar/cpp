/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:33:37 by nolahmar          #+#    #+#             */
/*   Updated: 2024/02/20 16:27:53 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(): _name("default"), _gradeToSign(0), _gradeToExecute(0)
{
    _signed = false;
}
AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : _name(name),
    _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    _signed = false;
}

AForm::AForm(const AForm &copy) : _name(copy._name), _signed(copy._signed),
    _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
}

AForm&   AForm::operator=(const AForm &copy)
{
    if (this != &copy)
        _signed = copy.getSigned();
    return (*this);
}

AForm::~AForm()
{
}

std::string AForm::getName() const
{
    return (_name);
}

int         AForm::getGradeToSign() const
{
    return (_gradeToSign);
}

bool        AForm::getSigned() const
{
    return (_signed);
}

int         AForm::getGradeToExecute() const
{
    return (_gradeToExecute);
}

void        AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() <= this->_gradeToSign)
    {
        this->_signed = true;
        std::cout << "The form status has been validated successfully" << std::endl;
    }
    else
    {
        throw AForm::GradeTooLowException();
    }
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return ("You overrated the grade, which is limited in the range [1, 150]");
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return ("You underrated the grade, which is limited in the range [1, 150]");
}

const char* AForm::AFormNotSignedException::what() const throw()
{
    return ("The form is not signed");
}

std::ostream& operator<<(std::ostream &out, const AForm &form)
{
    out << "AForm name: " << form.getName() << std::endl;
    out << "Grade to sign: " << form.getGradeToSign() << std::endl;
    out << "Grade to execute: " << form.getGradeToExecute() << std::endl;
    out << "Signed: " << form.getSigned() << std::endl;
    return (out);
}