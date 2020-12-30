#ifndef __MY_ALGORITHM_LIKE_STL__
#define __MY_ALGORITHM_LIKE_STL__

#include <type_traits>

namespace my {
// std::min
// std::max
// std::minmax
// std::min_element
// std::max_element
// std::minmax_element
//

// std::copy
// std::copy_if
// std::copy_n

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

} // namespace my
#endif
