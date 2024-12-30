
include_directories(.)

add_executable(thread thread.cc)

add_executable(CRTP test/CRTPTest.cc)
target_link_libraries(CRTP gtest)

add_test(NAME CRTP COMMAND $<TARGET_FILE:CRTP>)