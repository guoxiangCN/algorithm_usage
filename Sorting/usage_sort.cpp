// default (1)
// template <class RandomAccessIterator>
//   void sort (RandomAccessIterator first, RandomAccessIterator last);
// custom (2)
// template <class RandomAccessIterator, class Compare>
//   void sort (RandomAccessIterator first, RandomAccessIterator last, Compare
//   comp);

#include <algorithm>
#include <deque>
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

  std::cout << "========" << std::endl;

  // deque
  std::deque<int> dq;
  dq.push_back(1);
  dq.pop_front();
  dq.push_front(2);
  dq.pop_back();

  dq.assign({2, 3, 1, 5, 7, 6, 99, 12, 32, 24});
  std::sort(dq.begin(), dq.end());
  for (auto &x : dq) {
    std::cout << x << ",";
  }

  std::cout << "========" << std::endl;
  std::sort(dq.begin(), dq.end(), std::greater<int>());
  for (auto &x : dq) {
    std::cout << x << ",";
  }
  return 0;
}