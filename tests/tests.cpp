#include <gtest/gtest.h>

extern "C" {
#include "storage.h"
#include "blog_data.h"
#include "string_storage.h"
}

//default values:
const size_t length = 2;
const size_t capacity = 4;

//elements:
const char first_name[] = "name1";
const char first_content[] = "content1";
const char first_tag1[] = "#tag1";
const char first_tag2[] = "#tag2";
const char first_comment1[] = "comment1";
const char first_comment2[] = "comment2";
const int first_likes = 1;
const int first_d = 1;
const int first_m = 1;
const int first_y = 1;

TEST(initializing, string_constructor) {
    String_storage *test_string_storage = (String_storage *) malloc(sizeof(String_storage));
    EXPECT_TRUE(test_string_storage != 0);

    test_string_storage->str = NULL;
    test_string_storage->length = 0;

    freeSStorage(test_string_storage);
}




