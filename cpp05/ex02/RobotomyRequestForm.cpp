/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noni <noni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 14:18:16 by nolahmar          #+#    #+#             */
/*   Updated: 2024/02/21 16:15:06 by noni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request Form", 72, 45)
{
    _target = "default";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Request Form", 72, 45)
{
    _target = target;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src): AForm(src)
{
    *this = src;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
    AForm::operator=(rhs);
    _target = rhs._target;
    return *this;
}

void    RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (!getSigned())
        throw AForm::AFormNotSignedException();
    if (executor.getGrade() > getGradeToExecute())
        throw AForm::CouldNotExecuteException();

    std::cout << "Drrrrrrrrrrrr..." << std::endl;
    srand(time(0));
    if (rand() % 2 == 0)
        std::cout << _target << " has been robotomized successfully" << std::endl;
    else
        std::cout << _target << " robotomization failed" << std::endl;
}
