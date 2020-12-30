// default (1)
// template <class RandomAccessIterator>
//   void sort (RandomAccessIterator first, RandomAccessIterator last);
// custom (2)
// template <class RandomAccessIterator, class Compare>
//   void sort (RandomAccessIterator first, RandomAccessIterator last, Compare
//   comp);

#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <vector>

// RandomAccessContainer in cpp:    std::vector<T>, std::deque<T>
// RandomAccessContaioner in java:

int main(int argc, char **argv) {
  // NO LINT

  // std::list<int> list({1, 2, 5, 7, 2, 3, 99, 12});
  // std::sort(list.begin(), list.end());
  // auto x = list.begin() + 3; list不支持随机访问

  std::vector<int> vec({1, 2, 3, 4, 5});
  std::sort(vec.begin(), vec.end());

  for (auto &x : vec) {
    std::cout << x << ",";
  }

  std::cout << std::endl;

  std::list<int> list({1, 2, 5, 7, 2, 3, 99, 12});
  list.sort();
  for (auto &x : list) {
    std::cout << x << ",";
  }

  std::cout << std::endl;
  list.sort(std::greater<std::list<int>::value_type>());
  for (auto &x : list) {
    std::cout << x << ",";
  }

  return 0;
}