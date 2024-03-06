/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noni <noni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:52:47 by nolahmar          #+#    #+#             */
/*   Updated: 2024/03/06 19:34:23 by noni             ###   ########.fr       */
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
#include <sstream>

class BitcoinExchange {
    private:
        std::map<std::string, std::string> _data;
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& copy);
        ~BitcoinExchange();
        BitcoinExchange& operator=(const BitcoinExchange &rhs);
        void read_data(const std::string& filename);
        void isValidDate(std::string& date);
        void readAndVerifyFile(const std::string& filename);
        void isValidNumber(const std::string& value) ;
        int ft_stoi(const std::string &str);
        double ft_stod(const std::string &str);
};


#endif
