
add_library(searching)

target_sources(
  searching
  PRIVATE
  searching.hpp
)

set_target_properties(
  searching
  PROPERTIES
  LINKER_LANGUAGE CXX
)

target_include_directories(
  searching
  PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
)
