module;

#define GLAZE_CXX_MODULE 1

#if defined(_WIN32) || defined(__CYGWIN__)
#ifndef GLAZE_API_ON_WINDOWS
#define GLAZE_API_ON_WINDOWS
#endif
#endif

#ifdef GLAZE_API_ON_WINDOWS
#ifdef NOMINMAX
#include <windows.h>
#else
#define NOMINMAX
#include <windows.h>
#undef NOMINMAX
#endif
#define SHARED_LIBRARY_EXTENSION ".dll"
#define SHARED_LIBRARY_PREFIX ""
#elif __APPLE__
#include <dlfcn.h>
#define SHARED_LIBRARY_EXTENSION ".dylib"
#define SHARED_LIBRARY_PREFIX "lib"
#elif __has_include(<dlfcn.h>)
#include <dlfcn.h>
#define SHARED_LIBRARY_EXTENSION ".so"
#define SHARED_LIBRARY_PREFIX "lib"
#endif

#if __has_include(<Eigen/Core>)
#include <Eigen/Core>
#else
static_assert(false, "Eigen must be included to use glaze/ext/eigen.hpp");
#endif

#if __has_include(<asio.hpp>) && !defined(GLZ_USE_BOOST_ASIO)
#include <asio.hpp>
#include <asio/signal_set.hpp>
#ifdef GLZ_ENABLE_SSL
#include <asio/ssl.hpp>
#endif
#elif __has_include(<boost/asio.hpp>)
#ifndef GLZ_USING_BOOST_ASIO
#define GLZ_USING_BOOST_ASIO
#endif
#include <boost/asio.hpp>
#include <boost/asio/signal_set.hpp>
#ifdef GLZ_ENABLE_SSL
#include <boost/asio/ssl.hpp>
#endif
#else
static_assert(false, "standalone or boost asio must be included to use glaze/ext/glaze_asio.hpp");

#ifdef _WIN32
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")
#else
#include <unistd.h>
#endif

export module glaze;

export import std;

#include "glaze/glaze.hpp"
