#pragma once

#include <algorithm>
#include <vector>


template <typename T, typename _Compare>
void bubboSort(std::vector<T> &array, _Compare compare)
{
    std::size_t size = array.size();
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size - i - 1; j++)
        {
            if (compare(array[j + 1], array[j]))
                std::swap(array[j], array[j + 1]);
        }
    }
}

template <typename T>
void bubboSort(std::vector<T> &array)
{
    bubboSort(array, std::less<T>());
}