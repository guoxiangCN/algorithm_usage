#include <algorithm>
#include <array>
#include <chrono>
#include <deque>
#include <forward_list>
#include <iostream>
#include <list>
#include <map>
#include <random>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define ASSERT assert

// 只排nth位置的，其他的不保证顺序

// template <class RandomAccessIterator>
//   void nth_element (RandomAccessIterator first, RandomAccessIterator nth,
//                     RandomAccessIterator last);

// template <class RandomAccessIterator, class Compare>
//   void nth_element (RandomAccessIterator first, RandomAccessIterator nth,
//                     RandomAccessIterator last, Compare comp);

int main(int argc, char **argv) {
  // RandomAccess: std::vector<T>  std::deque<T>
  std::vector<int> v;
  for (size_t i = 1; i < 10; i++) {
    v.push_back(i);
  }

  auto seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::shuffle(v.begin(), v.end(), std::default_random_engine(seed));

  std::for_each(v.cbegin(), v.cend(),
                [](const int &x) { std::cout << x << ", "; });

  std::cout << std::endl;

  std::nth_element(v.begin(), v.begin() + 2, v.end());
  std::for_each(v.cbegin(), v.cend(),
                [](const int &x) { std::cout << x << ", "; });
  return 0;
}