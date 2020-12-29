#include <algorithm>
#include <initializer_list>
#include <iostream>
#include <vector>

#define ARRAY_LEN(arr) (sizeof(arr) / sizeof(arr[0]))

// std::min based on range iterators

int main(int argc, char **argv) {
  int arr[] = {3, 5, 6, 1, 2, 66, 77, 99, 189, 29};
  int *minElePtr = std::min_element(arr, arr + ARRAY_LEN(arr));
  std::cout << "minElePtr:" << minElePtr << ", minEle:" << *minElePtr
            << std::endl;
  // minElePtr:0x7ffee2c7a85c, minEle:1

  std::vector<int> v({1, 2, 3, 4, 5, 6, 0});

  std::vector<int>::const_iterator it = std::min_element(v.cbegin(), v.cend());
  std::cout << "minElementOfVector:" << *it << std::endl; // 0

  return 0;
}