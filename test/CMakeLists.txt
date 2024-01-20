# to enable google testing, uncomment
# # enable FetchContent
# include(FetchContent)
#
# # declare where to find the dependency
# FetchContent_Declare(GoogleTest
#   GIT_REPOSITORY https://github.com/google/googletest.git
#   GIT_TAG        main
#   )
#
# # bring the dependency into scope
# FetchContent_MakeAvailable(GoogleTest)
#
add_executable(
  smart_ptr_test
)
target_sources(
  smart_ptr_test
  PRIVATE
  smart_ptr_test.cpp
)

target_link_libraries(
  smart_ptr_test
  PRIVATE
    smart_ptr
    # gtest_main
)

add_executable(
  sorting_test
)

target_sources(
  sorting_test
  PRIVATE
  sorting_test.cpp
)

target_link_libraries(
  sorting_test
  PRIVATE
    sorting
)


add_test(
  NAME smart_ptr_test
  COMMAND $<TARGET_FILE:smart_ptr_test> --gtest_filter=smart_ptr.unique
)
