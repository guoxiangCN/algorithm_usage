#include "bytedance_sort.h"
#include <iostream>

void test()
{
    std::vector<int> arr = {13, 12, 55, 32, 77, 123, 1, 3, -1, 777, 90};
    bubboSort(arr);
    
    std::for_each(arr.begin(), arr.end(), [](int x) -> void {
        std::cout << x << std::endl;
    });

    // bubboSort(arr);
    // bubboSort<int, std::greater<int> /**/>(arr);
}

int main(int argc, char **argv)
{
    test();
    return 0;
}