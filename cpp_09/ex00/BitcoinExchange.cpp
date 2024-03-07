/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:30:14 by nolahmar          #+#    #+#             */
/*   Updated: 2024/03/06 15:11:45by nolahmar         ###   ########.fr       */
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

int BitcoinExchange::ft_stoi(const std::string &str)
{
    std::stringstream ss(str);
    int value;

    ss >> value;

    return value;
}

double BitcoinExchange::ft_stod(const std::string &str)
{
    std::stringstream ss(str);
    double value;

    ss >> value;

    return value;
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

void BitcoinExchange::isValidDate(std::string& date) {
    if (date.size() != 11)
        throw std::invalid_argument("Invalide date => " + date);
    if (date.back() != ' ')
        throw std::invalid_argument("Invalide date => " + date);
    date.pop_back();
    if (date[4] != '-' || date[7] != '-')
        throw std::invalid_argument("Invalide date => " + date);
    std::string year_str = date.substr(0, 4);
    std::string month_str = date.substr(5, 2);
    std::string day_str = date.substr(8, 2);

    if (!isdigit(year_str[0]) || !isdigit(year_str[1]) || !isdigit(year_str[2]) || !isdigit(year_str[3]))
        throw std::invalid_argument("Invalide date => " + date);
    if (!isdigit(month_str[0]) || !isdigit(month_str[1]))
        throw std::invalid_argument("Invalide date => " + date);
    if (!isdigit(day_str[0]) || !isdigit(day_str[1]))
        throw std::invalid_argument("Invalide date => " + date);
    int year = ft_stoi(year_str);
    int month = ft_stoi(month_str);
    int day = ft_stoi(day_str);

    if (year < 2009 || year > 2022 || month < 1 || month > 12 || day < 1 || day > 31)
        throw std::invalid_argument("Invalide date => " + date);
    if ((day > 30 && (month == 4 || month == 6 || month == 9 || month == 11)) || (day > 29 && month == 2))
        throw std::invalid_argument("Invalid date => " + date);
    else if (day > 31)
        throw std::invalid_argument("Invalid date => " + date);
    else if (month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            if (day > 29)
                throw std::invalid_argument("Invalid date => " + date);
        } 
            if (day > 28)
                throw std::invalid_argument("Invalid date => " + date);
        }
}

void BitcoinExchange::isValidNumber(const std::string& value) {
    size_t dote_count = 0;
    size_t space_count = 0;
    size_t minus_count = 0;
    size_t plus_count = 0;
    bool    found_digit = false;
    
    for (unsigned int  i = 0; i < value.size(); i++) {
        if (isdigit(value[i])) {
            found_digit = true;
            continue;
        }
        if (value[i] == '.') {
            ++dote_count;
            continue;
        }
        if (value[i] == ' ') {
            ++space_count;
            continue;
        }
        if (value[i] == '+') {
            ++plus_count;
            continue;
        }
        if (value[i] == '-') {
            ++minus_count;
            continue;
        }
        throw std::invalid_argument("Invalide number => " + value);
    }
    double  max_value = ft_stod(value);
    if (max_value > std::numeric_limits<int>::max())
        throw std::invalid_argument("too large a number");
    if (!found_digit)
        throw std::invalid_argument("Invalide number => " + value);
    if (dote_count > 1)
        throw std::invalid_argument("Invalide number more than one '.' in the number => " + value);
    if (space_count > 1)
        throw std::invalid_argument("Invalide number more than one space in the number => " + value);
    if (!space_count)
        throw std::invalid_argument("Invalide format (|number), the format should be (| number)");
    if (dote_count == 1 && (value[1] == '.' || value.back() == '.'))
        throw std::invalid_argument("Invalide number => " + value);
    if (!(value.front() == ' '))
        throw std::invalid_argument("Invalide number => " + value);
    if (plus_count > 1 || minus_count > 1)
        throw std::invalid_argument("Invalide number => " + value);
    if (plus_count && value[1] != '+')
        throw std::invalid_argument("Invalide number => " + value);
    if (minus_count)
        throw std::invalid_argument(" not a positive number");
}

void BitcoinExchange::readAndVerifyFile(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;

    if (!file.is_open()) {
        std::cout << "Error: File does not exist\n";
        return;
    }
    if (!std::getline(file, line) || line != "date | value") {
        std::cout << "Error: Invalid file format\n";
        file.close();
        return;
    }
     if (file.eof()) {
        std::cout << "Error: Empty file after header\n";
        file.close();
        return;
    }
    while (std::getline(file, line)) {
        size_t delim = line.find('|');
        if (delim == std::string::npos) {
            std::cout << "Error: bad input  => " << line << '\n';
            continue;
        }
        std::string date = line.substr(0, delim);
        std::string value = line.substr(delim + 1);

        try {
            isValidDate(date);
            isValidNumber(value);

            std::map<std::string, std::string>::iterator it;

            if (_data.count(date) == 1) {
                std::cout << date << " => " << value << " = " << ft_stod(_data[date]) * ft_stod(value) << std::endl;
            }
            else {
                it = _data.lower_bound(date);
                if (it != _data.begin()) {
                    --it;
                    std::cout << date << " => " << value << " = " << ft_stod(it->second) * ft_stod(value) << std::endl;
                }
                else 
                    std::cout << "Error: Date not found in map => " << date << '\n';
            }
        } 
        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
    file.close();
}
