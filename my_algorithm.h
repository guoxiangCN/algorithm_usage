#ifndef __MY_ALGORITHM_LIKE_STL__
#define __MY_ALGORITHM_LIKE_STL__

#include <initializer_list>
#include <type_traits>

namespace my {

// std::copy
// std::copy_if
// std::copy_n

template <typename InputIterator, typename OutputIterator>
OutputIterator copy(InputIterator first, InputIterator last,
                    OutputIterator output) {
  while (first != last) {
    *output = *first;
    first++;
  }
  return output;
}

template <typename InputIterator, typename OutputIterator, typename _Pred>
OutputIterator copy_if(InputIterator first, InputIterator last,
                       OutputIterator output, _Pred pred) {
  while (first != last) {
    if (pred(*first)) {
      *output = *first;
      output++;
    }
    first++;
  }
  return output;
}

template <typename InputIterator, typename SizeType, typename OutputIterator>
OutputIterator copy_n(
    InputIterator input,
    // typename std::enable_if<std::is_integral<SizeType>::value,SizeType>::type
    // n, CANNOT INFER TYPE
    SizeType n, OutputIterator output) {
  while (n > 0) {
    *output = *input;
    input++;
    output++;
    n--;
  }
  return output;
}

// std::min
// std::max
// std::minmax
// std::min_element
// std::max_element
// std::minmax_element
template <class T> T min(const T &a, const T &b) { //
  return (!(b > a)) ? a : b;
}

template <class T, class _Compare>
T min(const T &a, const T &b, _Compare compare) {
  return (!(compare(b, a))) ? a : b;
}

// template <class T>
// T min(std::initializer_list<T> list) {

// }

} // namespace my
#endif
