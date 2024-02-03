/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:33:37 by nolahmar          #+#    #+#             */
/*   Updated: 2024/02/03 13:53:27 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

//Form::Form() {}

Form::~Form() {}

Form::Form(const Form& other) : _name(other.getName()), _gradeToSign(other.getGradeToSign()), _gradeToExec(other.getGradeToExec()) {}

Form& Form::operator=(const Form& other) {
   if (this != &other) {
    if ( this != &other )
        _signed = other.getSigned();
   } 
    return *this;
}

Form::Form(const std::string& name, int gradeToSign) : _name(name), _gradeToSign(gradeToSign), _gradeToExec(0) {
    if ( gradeToSign < 1 )
        throw Form::GradeTooHighException();
    if ( gradeToSign > 150 )
        throw Form::GradeTooLowException();
}

std::string Form::getName() const {
    return _name;
}

bool Form::getSigned() const {
    return _signed;
}

int Form::getGradeToSign() const {
    return _gradeToSign;
}

int Form::getGradeToExec() const {
    return _gradeToExec;
}

void    Form::beSigned(const Bureaucrat& bureaucrat) {
    if ( bureaucrat.getGrade() > _gradeToSign )
        throw Form::GradeTooLowException();
    _signed = true;
}

std::ostream& operator<<( std::ostream& o, const Form& Form ) {
    o << "Form name: " << Form.getName() << std::endl
    << "Grade to sign: " << Form.getGradeToSign() << std::endl
    << "Grade to execute: " << Form.getGradeToExec();
    return o;
}