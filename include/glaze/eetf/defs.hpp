#pragma once

#if defined(GLAZE_CXX_MODULE)
#define GLAZE_EXPORT export
#else
#define GLAZE_EXPORT
#endif

#include <glaze/core/common.hpp>

#include "types.hpp"

GLAZE_EXPORT namespace glz
{
   template <class T>
   concept atom_t = string_t<T> && std::same_as<typename T::tag, eetf::tag_atom>;

} // namespace glz
