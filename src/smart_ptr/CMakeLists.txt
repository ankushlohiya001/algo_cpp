
add_library(smart_ptr STATIC)

target_sources(
  smart_ptr
  PUBLIC
    unique_ptr.hpp
  PRIVATE
    unique_ptr.cpp
)
