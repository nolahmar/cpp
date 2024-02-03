/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:33:22 by nolahmar          #+#    #+#             */
/*   Updated: 2024/02/02 12:16:47 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;
class Form {
    private:
        const std::string _name;
        bool	_signed;
		const int _gradeToSign;
		const int _gradeToExec;
	public:
		Form();
		Form(const Form& other);
		Form(const std::string& name, int gradeToSign);
		~Form();
		Form& operator=(const Form& other);
		std::string getName() const;
		bool getSigned() const;
		int getGradeToSign() const;
		int getGradeToExec() const;
		void beSigned(const Bureaucrat& bureaucrat);
		
	class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw() { return "Grade too high"; }
    };
    class GradeTooLowException : public std::exception {
       	public:
            virtual const char* what() const throw() { return "Grade too low"; }
    };
};

std::ostream& operator<<(std::ostream& os, const Form& Form);

#endif
