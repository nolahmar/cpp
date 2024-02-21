/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:59:43 by nolahmar          #+#    #+#             */
/*   Updated: 2024/02/19 15:34:32 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Form.hpp"

Form::Form():_name("default"), _signed(false), _gradeToSign(0), _gradeToExecute(0)
{
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name)
    , _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (_gradeToExecute < 1 || _gradeToSign < 1)
        throw Form::GradeTooHighException();
    if (_gradeToExecute > 150 || _gradeToSign > 150)
       throw Form::GradeTooLowException();
    _signed = false;
}

Form::Form(const Form &copy) : _name(copy._name)
    , _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
    *this = copy;
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
    if (bureaucrat.getGrade() <= _gradeToSign)
        _signed = true;
    else
        throw Form::GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw()
{
    return ("You overrated the grade, which is limited in the range [1, 150]");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("You underrated the grade, which is limited in the range [1, 150]");
}

std::ostream& operator<<(std::ostream &o, const Form &form)
{
    o << "Form name: " << form.getName() << std::endl;
    o << "Grade to sign: " << form.getGradeToSign() << std::endl;
    o << "Grade to execute: " << form.getGradeToExecute() << std::endl;
    o << "Signed: " << form.getSigned() << std::endl;
    return (o);
}