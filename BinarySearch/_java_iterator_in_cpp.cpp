#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

template <typename T> class Iterator {
public:
  virtual bool hasNext() = 0;
  virtual T next() = 0;
  virtual ~Iterator() {}
};

template <typename T> class Collection {
public:
  virtual void add(const T &t) = 0;
  virtual Iterator<T> *iterator() = 0;
};

template <typename T> class QList : public Collection<T> {
public:
  void add(const T &t) override {
    // nop
  }

  Iterator<T> *iterator() override {
    // nop
    return new QListIterator();
  }

private:
  struct QListIterator : public Iterator<T> {
    bool hasNext() { return true; }
    T next() { return T(); }
  };
};

void testJavaIterators() {
  QList<int> list;
  list.add(1);
  auto iter = list.iterator();

  std::cout << std::boolalpha << "hasNext:" << iter->hasNext();
  std::cout << "next:" << iter->next() << std::endl;
  delete iter;
}

template <typename Iter> void test(Iter begin, Iter end) {
  typename std::iterator_traits<Iter>::difference_type count;
  count = end - begin;
}

int main(int argc, char **argv) {
  std::vector<int> vec({1, 2, 3, 4, 6, 7, 8});
  test(vec.begin(), vec.end());

  int arr[] = {1, 2, 3, 4, 5, 6, 7};
  test(arr, arr + 3);

  typename std::iterator_traits<int *>::difference_type count;

  testJavaIterators();
  return 0;
}
