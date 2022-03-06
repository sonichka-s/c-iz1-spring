add_library(blog_data blog_data.c blog_data.h)

target_include_directories(blog_data PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})