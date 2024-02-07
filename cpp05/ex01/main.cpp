/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:59:59 by nolahmar          #+#    #+#             */
/*   Updated: 2024/02/07 12:00:02 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try {
        Bureaucrat bureaucrat("Xxxx",11);
        Form form("formName", 10, 20);
        bureaucrat.signForm(form);
        std::cout << form << std::endl;
    }
    catch (std::exception &error) {
        std::cout << error.what() << std::endl;
    }
    return 0;
}