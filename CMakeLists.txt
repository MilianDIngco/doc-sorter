cmake_minimum_required(VERSION 3.10)
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

# include directories
include_directories(include)
include_directories(${CURL_INCLUDE_DIRS})

# create executable
add_executable(docsorter
  src/main.cpp
  src/auth.cpp
  src/drive_client.cpp)

# link libraries
target_link_libraries(docsorter
  ${CURL_LIBRARIES}
  nlohmann_json::nlohmann_json
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
