cmake_minimum_required(VERSION 3.14)

project(algo_cpp VERSION 0.1.0 LANGUAGES CXX)


include(GNUInstallDirs)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})

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
