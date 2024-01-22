
add_library(ads)

target_sources(
  ads
  PUBLIC
  ads.hpp
)

set_target_properties(
  ads
  PROPERTIES
  LINKER_LANGUAGE CXX
)

target_include_directories(
  ads
  PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
)
