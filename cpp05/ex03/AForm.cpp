/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:00:44 by nolahmar          #+#    #+#             */
/*   Updated: 2024/02/20 15:00:46 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "AForm.hpp"

Form::Form() : _name("Default"), _gradeToSign(0), _gradeToExecute(0)
{
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    _signed = false;
}

Form::Form(const Form &copy) : _name(copy._name), _signed(copy._signed), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
}

Form&   Form::operator=(const Form &copy)
{
    std::cout << "Assignation operator called" << std::endl;
    if (this != &copy)
    {
        _signed = copy.getSigned();
    }
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

void        Form::setSigned(bool sign)
{
    _signed = sign;
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