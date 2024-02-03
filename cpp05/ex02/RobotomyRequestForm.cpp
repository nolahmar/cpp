/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 14:18:16 by nolahmar          #+#    #+#             */
/*   Updated: 2024/02/03 16:22:51 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm():Form("Robotomy", 72, 45) {
    this->_target = "default";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) {
    this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : Form(src) {
    *this = src;
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
    this->_target = other._target;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const RobotomyRequestForm &robot) {
    os << "Robotomy Request From:" << robot.getName() << ", grade to sign: " << robot.getGradeToSign() << ", grade to execute: " << robot.getGradeToExec() << ", signed :" << robot.getSigned() << std::endl;
    return os;
}