/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 09:19:22 by nolahmar          #+#    #+#             */
/*   Updated: 2023/12/07 09:19:29 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <cstring>
#include <iostream>

void	print_upper(char *str) 
{
    int 		i;
	std::string	strUp;

    i = 0;
    while (str[i])
    {
        strUp += std::toupper(str[i]);
        i++;
    }
	std::cout << strUp;
}

int main(int argc, char **argv)
{
    int i;

    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    i = 0;
    while (++i < argc)
        print_upper(argv[i]);
    std::cout << std::endl;
	return (0);
}
