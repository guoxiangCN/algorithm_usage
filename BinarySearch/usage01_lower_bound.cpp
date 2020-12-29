#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

template <typename Iter> void test(Iter begin, Iter end) {
  typename std::iterator_traits<Iter>::difference_type count;
  count = end - begin;
}

int main(int argc, char **argv) {
  std::vector<int> vec({1, 2, 3, 4, 6, 7, 8});
  test(vec.begin(), vec.end());

  int arr[] = {1, 2, 3, 4, 5, 6, 7};
  test(arr, arr + 3);

  typename std::iterator_traits<int *>::difference_type count;

  return 0;
}
