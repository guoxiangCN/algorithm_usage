#pragma once

#include <algorithm>
#include <vector>

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