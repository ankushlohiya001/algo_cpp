
add_library(math)

target_sources(
  math
  PRIVATE
  math.hpp
)

set_target_properties(
  math
  PROPERTIES
  LINKER_LANGUAGE CXX

)

target_include_directories(
  math
  PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
)
