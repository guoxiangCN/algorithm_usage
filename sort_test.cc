
#include <iostream>
#include <algorithm>

#include "sort_bubbo.h"
#include "sort_insert.h"
#include "sort_select.h"
#include "sort_quick.h"
#include "sort_merge.h"
#include "sort_heap.h"

void test()
{
    std::vector<int> arr = {13, 12, 55, 32, 77, 123, 1, 3, -1, 777, 90};
    heapSort(arr, std::less<int>());

    std::for_each(arr.begin(), arr.end(), [](int x) -> void {
        std::cout << x << ",";
    });

    // bubboSort(arr);
    // bubboSort<int, std::greater<int> /**/>(arr);
}

int main(int argc, char **argv)
{
    test();
    return 0;
}