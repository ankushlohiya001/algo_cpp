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

# we need to make each test's executable, so :)
foreach(lib
  IN ITEMS ${modules})
  add_executable(
  ${lib}_test
)

  target_sources(
  ${lib}_test
  PRIVATE
  ${lib}_test.cpp
)

  # linking all modules, so that we can use library to every
  # all modules tests
  target_link_libraries(
  ${lib}_test
  PRIVATE
  ${modules}
)
endforeach()

#
# add_test(
#   NAME smart_ptr_test
#   COMMAND $<TARGET_FILE:smart_ptr_test> --gtest_filter=smart_ptr.unique
# )
