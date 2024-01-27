cmake_minimum_required(VERSION 3.14)

project(algo_cpp VERSION 0.1.0 LANGUAGES CXX)


# used to create build accord to GNU
# ie. makes bin/, lib/ etc, perfect structure :)
include(GNUInstallDirs)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})

# used to make nvim able to intercept linked directories
# ie. header files will be `not found` without compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# available modules of our project
# related to cpp more than cmake. ;)
set(modules
  ads
  searching
  sorting
  smart_ptr
)

# our source code
add_subdirectory(src)

# testing things
enable_testing()
add_subdirectory(test)
