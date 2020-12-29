#include <algorithm>
#include <assert.h>
#include <iostream>
#include <string>
#include <vector>

struct mycmp {
  bool operator()(const char &a, const char &b) {
    return std::tolower(a) < std::tolower(b);
  }
};

int main(int argc, char **argv) {

  std::string foo = "AppLe";
  std::string bar = "Apple";

  // std::less<T> default.
  bool less = std::lexicographical_compare(foo.cbegin(), foo.cend(),
                                           bar.cbegin(), bar.cend());
  assert(less);

  bool less2 = std::lexicographical_compare(foo.cbegin(), foo.cend(),
                                            bar.cbegin(), bar.cend(), mycmp());
  assert(!less2);
  return 0;
}