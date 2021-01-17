#pragma once

#include <algorithm>
#include <vector>

template <typename T, typename _Compare>
void selectSort(std::vector<T> &array, _Compare compare)
{
    size_t size = array.size();
    for (size_t i = 0; i < size - 1; i++)
    {
        for (size_t j = i + 1; j < size; j++)
        {
            if (compare(array[j], array[i]))
                std::swap(array[i], array[j]);
        }
    }
}

template <typename T>
void selectSort(std::vector<T> &array)
{
    selectSort(array, std::less<T>());
}