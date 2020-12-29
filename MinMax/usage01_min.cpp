#include <algorithm>
#include <initializer_list>
#include <iostream>
#include <vector>

struct User {
  int age;
};

inline std::ostream &operator<<(std::ostream &stream, User &u) {
  stream << "struct User { age:" << u.age << "}";
  return stream;
}

int main(int argc, char **argv) {

  // example1: simple compare with <
  int a = 100;
  int b = 200;
  int max = std::min(a, b);
  std::cout << "max:" << max << std::endl; // max:100

  // example02: simple compare with Compare
  int max2 = std::min(a, b, [](int x, int y) -> bool { return x > y; });
  std::cout << "max2:" << max2 << std::endl; // max2: 200

  User user1 = {100};
  User user2 = {200};
  User minUser =
      std::min(user1, user2, [](const User &x, const User &y) -> bool {
        return x.age < y.age;
      });
  std::cout << "minUser: " << minUser
            << std::endl; // minUser: struct User {age:100}

  // example03: initializer_list
  auto minOfList = std::min({13, 12, 10, 99, 88, 2});
  std::cout << "minOfList:" << minOfList << std::endl; // minOfList:2
  return 0;
}
