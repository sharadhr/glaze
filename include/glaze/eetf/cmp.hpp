#pragma once

#if defined(GLAZE_CXX_MODULE)
#define GLAZE_EXPORT export
#else
#define GLAZE_EXPORT
#endif

namespace glz::eetf
{

   namespace detail
   {

      // Primary template
      template <typename Tag>
      struct in_impl;

      // Specialization for `int...`
      template <int N, int... Vs>
      struct in_impl<std::integer_sequence<int, N, Vs...>>
      {
         bool value{false};

         template <int_t T>
         constexpr in_impl(const T& val) : value{(val == N) || in_impl<std::integer_sequence<int, Vs...>>(val).value}
         {}
      };

      template <int N>
      struct in_impl<std::integer_sequence<int, N>>
      {
         bool value{false};

         template <int_t T>
         constexpr in_impl(const T& val) : value{val == N}
         {}
      };

   } // namespace detail

   GLAZE_EXPORT template <typename T>
   using in = detail::in_impl<T>;

   GLAZE_EXPORT namespace cmp
   {

      template <template <class> class Op, int... Vs, typename T>
      constexpr bool is(const T& val)
      {
         return Op<std::integer_sequence<int, Vs...>>(val).value;
      }

   };

} // namespace erlterm
