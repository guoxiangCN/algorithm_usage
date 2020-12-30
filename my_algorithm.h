#ifndef __MY_ALGORITHM_LIKE_STL__
#define __MY_ALGORITHM_LIKE_STL__

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

} // namespace my
#endif
