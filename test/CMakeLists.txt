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

foreach(lib
  IN ITEMS sorting smart_ptr ads)
  add_executable(
  ${lib}_test
)

  target_sources(
  ${lib}_test
  PRIVATE
  ${lib}_test.cpp
)

  target_link_libraries(
  ${lib}_test
  PRIVATE
    ${lib}
)
endforeach()

#
# add_test(
#   NAME smart_ptr_test
#   COMMAND $<TARGET_FILE:smart_ptr_test> --gtest_filter=smart_ptr.unique
# )
