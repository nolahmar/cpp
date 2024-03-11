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
    std::list<int> leftlist(linkedList.begin(), linkedList.begin() + mid);
    std::list<int> rightlist(linkedList.begin() + mid, linkedList.end());
}

int main()
{
    std::vector<int> v;
    v.push_back(5);
    v.push_back(3);
    v.push_back(-1);
    v.push_back(3);
    v = merge(v);
    for (int i = 0; i < v.size(); ++i)
        std::cout << v[i] << std::endl; 
}