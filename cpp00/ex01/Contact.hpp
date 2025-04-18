/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 09:17:26 by nolahmar          #+#    #+#             */
/*   Updated: 2023/12/08 09:17:29 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>
#include <iostream>
#include <iomanip>

class Contact {
    private:
        std::string _firstName;
        std::string _lastName;
        std::string _nickname;
        std::string _phoneNumber;
        std::string _darkestSecret;

    public:
        std::string getFirstName() const ;
        void setFirstName(const std::string& value) ;

        std::string getLastName() const;
        void setLastName(const std::string& value) ;

        std::string getNickname() const ;
        void setNickname(const std::string& value) ;

        std::string getPhoneNumber() const ;
        void setPhoneNumber(const std::string& value) ;

        std::string getDarkestSecret() const ;
        void setDarkestSecret(const std::string& value) ;
        void displayContactInfo() const;
};

#endif
