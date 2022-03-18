#include <gtest/gtest.h>

extern "C" {
#include "storage.h"
#include "blog_data.h"
#include "string_storage.h"
}

//default values:
const size_t length = 1;
const size_t capacity = 2;

//string:
char *test_str = "name content #tag1 #tag2 comment1 comment2 1 1 1 1";

//elements:
const char first_name[] = "name1";
const char first_content[] = "content1";
const char *tag_arr[2] = {"#tag1", "#tag2"};
const char *comment_arr[2] = {"comment1", "comment2"};
const int first_likes = 1;
const int first_d = 1;
const int first_m = 1;
const int first_y = 1;

TEST(initializion, string_constructor) {
    String_storage *def_string_storage = (String_storage *) malloc(sizeof(String_storage));
    EXPECT_TRUE(def_string_storage != NULL);

    def_string_storage->str = NULL;
    def_string_storage->length = 0;

    String_storage *test_string_storage = string_storage();

    ASSERT_EQ(def_string_storage->str, test_string_storage->str);
    ASSERT_EQ(def_string_storage->length, test_string_storage->length);

    freeSStorage(def_string_storage);
    freeSStorage(test_string_storage);
}

TEST(initializion, storage_constructor) {
    Storage *default_storage = (Storage *) malloc(sizeof(Storage));
    EXPECT_TRUE(default_storage != NULL);

    default_storage->post = NULL;
    default_storage->length = 0;
    default_storage->capacity = 1;

    Storage *test_storage = storage();
    EXPECT_TRUE(test_storage != NULL);
    EXPECT_TRUE(test_storage->post != NULL);

    ASSERT_EQ(default_storage->post, test_storage->post);
    ASSERT_EQ(default_storage->length, test_storage->length);
    ASSERT_EQ(default_storage->capacity, test_storage->capacity);


    freeStorage(test_storage);
    freeStorage(default_storage);
}

TEST(storage_logic, get_post) {
    Post *test_post = (Post *) malloc(sizeof(Post));
    EXPECT_TRUE(test_post != NULL);

    test_post = getPostTest(test_str);

    EXPECT_TRUE(test_post->tags != NULL);
    EXPECT_TRUE(test_post->comments != NULL);

    EXPECT_EQ(first_name, test_post->name);
    EXPECT_EQ(first_content, test_post->content);
    for (int i = 0; i < test_post->tags->length; ++i) {
        EXPECT_EQ(tag_arr[i], test_post->tags[i]);
    }
    for (int i = 0; i < test_post->comments->length; ++i) {
        EXPECT_EQ(comment_arr[i], test_post->comments[i]);
    }
    EXPECT_EQ(first_likes, test_post->likes);
    EXPECT_EQ(first_d, test_post->day);
    EXPECT_EQ(first_m, test_post->month);
    EXPECT_EQ(first_y, test_post->year);

    freePost(test_post);
}

TEST(storage_logic, update_storage) {
    Storage *test_storage = storage();
    EXPECT_TRUE(test_storage != NULL);
    EXPECT_TRUE(test_storage->post !=NULL);

    Post *test_post = (Post *)malloc(sizeof(Storage));
    EXPECT_TRUE(test_post != NULL);

    test_post = getPostTest(test_str);
    updateStorageTest(test_storage, test_post);

    EXPECT_EQ(length, test_storage->length);
    EXPECT_EQ(capacity, test_storage->capacity);
}

TEST(storage_logic, fill_storage) {
    Storage *test_storage = (Storage *) malloc(sizeof(Storage));
    EXPECT_TRUE(test_storage != NULL);


}





