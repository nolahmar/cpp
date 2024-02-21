/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:00:51 by nolahmar          #+#    #+#             */
/*   Updated: 2024/02/20 15:00:54 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class Form
{
    private:
        const std::string _name;
        bool _signed;
        int const _gradeToSign;
        int const _gradeToExecute;
        
        public:
            Form();
            Form(std::string name, int gradeToSign, int gradeToExecute);
            Form(const Form &copy);
            Form &operator=(const Form &copy);
            virtual ~Form();
            std::string getName() const;
            bool        getSigned() const;
            int         getGradeToSign() const;
            int         getGradeToExecute() const;
            void        setSigned(bool sign);
            virtual void        execute(Bureaucrat const & executor) const = 0;

            class GradeTooHighException : public std::exception
            {
                public:
                    virtual const char *what() const throw();
            };

            class GradeTooLowException : public std::exception
            {
                public:
                    virtual const char *what() const throw();
            };
};

std::ostream &operator<<(std::ostream &o, const Form &form);

#endif