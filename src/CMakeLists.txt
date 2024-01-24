

foreach(
  dir IN ${modules})
  add_subdirectory(${dir})
endforeach()

add_library(algo_cpp)

target_sources(
  algo_cpp
  PUBLIC
    algo_cpp.hpp
)

set_target_properties(
  algo_cpp
  PROPERTIES
  LINKER_LANGUAGE CXX
)

target_link_libraries(
  algo_cpp
  PUBLIC
    smart_ptr
    sorting
)

target_include_directories(
  algo_cpp
  PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
)
