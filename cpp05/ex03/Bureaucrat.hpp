/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noni <noni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:59:46 by nolahmar          #+#    #+#             */
/*   Updated: 2024/02/21 16:27:27 by noni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>
# include <string>

class AForm;

class Bureaucrat
{
    private:
        std::string const   _name;
        int                 _grade;
    public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(Bureaucrat const & src);
        ~Bureaucrat();
        Bureaucrat&    operator=(const Bureaucrat &rhs);

        std::string   getName() const;
        int           getGrade() const;

        void          incrementGrade();
        void          decrementGrade();

        void    signForm(AForm &form);
        void    executeForm(AForm const & form) const;


        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream &  operator<<(std::ostream & o, Bureaucrat const & rhs);

#endif
