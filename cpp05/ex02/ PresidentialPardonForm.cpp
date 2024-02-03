/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    PresidentialPardonForm.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 14:18:54 by nolahmar          #+#    #+#             */
/*   Updated: 2024/02/03 16:21:38 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): Form("Presidential", 25, 5) {
    this->_target = "default";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) {
    this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) : Form(src) {
    *this = src;
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs) {
    this->_target = rhs._target;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const PresidentialPardonForm &pres) {
    os << "Presidential Pardon Form: " << pres.getName() << ", grade to sign: " << pres.getGradeToSign() << ", grade to execute: " << pres.getGradeToExec() << ", signed: " << pres.getSigned() << std::endl;
    return os;
}
