#include <algorithm>
#include <initializer_list>
#include <iostream>
#include <vector>

// std::minmax()  c++11 required.

int main(int argc, char **argv) {
  // examples01:
  int a = 100, b = 200;
  std::pair<int, int> minAndMax = std::minmax(a, b);
  std::cout << "min:" << minAndMax.first << " max:" << minAndMax.second
            << std::endl;

  // examples02: std::minmax(T,T,Compare)
  // example03： std:minmax(intializer_list)
  // example04： std:minmax(intializer_list,Compare)

  return 0;
}