#ifndef __BYTEDANCE_SORT_ALL_H__
#define __BYTEDANCE_SORT_ALL_H__

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
            {
                std::swap(array[j], array[j + 1]);
            }
        }
    }
}

template <typename T>
void bubboSort(std::vector<T> &array)
{
    bubboSort(array, std::less<T>());
}

template <typename T, typename _Compare>
void selectSort(std::vector<T> &array, _Compare compare)
{
    size_t size = array.size();
    for (size_t i = 0; i < size - 1; i++)
    {
        for (size_t j = i + 1; j < size; j++)
        {
            if (compare(array[j], array[i]))
            {
                std::swap(array[i], array[j]);
            }
        }
    }
}

template <typename T>
void selectSort(std::vector<T> &array)
{
    selectSort(array, std::less<T>());
}

template <typename T, typename _Compare>
void insertSort(std::vector<T> &array, _Compare compare)
{
    size_t size = array.size();
    if (size <= 1)
        return;
    for (size_t i = 1; i < size; i++)
    {
        for (size_t j = 0; j < i; j++)
        {
        }
    }
}

template <typename T, typename _Compare>
void __quickSort(std::vector<T> &array, _Compare compare)
{
}

template <typename T, typename _Compare>
void quickSort(std::vector<T> &array, _Compare compare)
{
}

template <typename T>
void quickSort(std::vector<T> &array)
{
}

template <typename T, typename _Compare>
void heapSort(std::vector<T> &array, _Compare compare)
{
}

#endif