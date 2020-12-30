#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char **argv) {
  std::array<int, 10> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  // std::vector<int> v; core dump
  std::vector<int> v(5);

  for (const auto &x : v) {
    std::cout << x << ",";
  }
  return 0;
}