// Glaze Library
// For the license information refer to glaze.hpp

#pragma once

#if defined(GLAZE_CXX_MODULE)
#define GLAZE_EXPORT export
#else
#define GLAZE_EXPORT
#endif

#include "glaze/core/write.hpp"
#include "glaze/util/dtoa.hpp"
#include "glaze/util/itoa.hpp"

GLAZE_EXPORT namespace glz
{
   template <num_t T>
   void format_to(std::string& buffer, T&& value)
   {
      auto ix = buffer.size();
      buffer.resize((std::max)(buffer.size() * 2, ix + 64));

      const auto start = buffer.data() + ix;
      const auto end = glz::to_chars(start, std::forward<T>(value));
      ix += size_t(end - start);
      buffer.resize(ix);
   }
}
