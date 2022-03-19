add_library(storage storage.c storage.h)

target_link_libraries(storage LINK_PUBLIC blog_data string_storage)

target_include_directories(storage PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})