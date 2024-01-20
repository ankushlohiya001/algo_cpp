
add_library(sorting)

target_sources(
  sorting
  PUBLIC
  sorting.hpp
)

set_target_properties(
  sorting
  PROPERTIES
  LINKER_LANGUAGE CXX
)

target_include_directories(
  sorting
  PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
)
