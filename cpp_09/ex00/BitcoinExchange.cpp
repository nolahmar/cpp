/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noni <noni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:30:14 by nolahmar          #+#    #+#             */
/*   Updated: 2024/03/05 20:51:57 by noni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
    *this = copy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
    {
        _data = other._data;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
    
}

bool BitcoinExchange::isEmpty() const
{
    return _data.empty();
}

void BitcoinExchange::read_data(const std::string& filename)
{
    size_t delim;
   std::ifstream file(filename);
   if (!file.is_open()) {
    std::cerr << "Error opening file: " << filename << std::endl;
    return ;
   }
   std::string line;
   std::getline(file, line);
   
   while (std::getline(file, line)) {
    delim = line.find(',');
    if (delim != std::string::npos) {
        std::string date = line.substr(0, delim);
        std::string value = line.substr(delim + 1);
        _data[date] = value;
    }
   }
   file.close();
}

bool BitcoinExchange::isValidDate(const std::string& date) {
    if (date.size() != 10)
        return false; 
    if (date[4] != '-' || date[7] != '-')
        return false;
    std::string yearStr = date.substr(0, 4);
    std::string monthStr = date.substr(5, 2);
    std::string dayStr = date.substr(8, 2);
    try {
        int year = std::stoi(yearStr);
        int month = std::stoi(monthStr);
        int day = std::stoi(dayStr);

        if (year < 2009 || year > 2022 || month < 1 || month > 12 || day < 1 || day > 31)
            return false;
        return true;
    } 
    catch (const std::exception& e) {
        return false;
    }
}

bool BitcoinExchange::isValidNumber(const std::string& value) {
    try {
        size_t pos = 0;
        //double number = std::stod(value, &pos);
        if (pos != value.size()) 
            throw std::invalid_argument("Error: Invalid characters after number.");
        if (value.back() == '.') 
            throw std::invalid_argument("Error: Number cannot end with a point.");
        size_t dotCount = std::count(value.begin(), value.end(), '.');
        if (dotCount > 1)
            throw std::invalid_argument("Error: More than one '.' in the number.");
        size_t afterPos = value.find_first_not_of(" \t", pos);
        if (afterPos != std::string::npos) 
            throw std::invalid_argument("Error: Invalid characters after number.");
        return true;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return false;
    }
}

void BitcoinExchange::readAndVerifyFile(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;

    if (!file.is_open()) {
        std::cout << "Error: File does not exist\n";
        return;
    }
    if (!std::getline(file, line) || line != "date | value") {
        std::cout << "Error: Format de fichier invalide\n";
        return;
    }
    while (std::getline(file, line)) {
        size_t delim = line.find('|');
        if (delim == std::string::npos) {
            std::cout << "Error: Format de ligne invalide => " << line << '\n';
            continue;
        }
        std::string date = line.substr(0, delim);
        std::string value = line.substr(delim + 1);

        try {
            if (!isValidDate(date)) {
                throw std::invalid_argument("Erreur: Date invalide => " + date);
            }
            if (!isValidNumber(value)) {
                throw std::invalid_argument("Erreur: Numbre invalide => " + value);
            }
            std::map<std::string, std::string>::iterator it;
            it = _data.lower_bound(date);
          if (it != _data.end()) {
                std::cout << date << " => " << value << " = "
                          << std::stod(it->second) * std::stod(value) << std::endl;
            } 
            else 
                std::cout << "Error: Date not found in map => " << date << '\n';
        } 
        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
    file.close();
}

bool BitcoinExchange::isValidMonthLength(const std::string& date) const 
{
    int year = std::stoi(date.substr(0, 4));
    int month = std::stoi(date.substr(5, 2));

    if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12))
        return true;  // Months with 31 days
    else if (month == 4 || month == 6 || month == 9 || month == 11)
        return true;  // Months with 30 days
    else if (month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            return true; // Fevrier 29
        else 
            return false;
    }
    else 
        return false;  // Invalid month
}
