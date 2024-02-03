/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:59:08 by nolahmar          #+#    #+#             */
/*   Updated: 2024/02/03 14:12:22 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main()
{
    try {
        Bureaucrat bureaucrat("Xxxx",11);
        Form form("formName", 10);
        bureaucrat.signForm(form);
        std::cout << form << std::endl;
    }
    catch (std::exception &error) {
        std::cout << error.what() << std::endl;
    }
    return 0;
}