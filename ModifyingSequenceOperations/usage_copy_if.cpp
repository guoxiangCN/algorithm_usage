#include "../my_algorithm.h"
#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char **argv) {

  //
  std::array<int, 10> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  // std::vector<int> v; core dump
  std::vector<int> v(arr.size());

  // auto outIter = std::copy_if(arr.begin(), arr.end(), v.begin(), [](const int
  // &x) { return x % 2 != 0; });

  auto outIter = my::copy_if(arr.begin(), arr.end(), v.begin(),
                             [](const int &x) { return x % 2 != 0; });
  v.resize(std::distance(v.begin(), outIter));

  for (const auto &x : v) {
    std::cout << x << ",";
  }

  v.resize(0);
  return 0;
}