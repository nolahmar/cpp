#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("Presidential Pardon Form", 25, 5)
{
    this->_target = "default";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("Presidential Pardon Form", 25, 5)
{
    this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) : Form(src)
{
    *this = src;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
    this->_target = rhs._target;
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (this->getSigned() == false)
        throw Form::GradeTooLowException();
    else if (executor.getGrade() > this->getGradeToExecute())
        throw Form::GradeTooLowException();
    else
        std::cout << this->_target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}

std::ostream &operator<<(std::ostream &o, const PresidentialPardonForm &pres)
{
    o << "Presidential Pardon Form: " << pres.getName() << ", grade to sign: " << pres.getGradeToSign() << ", grade to execute: " << pres.getGradeToExecute() << ", signed: " << pres.getSigned() << std::endl;
    return o;
}