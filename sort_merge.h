#pragma once

#include <algorithm>
#include <vector>

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