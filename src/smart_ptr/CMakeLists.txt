
add_library(smart_ptr)

target_sources(
  smart_ptr
  PUBLIC
  smart_ptr.hpp
)

set_target_properties(
  smart_ptr
  PROPERTIES
  LINKER_LANGUAGE CXX
)

target_include_directories(
  smart_ptr
  PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
)
