/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:28:41 by nolahmar          #+#    #+#             */
/*   Updated: 2024/02/13 14:51:19 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Template.hpp"

int main( void ) {
int a = 2;
int b = 3;
::swap( a, b );
std::cout << "a = " << a << ", b = " << b << std::endl;
std::cout << "min(a, b) = " << ::min( a, b ) << std::endl;
std::cout << "max(a, b) = " << ::max( a, b ) << std::endl;
std::string c = "chaine1";
std::string d = "chaine2";
::swap(c, d);
std::cout << "c = " << c << ", d = " << d << std::endl;
std::cout << "min(c, d) = " << ::min( c, d ) << std::endl;
std::cout << "max(c, d) = " << ::max( c, d ) << std::endl;
return 0;
}