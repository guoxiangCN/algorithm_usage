#ifndef __SORT_H__
#define __SORT_H__

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
template <typename T, typename Compare>
void quickSortPartition(std::vector<T> &arr, Compare compare, int left, int right)
{
    if(left >= right) return;

    size_t savedLeft = left;
    size_t savedRight = right;

    T pivot = arr[left];
    while(left < right)
    {
        while(left < right && !compare(arr[right], pivot))
        {
           right--;
        }

        if(left <right) {
             arr[left] = arr[right];
            left++;
        }
       

        while(left < right && compare(arr[left], pivot))
        {
            left++;
        }   

        if(left < right) {
            arr[right] = arr[left];
            right--;
        }
    }
    arr[left] = pivot;
    quickSortPartition(arr, compare, savedLeft, left-1);
    quickSortPartition(arr, compare, left + 1, savedRight);
}

// n * log2 N  -> 0(n^2)
template <typename T, typename Compare>
void quickSort(std::vector<T> &arr, Compare compare)
{
    int size = arr.size();
    if(size == 0) return;
    int left = 0, right = size - 1;
    quickSortPartition(arr, compare, left, right);
}

template <typename T>
void quickSort(std::vector<T> &arr)
{
    quickSort(arr, std::less<T>());
}


// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// 归并排序 O(n * logN)

template <typename T, typename Compare>
void mergemerge(std::vector<T> &array, Compare compare, int i, int j, int mid)
{

}

template <typename T, typename Compare>
void mergeSort0(std::vector<T> &array, Compare compare, int i, int j)
{
    if(i >= j) return;



    int mid = (i + j) /2;
    mergeSort0(array, compare, i, mid);
    mergeSort0(array, compare, mid + 1, j);
    mergemerge(array, compare, i, j, mid);
}

template <typename T, typename Compare>
void mergeSort(std::vector<T> &array, Compare compare)
{
    
}

template <typename T>
void mergeSort(std::vector<T> &array)
{
    mergeSort(array, std::less<T>());
}

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// 堆排序 
template <typename T>
void heapSort(std::vector<T> &array)
{
    // fixme
}

#endif