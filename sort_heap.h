#pragma once

#include <algorithm>
#include <vector>

/**
 * arr
 * compare
 * adjustPos 需要调整的数组的索引位置
 */
template <typename T, typename Compare>
void adjustHeap(std::vector<T> &arr, Compare compare, int adjustPos)
{
    int maxPos = arr.size() - 1;
    int toBeParentPos = adjustPos;

    int leftPos = 2 * adjustPos + 1;
    int rightPos = 2 * adjustPos + 2;

    if (leftPos <= maxPos && compare(arr[leftPos], arr[toBeParentPos]))
        toBeParentPos = leftPos;
    if (rightPos <= maxPos && compare(arr[rightPos], arr[toBeParentPos]))
        toBeParentPos = rightPos;

    if (toBeParentPos != adjustPos)
    {
        std::swap(arr[toBeParentPos], arr[adjustPos]);
        adjustHeap(arr, compare, toBeParentPos);
    }
}

template <typename T, typename Compare>
void heapSort(std::vector<T> &arr, Compare compare)
{
    // 无顺序数组变成堆, 需要从最后的节点往堆顶维护 O(N)
    for (int i = (arr.size() / 2) - 1  ; i >= 0; i--)
    {
        adjustHeap(arr, compare, i);
    }
    
    // 排序
}