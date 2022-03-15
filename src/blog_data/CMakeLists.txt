add_library(blog_data blog_data.c blog_data.h)

target_link_libraries(blog_data LINK_PUBLIC tags_storage comments_storage)

target_include_directories(blog_data PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})