#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char **argv) {
  std::array<int, 5> arr = {1, 2, 3, 4, 5};
  std::vector<int> vec(2);

  // just copied 2 elements.
  std::copy(arr.begin(), arr.end(), vec.begin());

  std::for_each(vec.begin(), vec.end(),
                [](const int &x) { std::cout << x << ","; });

  return 0;
}
