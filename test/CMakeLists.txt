
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
)


add_test(
  NAME smart_ptr_test
  COMMAND $<TARGET_FILE:smart_ptr_test>
)
