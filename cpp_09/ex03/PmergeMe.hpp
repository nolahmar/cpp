#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <ctime>
#include <sstream>
#include <exception>

std::vector<int> sort_vector(std::vector<int> inputVector);
std::list<int> sort_list(std::list<int>& inputList);
long long ft_stoi(const std::string &str);
void    is_valid_input(const std::string& str);

#endif