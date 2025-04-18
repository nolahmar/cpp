/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 09:17:34 by nolahmar          #+#    #+#             */
/*   Updated: 2023/12/08 09:17:39 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::displayContactInfo() const {
    std::cout << "First Name: " << _firstName << std::endl;
    std::cout << "Last Name: " << _lastName << std::endl;
    std::cout << "Nickname: " << _nickname << std::endl;
    std::cout << "Phone Number: " << _phoneNumber << std::endl;
    std::cout << "Darkest Secret: " << _darkestSecret << std::endl;
}

std::string Contact::getFirstName() const { 
    return _firstName;
}

void Contact::setFirstName(const std::string& value) { 
    _firstName = value; 
}

std::string Contact::getLastName() const { 
    return _lastName; 
}

void Contact::setLastName(const std::string& value) {
     _lastName = value; 
}

std::string Contact::getNickname() const {
    return _nickname; 
}

void Contact::setNickname(const std::string& value) { 
    _nickname = value; 
}

std::string Contact::getPhoneNumber() const { 
    return _phoneNumber; 
}

void Contact::setPhoneNumber(const std::string& value) {
    _phoneNumber = value; 
}

std::string Contact::getDarkestSecret() const { 
    return _darkestSecret; 
}

void Contact::setDarkestSecret(const std::string& value) { 
    _darkestSecret = value; 
}
