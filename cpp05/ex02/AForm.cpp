/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:33:37 by nolahmar          #+#    #+#             */
/*   Updated: 2024/02/07 12:02:26 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    _signed = false;
}

Form::Form(const Form &copy) : _name(copy._name), _signed(copy._signed), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
}

Form&   Form::operator=(const Form &copy)
{
    if (this != &copy)
        _signed = copy.getSigned();
    return (*this);
}

Form::~Form()
{
}

std::string Form::getName() const
{
    return (_name);
}

int         Form::getGradeToSign() const
{
    return (_gradeToSign);
}

bool        Form::getSigned() const
{
    return (_signed);
}

int         Form::getGradeToExecute() const
{
    return (_gradeToExecute);
}

void        Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() <= this->_gradeToSign)
    {
        this->_signed = true;
        std::cout << "The form status has been validated successfully" << std::endl;
    }
    else
    {
        throw Form::GradeTooLowException();
    }
}

const char* Form::GradeTooHighException::what() const throw()
{
    return ("You overrated the grade, which is limited in the range [1, 150]");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("You underrated the grade, which is limited in the range [1, 150]");
}

const char* Form::FormNotSignedException::what() const throw()
{
    return ("The form is not signed");
}

std::ostream& operator<<(std::ostream &out, const Form &form)
{
    out << "Form name: " << form.getName() << std::endl;
    out << "Grade to sign: " << form.getGradeToSign() << std::endl;
    out << "Grade to execute: " << form.getGradeToExecute() << std::endl;
    out << "Signed: " << form.getSigned() << std::endl;
    return (out);
}