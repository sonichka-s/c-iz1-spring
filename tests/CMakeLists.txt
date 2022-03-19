add_executable(tests main.cpp tests.cpp)

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

target_include_directories(tests PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(tests ${GTEST_LIBRARIES} Threads::Threads blog_data storage string_storage)