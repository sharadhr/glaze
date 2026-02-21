// Glaze Library
// For the license information refer to glaze.hpp

// Optional std::error_code integration for glz::error_code
// Include this header to enable implicit conversion from glz::error_code to std::error_code
//
// NOTE: Including this header adds ~34KB to binary size due to:
// - The global error_category variable with std::error_category vtable
// - This forces a DATA segment which incurs page alignment overhead
// For size-constrained embedded systems, avoid including this header.

#pragma once

#if defined(GLAZE_CXX_MODULE)
#define GLAZE_EXPORT export
#else
#define GLAZE_EXPORT
#include <system_error>
#endif

#include "glaze/core/error_category.hpp"

GLAZE_EXPORT namespace glz
{
   struct glaze_error_category : public std::error_category
   {
      const char* name() const noexcept override { return "glaze"; }

      std::string message(int ev) const override { return {meta<error_code>::keys[uint32_t(ev)]}; }
   };

   inline glaze_error_category error_category{};

   inline std::error_code make_error_code(error_code e) { return {static_cast<int>(e), error_category}; }
}

// Make Glaze error_code compatible with std::error_code
GLAZE_EXPORT template <> struct std::is_error_code_enum<glz::error_code> : std::true_type{};
