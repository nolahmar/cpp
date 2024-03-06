/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:52:47 by nolahmar          #+#    #+#             */
/*   Updated: 2024/03/06 16:30:57 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANDE_HPP
#define BITCOINEXCHANDE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <exception>
#include <limits>

class BitcoinExchange {
    private:
        std::map<std::string, std::string> _data;
        std::map<std::string, std::string> _date;
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& copy);
        ~BitcoinExchange();
        BitcoinExchange& operator=(const BitcoinExchange &rhs);
        void read_data(const std::string& filename);
        void isValidDate(std::string& date);
        void readAndVerifyFile(const std::string& filename);
        void isValidNumber(const std::string& value) ;
        bool isEmpty() const;
        bool isValidMonthLength(const std::string& date) const;
        void countMonthDays();
};


#endif
