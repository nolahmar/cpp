/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 09:17:08 by nolahmar          #+#    #+#             */
/*   Updated: 2023/12/08 09:17:13 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <limits>

const int MAX_CONTACTS = 8;

class PhoneBook {
    private:
        Contact _contacts[MAX_CONTACTS];
        int     _contactCount;
        int     _index;

    public:
        PhoneBook();
        void addContact();
        void searchContacts();

    private:
        std::string _truncateString(const std::string& str) const;
        bool _isDigit(const std::string& chaine) const;
};

#endif // PHONEBOOK_H
