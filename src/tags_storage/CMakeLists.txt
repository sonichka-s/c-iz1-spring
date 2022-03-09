add_library(tags_storage tags_storage.c tags_storage.h)

target_include_directories(tags_storage PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})