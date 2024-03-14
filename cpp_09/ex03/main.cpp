#include "PmergeMe.hpp"

int main(int argc, char* argv[]) 
{
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <list of integers>" << std::endl;
        return 1;
    }

    for (int i = 1; i < argc; ++i) {
        try {
            is_valid_input(argv[i]);
        } catch (std::exception& e) {
            std::cout << e.what();
            return 1;
        }
    }
    std::cout << "Before:";
    for (int i = 1; i < argc; ++i)
        std::cout << " " << argv[i];
    std::cout << std::endl;
    
    std::vector<int> inputVector;
    for (int i = 1; i < argc; ++i) {
        try {
            inputVector.push_back(ft_stoi(argv[i]));
        } catch(std::exception& e) {
            std::cout << e.what();
            return 1;
        }
    }
    std::vector<int> sortedVector = sort_vector(inputVector);
    std::cout << "After:";
    for (size_t i = 0; i < sortedVector.size(); ++i) 
        std::cout << " " << sortedVector[i];
        std::cout << std::endl;
    std::clock_t start_time = std::clock();
    sort_vector(inputVector);
    std::clock_t end_time = std::clock();
    double _time = static_cast<double> (end_time - start_time) / CLOCKS_PER_SEC;
    std::cout << "Time to process a range of " << inputVector.size() << " elements with std::vector: " << _time << " us" << std::endl;
    std::list<int> inputList(inputVector.begin(), inputVector.end());
    std::list<int> sortedList = sort_list(inputList);
    start_time = std::clock();
    sort_list(inputList);
    end_time = std::clock();
    _time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
    std::cout << "Time to process a range of " << inputList.size() << " elements with std::list: " << _time << " us" << std::endl;
    return 0;
}
