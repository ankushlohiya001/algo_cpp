
# adding directories of all modules
# ie. required them to have cmakelist.txt
# to include in the project
foreach(
  dir IN ITEMS ${modules})
  add_subdirectory(${dir})
endforeach()

# our main library enclosed every module.
add_library(algo_cpp)

target_sources(
  algo_cpp
  PUBLIC
    algo_cpp.hpp
)

# required because we've only hpp files,
# and cmake unable to intercept linker language
set_target_properties(
  algo_cpp
  PROPERTIES
  LINKER_LANGUAGE CXX
)

# linking all modules to main library
target_link_libraries(
  algo_cpp
  PUBLIC
    ${modules}
)

# it makes header file visible :L
target_include_directories(
  algo_cpp
  PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
)
