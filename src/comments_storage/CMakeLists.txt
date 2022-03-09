add_library(comments_storage comments_storage.c comments_storage.h)

target_include_directories(comments_storage PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})