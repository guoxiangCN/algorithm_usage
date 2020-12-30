#include "chrono_traits.h"
#include <iostream>

int main(int argc, char **argv) {
  bool isD = is_duration<int>::value;
  bool isD1 = is_duration<std::chrono::duration<int, int> /**/>::value;

  std::cout << "isD:" << std::boolalpha << isD << std::endl;
  std::cout << "isD1:" << std::boolalpha << isD1 << std::endl;
  // false  true
  return 0;
}