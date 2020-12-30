#include <algorithm>
#include <deque>
#include <forward_list>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define ASSERT assert

// template <class ForwardIterator>
//   bool is_sorted (ForwardIterator first, ForwardIterator last);

// template <class ForwardIterator, class Compare>
//   bool is_sorted (ForwardIterator first, ForwardIterator last, Compare comp);

int main(int argc, char **argv) {
  // ForwardIterator

  // 1. array
  int sortedArray[] = {1, 2, 3, 4, 5, 6};
  ASSERT(std::is_sorted(sortedArray, sortedArray + 6));
  ASSERT(!std::is_sorted(sortedArray, sortedArray + 6, std::greater<int>()));

  int partSortedArray[] = {3, 1, 2, 3, 5, 7, 8};
  ASSERT(!std::is_sorted(partSortedArray, partSortedArray + 7));
  ASSERT(std::is_sorted(partSortedArray + 1, partSortedArray + 4)); // [)

  // 2. vector iterators
  std::vector<int> v(sortedArray, sortedArray + 6);
  ASSERT(std::is_sorted(v.begin(), v.end()));
  ASSERT(!std::is_sorted(v.begin(), v.end(), std::greater<int>()));
  ASSERT(
      std::is_sorted(v.rbegin(), v.rend(), std::greater<int>())); // ATTENTATION

  // 3. list iterators
  std::list<int> list(sortedArray, sortedArray + 6);
  ASSERT(std::is_sorted(list.begin(), list.end()));

  // 4. forward_list iterators
  std::forward_list<int> flist(sortedArray, sortedArray + 6);
  ASSERT(std::is_sorted(flist.begin(), flist.end()));

  // 5. try std::set
  std::set<int> set(sortedArray, sortedArray + 6);
  ASSERT(std::is_sorted(set.begin(), set.end()));

  // 6. try set::map
  std::map<std::string, std::uint64_t> scoreMap;
  scoreMap.insert(std::make_pair("aaa", 123));
  scoreMap.insert(std::make_pair("bbb", 444));
  ASSERT(std::is_sorted(scoreMap.begin(), scoreMap.end()));

  // 7. try std::unordered_set
  // std::unordered_set<int> tmp;
  // std::hash<int>()(6);
  std::unordered_set<int> uset(sortedArray, sortedArray + 6, 2);
  // ASSERT(std::is_sorted(uset.begin(), uset.end())); // false
  for (auto &x : uset) {
    std::cout << x;
  }
  std::cout << std::endl;

  std::cout << "All Done" << std::endl;
  return 0;
}