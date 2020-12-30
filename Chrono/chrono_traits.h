#ifndef __CHRONO_TRAITS________________
#define __CHRONO_TRAITS________________

#include <chrono>
#include <type_traits>

template <typename T> struct is_duration : std::false_type {};

template <typename Rep, typename Period>
struct is_duration<std::chrono::duration<Rep, Period> /**/> : std::true_type {};

#endif
