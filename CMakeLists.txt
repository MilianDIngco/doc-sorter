cmake_minimum_required(VERSION 3.20)
project(docsorter VERSION 1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# get req packs
find_package(PkgConfig REQUIRED) # this is a cmake module used to find packages
find_package(nlohmann_json 3.2.0 REQUIRED) # this is a c++ library to parse json files

# use pkgconfig to find libcurl 
pkg_check_modules(CURL REQUIRED libcurl) # libcurl is an http client library, used to make web requests

# include directories for your project headers
include_directories(include)
include_directories(${CURL_INCLUDE_DIRS})

# Add libstemmer include directory to main project
include_directories(${CMAKE_SOURCE_DIR}/library/libstemmer/include)

# LIBSTEMMER STUFF thanks claude. 
file(GLOB LIBSTEMMER_CORE
  library/libstemmer/libstemmer/libstemmer.c
  library/libstemmer/libstemmer/libstemmer_utf8.c
)

set(LIBSTEMMER_MODULES
  library/libstemmer/libstemmer/modules.h
  library/libstemmer/libstemmer/modules_utf8.h
)

file(GLOB LIBSTEMMER_LANGS_UTF8
  library/libstemmer/src_c/stem_UTF_8_*.c
)

file(GLOB LIBSTEMMER_LANGS_ISO_8859_1
  library/libstemmer/src_c/stem_ISO_8859_1_*.c
)

file(GLOB LIBSTEMMER_LANGS_ISO_8859_2
  library/libstemmer/src_c/stem_ISO_8859_2_*.c
)

file(GLOB LIBSTEMMER_LANGS_KOI8_R
  library/libstemmer/src_c/stem_KOI8_R_*.c
)

file(GLOB LIBSTEMMER_RUNTIME
  library/libstemmer/runtime/*.c
)

file(GLOB LIBSTEMMER_UTILITIES
  library/libstemmer/src_c/utilities.c
)

add_library(libstemmer STATIC
  ${LIBSTEMMER_CORE}
  ${LIBSTEMMER_LANGS_UTF8}
  ${LIBSTEMMER_LANGS_ISO_8859_1}
  ${LIBSTEMMER_LANGS_ISO_8859_2}
  ${LIBSTEMMER_LANGS_KOI8_R}
  ${LIBSTEMMER_RUNTIME}
  ${LIBSTEMMER_UTILITIES}
)

target_include_directories(libstemmer PRIVATE
    ${CMAKE_SOURCE_DIR}/library/libstemmer/libstemmer
)

# Add include directories to libstemmer target so it compiles properly
target_include_directories(libstemmer PUBLIC
    ${CMAKE_SOURCE_DIR}/library/libstemmer/include
    ${CMAKE_SOURCE_DIR}/library/libstemmer/runtime
    ${CMAKE_SOURCE_DIR}/library/libstemmer/src_c
)

# add abseil subdirectory as prereq for re2
add_subdirectory(${CMAKE_SOURCE_DIR}/library/abseil-cpp)

# add re2 subdirectory for regex
set(RE2_INSTALL OFF CACHE BOOL "Disable RE2 installation")
add_subdirectory(${CMAKE_SOURCE_DIR}/library/re2)

# create executable
add_executable(docsorter
  src/main.cpp
  src/auth.cpp
  src/drive_client.cpp
  src/doc_vec.cpp
)

target_link_libraries(docsorter
  libstemmer
  ${CURL_LIBRARIES}
  nlohmann_json::nlohmann_json
  re2::re2
)

# add compiler flags from pkg-config
target_compile_options(docsorter PRIVATE ${CURL_CFLAGS_OTHER})

# set build type to debug by default
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

# compiler warnings
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
  target_compile_options(docsorter PRIVATE -Wall -Wextra -Wpedantic)
endif()

# print status
message(STATUS "libcurl found: ${CURL_FOUND}")
message(STATUS "libcurl version: ${CURL_VERSION}")
message(STATUS "nlohmann/json found")
