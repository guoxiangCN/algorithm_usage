#include <algorithm>
#include <deque>
#include <iostream>
#include <list>
#include <string>
#include <vector>

// template <class RandomAccessIterator>
//   void stable_sort ( RandomAccessIterator first, RandomAccessIterator last );

// template <class RandomAccessIterator, class Compare>
//   void stable_sort ( RandomAccessIterator first, RandomAccessIterator last,
//                      Compare comp );

int main(int argc, char **argv) {
  std::vector<std::string> names;
  names.assign({"Bbbb", "Cccc", "Zzz", "Kkk", "Hhhh", "Aaaa"});

  std::stable_sort(names.begin(), names.end());
  std::for_each(names.begin(), names.end(),
                [](const std::string &str) { std::cout << str << std::endl; });

  return 0;
}