#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <vector>

// 字典序的下一个排列  可以实现全排列

int main(int argc, char **argv) {
  std::string foobar = "abc";

  do {
    std::cout << foobar << std::endl;
  } while (std::next_permutation(foobar.begin(), foobar.end()));

  /*
  abc
  acb
  bac
  bca
  cab
  cba
  */
  return 0;
}