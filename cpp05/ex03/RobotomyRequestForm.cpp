/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:02:01 by nolahmar          #+#    #+#             */
/*   Updated: 2024/02/20 15:02:02 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("Robotomy Request Form", 72, 45)
{
    this->_target = "default";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("Robotomy Request Form", 72, 45)
{
    this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : Form(src)
{
    *this = src;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
    this->_target = rhs._target;
    return *this;
}

void    RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (this->getSigned() == false)
        throw Form::GradeTooLowException();
    else if (executor.getGrade() > this->getGradeToExecute())
        throw Form::GradeTooLowException();
    else
    {
        std::cout << "Drilling noises" << std::endl;
        if (rand() % 2 == 0)
            std::cout << this->_target << " has been robotomized successfully" << std::endl;
        else
            std::cout << this->_target << " robotomization failed" << std::endl;
    }
}

std::ostream &operator<<(std::ostream &o, const RobotomyRequestForm &robot)
{
    o << "Robotomy Request Form: " << robot.getName() << ", grade to sign: " << robot.getGradeToSign() << ", grade to execute: " << robot.getGradeToExecute() << ", signed: " << robot.getSigned() << std::endl;
    return o;
}