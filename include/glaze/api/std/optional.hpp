// Glaze Library
// For the license information refer to glaze.hpp

#pragma once

#if defined(GLAZE_CXX_MODULE)
#define GLAZE_EXPORT export
#else
#define GLAZE_EXPORT
#include <optional>

#include "glaze/core/meta.hpp"
#endif

GLAZE_EXPORT namespace glz
{
   template <class T>
   struct meta<std::optional<T>>
   {
      static constexpr std::string_view name = join_v<chars<"std::optional<">, name_v<T>, chars<">">>;
   };
}
