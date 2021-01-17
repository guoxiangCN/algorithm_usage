#pragma once

#include <algorithm>
#include <vector>


template <typename T, typename _Compare>
void insertSort(std::vector<T> &array, _Compare compare)
{
    size_t size = array.size();
    for (size_t i = 1; i < size; i++)
    {
        T &cur = array[i];
        size_t j = i - 1;
        while (j >= 0 && compare(cur, array[j]))
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = cur;
    }
}

template <typename T>
void insertSort(std::vector<T> &array)
{
    return insertSort(array, std::less<T>());
}