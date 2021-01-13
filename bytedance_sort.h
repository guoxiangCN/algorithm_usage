#ifndef __BYTEDANCE_SORT_ALL_H__
#define __BYTEDANCE_SORT_ALL_H__

#include <vector>    // use vector instead of array.
#include <cstddef>   // just for std::size_t
#include <algorithm> // just for std::swap and std::less
#include <iostream>  // just for debug and can be removed.
#include <thread>    // just for debug and can be removed.

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

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

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

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

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

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

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
template <typename T, typename _Compare>
size_t __quickSortPartition(std::vector<T> &array, _Compare compare, size_t first, size_t last)
{
    T &pivot = array[first];
    while (first < last)
    {
        while (first < last && !compare(array[last], pivot)) // last >= pivot
        {
            last--;
        }

        array[first] = array[last];

        while (
            first < last && 
            (   
                compare(array[first], pivot) 
                ||
                ( !compare(array[first], pivot) && !compare(pivot, array[first]))   // a<b=false && b<a=false 则代表a==b
            )
        ) 
        {
            first++;
        }
        array[last] = array[first];
    }
    array[first] = pivot;
    return first;
}

template <typename T, typename _Compare>
void __quickSort(std::vector<T> &array, _Compare compare, size_t first, size_t last)
{
    if (first >= last)
        return;
    size_t pivotPos = __quickSortPartition(array, compare, first, last);
    __quickSort(array, compare, first, pivotPos - 1);
    __quickSort(array, compare, pivotPos + 1, last);
}

template <typename T, typename _Compare>
void quickSort(std::vector<T> &array, _Compare compare)
{
    std::size_t size = array.size();
    if (!size)
        return;
    __quickSort(array, compare, 0, size - 1);
}

template <typename T>
void quickSort(std::vector<T> &array)
{
    return quickSort(array, std::less<T>());
}

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

template <typename T, typename _Compare>
void heapSort(std::vector<T> &array, _Compare compare)
{
    // fixme
}

template <typename T>
void heapSort(std::vector<T> &array)
{
    // fixme
}

#endif