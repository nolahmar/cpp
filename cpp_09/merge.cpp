#include <iostream>
#include <vector>
#include <list>

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
    return vector1;
}

int main()
{
    std::vector<int> v;
    v.push_back(5);
    v.push_back(-1);
    v.push_back(5);
    v.push_back(5);
    v.push_back(5);
    // v.push_back(80);
    // v.push_back(122);
    //v = merge(v);
    v = sort_vector(v);
    for (int i = 0; i < v.size(); ++i)
        std::cout << v[i] << std::endl; 
}

// int main()
// {
//     std::list<int> v;
//     v.push_back(5);
//     v.push_back(344);
//     v.push_back(-4567);
//     // v.push_back(0);
//     v = merge_list(v);
//     for (std::list<int>::iterator it = v.begin(); it != v.end(); ++it) 
//         std::cout << *it << std::endl;
//     return 0;
// }
