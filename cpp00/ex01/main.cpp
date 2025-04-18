/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 09:20:04 by nolahmar          #+#    #+#             */
/*   Updated: 2023/12/09 10:23:55 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

void endoffile(){
    if (std::cin.eof()){
        std::cout << "End of file encountered. Exiting program.\n";
        exit(1);
    }
}

int main() {
    PhoneBook phoneBook;
    std::string command;

    while (true) {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);
            endoffile();
        if (command == "ADD") {
            endoffile();
            phoneBook.addContact();
        } else if (command == "SEARCH") {
            endoffile();
            phoneBook.searchContacts();
        } else if (command == "EXIT") {
            std::cout << "Exiting program. Contacts will be lost forever.\n";
            break;
        } else {
            std::cout << "Invalid command. Discarding input.\n";
        }
    }
    return 0;
}
