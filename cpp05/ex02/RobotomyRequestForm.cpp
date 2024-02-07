/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 14:18:16 by nolahmar          #+#    #+#             */
/*   Updated: 2024/02/07 13:12:39 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("Robotomy Request Form", 72, 45)
{
    _target = "default";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("Robotomy Request Form", 72, 45)
{
    _target = target;
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
    _target = rhs._target;
    return *this;
}

void    RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (getSigned() == false)
        throw Form::FormNotSignedException();
    else if (executor.getGrade() > getGradeToExecute())
        throw Form::GradeTooLowException();
    else
    {
        std::cout << "Drilling noises" << std::endl;
        srand(time(0));
        if (rand() % 2 == 0)
        {
            std::cout << _target << " has been robotomized successfully" << std::endl;
        }
        else
        {
            std::cout << _target << " robotomization failed" << std::endl;
        }
    }
}

std::ostream &operator<<(std::ostream &out, const RobotomyRequestForm &robot)
{
    out << "Robotomy Request Form: " << robot.getName() << ", grade to sign: " << robot.getGradeToSign() << ", grade to execute: " << robot.getGradeToExecute() << ", signed: " << robot.getSigned() << std::endl;
    return out;
}