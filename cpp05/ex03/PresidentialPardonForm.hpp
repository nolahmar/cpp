/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:01:55 by nolahmar          #+#    #+#             */
/*   Updated: 2024/02/20 15:01:56 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTALPARDONFORM
#define PRESIDENTALPARDONFORM

#include "AForm.hpp"

class PresidentialPardonForm : public Form
{
    private:
        std::string _target;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(PresidentialPardonForm const &src);
        ~PresidentialPardonForm();
        PresidentialPardonForm& operator=(const PresidentialPardonForm &rhs);
        void execute(Bureaucrat const & executor) const;
};

std::ostream &operator<<(std::ostream &out, const PresidentialPardonForm &pres);

#endif