/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 09:20:38 by nolahmar          #+#    #+#             */
/*   Updated: 2023/12/08 16:36:44 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook() 
{
    _contactCount = 0;
    _index = 0;
}

void PhoneBook::addContact() {
    if(MAX_CONTACTS < 1)
        std::cout << "Invalid operation.\n";
    else {
    // A saved contact can’t have empty fields
    Contact newContact;
    std::cout << "Enter first name: ";
    std::string firstNameInput;
    std::getline(std::cin, firstNameInput); 
    if (!firstNameInput.size())
    {
        std::cout << "Can't save a contact with an empty field: " \
            "First Name is empty" << std::endl;
        return;
    }
    newContact.setFirstName(firstNameInput);

    std::cout << "Enter last name: ";
    std::string lastNameInput;
    std::getline(std::cin, lastNameInput);
    if (!lastNameInput.size())
    {
        std::cout << "Can't save a contact with an empty field: " \
            "Last Name is empty" << std::endl;
        return;
    }
    newContact.setLastName(lastNameInput);

    std::cout << "Enter nickname: ";
    std::string nicknameInput;
    std::getline(std::cin, nicknameInput);
    if (!nicknameInput.size())
    {
        std::cout << "Can't save a contact with an empty field: " \
            "Nick Name is empty" << std::endl;
        return;
    }
    newContact.setNickname(nicknameInput);

    std::cout << "Enter phone number: ";
    std::string phoneNumberInput;
    std::getline(std::cin, phoneNumberInput);
    if (!phoneNumberInput.size())
    {
        std::cout << "Can't save a contact with an empty field: " \
            "Phone Number is empty" << std::endl;
        return;
    }
    newContact.setPhoneNumber(phoneNumberInput);

    std::cout << "Enter darkest secret: ";
    std::string darkestSecretInput;
    std::getline(std::cin, darkestSecretInput);
    if (!darkestSecretInput.size())
    {
        std::cout << "Can't save a contact with an empty field: " \
            "Darkest Secret is empty" << std::endl;
        return;
    }
    newContact.setDarkestSecret(darkestSecretInput);
    _contacts[_index] = newContact;
    _index++;
    if (_contactCount < 8)
    _contactCount++;
    if (_index == MAX_CONTACTS)
        _index = 0;
    std::cout << "Contact added successfully.\n";
    }
}

void PhoneBook::searchContacts() {
    if (_contactCount == 0) {
        std::cout << "PhoneBook is empty.\n";
        return;
    }

    // Display header
    std::cout << std::setw(10) << std::right << "Index" << "|"
        << std::setw(10) << std::right << "First Name" << "|"
        << std::setw(10) << std::right << "Last Name" << "|"
        << std::setw(10) << std::right << "Nickname" << std::endl;

    // Display contacts
    for (int i = 0; i < _contactCount; ++i) {
        std::cout << std::setw(10) << std::right << i << "|"
            << std::setw(10) << std::right << _truncateString(_contacts[i].getFirstName()) << "|"
            << std::setw(10) << std::right << _truncateString(_contacts[i].getLastName()) << "|"
            << std::setw(10) << std::right << _truncateString(_contacts[i].getNickname()) << std::endl;
    }

    // Prompt for index
    int index;
    std::cout << "Enter the index of the desired entry: ";
    std::string indexString;
    std::getline(std::cin,indexString);
    if((!_isDigit(indexString)) || (indexString.empty() )){
            std::cout << "Invalid index.\n";
            return;
    }
    index = atoi(indexString.c_str());
    if (index >= 0 && index < _contactCount) {
        // Display contact information
        std::cout << "First Name: " << _contacts[index].getFirstName() << std::endl;
        std::cout << "Last Name: " << _contacts[index].getLastName() << std::endl;
        std::cout << "Nickname: " << _contacts[index].getNickname() << std::endl;
        std::cout << "Phone Number: " << _contacts[index].getPhoneNumber() << std::endl;
        std::cout << "Darkest Secret: " << _contacts[index].getDarkestSecret() << std::endl;
    } else {
        std::cout << "Invalid index.\n";
        return;
    }
}

bool PhoneBook::_isDigit(const std::string& chaine) const {
    for (std::size_t i = 0; i < chaine.size(); ++i) {
        if (!std::isdigit(chaine[i])) {
            return false;
        }
    }
    return true;
}

std::string PhoneBook::_truncateString(const std::string& str) const {
    unsigned int width = 10;

    if (str.length() <= width) {
        return str;
    } else {
        return str.substr(0, width - 1) + ".";
    }
}
