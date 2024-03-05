/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noni <noni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:52:47 by nolahmar          #+#    #+#             */
/*   Updated: 2024/03/05 20:51:51 by noni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANDE_HPP
#define BITCOINEXCHANDE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <exception>

class BitcoinExchange {
    private:
        std::map<std::string, std::string> _data;
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& copy);
        ~BitcoinExchange();
        BitcoinExchange& operator=(const BitcoinExchange &rhs);
        void read_data(const std::string& filename);
        bool isValidDate(const std::string& date);
        void readAndVerifyFile(const std::string& filename);
        bool isValidNumber(const std::string& value) ;
        bool isEmpty() const;
        bool isValidMonthLength(const std::string& date) const;
};


#endif