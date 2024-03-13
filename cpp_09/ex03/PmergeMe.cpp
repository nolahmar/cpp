#include "PmergeMe.hpp"


void    is_valid_input(const std::string& str)
{
    for (size_t i = 0; i < str.size(); i++)
        if (!isdigit(str[i]))
            throw std::out_of_range("Error\n");
}

long long ft_stoi(const std::string &str)
{
    std::stringstream ss(str);
    long long value;

    if (ss >> value)
        return value;
    throw std::out_of_range("Error\n");
}

std::vector<int> merge(std::vector<int> array)
{
    if (array.size() <= 1)
        return array;
    int mid = (array.size() - 1) / 2;
    std::vector<int> leftArray(array.begin(), array.begin() + mid + 1);
    std::vector<int> rightArray(array.begin() + mid + 1 ,array.end());

    leftArray = merge(leftArray);
    rightArray = merge(rightArray);
    int n1 = leftArray.size();
    int n2 = rightArray.size();

    int i = 0;
    int j = 0;
    int k = 0;

    while (i < n1 && j < n2)
    {
        if (leftArray[i] < rightArray[j])
        {
            array[k] = leftArray[i];
            i++;
        }
        else
        {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }
    while (i  < n1) {
        array[k] = leftArray[i];
        ++k;
        ++i;
    }
    while (j  < n2) {
        array[k] = rightArray[j];
        ++k;
        ++j;
    }
    return array;
}

std::list<int> merge_list(std::list<int> linkedList)
{
    if (linkedList.size() <= 1)
        return linkedList;
    
    int mid = linkedList.size() / 2;

    std::list<int>::iterator midIter = linkedList.begin();
     for (int i = 0; i < mid; ++i)
        ++midIter;

    std::list<int> leftList(linkedList.begin(), midIter);
    std::list<int> rightList(midIter, linkedList.end());

    leftList = merge_list(leftList);
    rightList = merge_list(rightList);

    int n1 = leftList.size();
    int n2 = rightList.size();

    std::list<int>::iterator leftIter = leftList.begin();
    std::list<int>::iterator rightIter = rightList.begin();

    std::list<int> mergedList;

    int i = 0;
    int j = 0;

    while (i < n1 && j < n2)
    {
        if (*leftIter < *rightIter)
        {
            mergedList.push_back(*leftIter);
            ++leftIter;
            ++i;
        }
        else
        {
            mergedList.push_back(*rightIter);
            ++rightIter;
            ++j;
        }
    }
    while (i < n1)
    {
        mergedList.push_back(*leftIter);
        ++leftIter;
        ++i;
    }
    while (j < n2)
    {
        mergedList.push_back(*rightIter);
        ++rightIter;
        ++j;
    }
    return mergedList;
}

int binarySearch(std::vector<int>& sortedVector, int element)
{
    int start = 0;
    int end = sortedVector.size() - 1;

    while (start <= end) 
    {
        int mid = (end + start) / 2;
        if (sortedVector[mid] == element)
            return mid;
        if (sortedVector[mid] < element) 
            start = mid + 1;
        else 
            end = mid - 1;
    }
    return start;
}

std::vector<int> sort_vector(std::vector<int> inputVector) 
{
    //  std::clock_t start = std::clock();
    if (inputVector.size() < 2)
        return inputVector;
    std::vector<int> vector1;
    std::vector<int> vector2;

    for (size_t i = 0; i < inputVector.size() - 1; i += 2) 
    {
        int first_element = inputVector[i];
        int second_element  = inputVector[i + 1];

        if (first_element > second_element) 
        {
            vector1.push_back(first_element);
            vector2.push_back(second_element);
        } 
        else 
        {
            vector1.push_back(second_element);
            vector2.push_back(first_element);
        }
    }
    if (vector1.size() + vector2.size() != inputVector.size())
        vector1.push_back(inputVector.back());
    vector1 = merge(vector1);
    for (size_t i = 0; i < vector2.size(); ++i)
    {
        int elem = vector2[i];
        int index = binarySearch(vector1, elem);
        vector1.insert(vector1.begin() + index, elem);
    }
    // std::clock_t end = std::clock();
    // double time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    // std::cout << "Time to process a range of " <<  inputVector.size() << " elements with std::vector: " << time << std::endl;
    return vector1;
}

std::list<int>::iterator binarySearch_list(std::list<int>& sortedList, int element)
{
    std::list<int>::iterator start = sortedList.begin();
    std::list<int>::iterator end = sortedList.end();

    while (start != end)
    {
        std::list<int>::iterator mid = std::next(start, std::distance(start, end) / 2);

        if (*mid == element)
            return mid;
        if (*mid < element)
            start = std::next(mid);
        else
            end = mid;
    }
    return start;
}

std::list<int> sort_list(std::list<int>& inputList)
{
    //  std::clock_t start = std::clock();
    if (inputList.size() < 2)
        return inputList;

    std::list<int> list1;
    std::list<int> list2;

    std::list<int>::iterator it = inputList.begin();
    while (it != inputList.end()) {
        int first_element = *it;
        ++it;
        if (it != inputList.end()) {
            int second_element = *it;

            if (first_element > second_element) 
            {
                list1.push_back(first_element);
                list2.push_back(second_element);
            }
            else
            {
                list1.push_back(second_element);
                list2.push_back(first_element);
            }
            ++it;
        }
    }
    if (list1.size() + list2.size() != inputList.size())
        list1.push_back(inputList.back());

    list1 = merge_list(list1);
    for (std::list<int>::iterator it = list2.begin(); it != list2.end(); ++it)
    {
        std::list<int>::iterator position = binarySearch_list(list1, *it);
        list1.insert(position, *it);
    }
    // std::clock_t end = std::clock();

    // double time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    // std::cout << "Time to process a range of " << inputList.size() << "elements with std::list: "<< time << std::endl;
    return list1;
}
