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
char test_str[] = "name content #tag1 #tag2 comment1 comment2 1 1 1 1";

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
        EXPECT_EQ(tag_arr[i], test_post->tags->str[i]);
    }
    for (int i = 0; i < test_post->comments->length; ++i) {
        EXPECT_EQ(comment_arr[i], test_post->comments->str[i]);
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

    Post *test_post = (Post *)malloc(sizeof(Storage));
    EXPECT_TRUE(test_post != NULL);

    test_post = getPostTest(test_str);
    updateStorageTest(test_storage, test_post);

    EXPECT_EQ(length, test_storage->length);
    EXPECT_EQ(capacity, test_storage->capacity);

    freeStorage(test_storage);
}

TEST(storage_logic, fill_storage) {
    Storage *test_storage = storage();
    EXPECT_TRUE(test_storage != NULL);

    char input_str[] = "name content #tag1 #tag2 comment1 5 12 12 21\nname2 content2 #tag21 #tag22 #tag23 comment21 comment22 10 15 12 20\nname3 content3 #tag31 #tag32 comment31 comment32 comment33 39 10 07 18";
    FILE *test_stream = fmemopen(test_stream, strlen(input_str), "r");
    EXPECT_TRUE(test_stream != NULL);

    fillStorageTest(test_storage, input_str);

    Storage *expect_storage = storage();
    char filename[] = "../input.txt";
    fillStorage(test_storage, filename);

    for (int i = 0; i < test_storage->length; ++i) {
        EXPECT_EQ(test_storage->post[i].name, expect_storage->post[i].name);
        EXPECT_EQ(test_storage->post[i].content, expect_storage->post[i].content);
        for (int j = 0; j < expect_storage->post[i].tags->length; ++j) {
            EXPECT_EQ(test_storage->post[i].tags->str[j], expect_storage->post[i].tags->str[j]);
        }
        for (int j = 0; j < expect_storage->post[i].comments->length; ++j) {
            EXPECT_EQ(test_storage->post[i].comments->str[j], expect_storage->post[i].comments->str[j]);
        }
        EXPECT_EQ(test_storage->post[i].likes, expect_storage->post[i].likes);
        EXPECT_EQ(test_storage->post[i].day, expect_storage->post[i].day);
        EXPECT_EQ(test_storage->post[i].month, expect_storage->post[i].month);
        EXPECT_EQ(test_storage->post[i].year, expect_storage->post[i].year);
    }

    freeStorage(test_storage);
    freeStorage(expect_storage);
}

TEST(output_logic, comment_sort) {
    Storage *test_storage = storage();
    EXPECT_TRUE(test_storage != NULL);

    char input_str[] = "name1 content1 #tag1 #tag2 comment1 1 1 1 1\nname2 content2 #tag21 #tag22 comment21 comment22 2 2 2 2";
    FILE *input = fmemopen(input_str, strlen(input_str), "r");
    EXPECT_TRUE(input != NULL);

    char test_post_input1[] = "name2 content2 #tag21 #tag22 comment21 comment22 2 2 2 2";
    Post *test_post1 = getPostTest(test_post_input1);
    EXPECT_TRUE(test_post1 != NULL);

    char test_post_input2[] = "name1 content1 #tag1 #tag2 comment1 1 1 1 1";
    Post* test_post2 = getPostTest(test_post_input2);
    EXPECT_TRUE(test_post2 != NULL);

    Post *test_post_arr[2] = {test_post1, test_post2};

    fillStorage(test_storage, input_str);
    commentSortTest(test_storage);

    for (int i = 0; i < test_storage->length; ++i) {
        EXPECT_EQ(test_storage->post[i].name, test_post_arr[i]->name);
        EXPECT_EQ(test_storage->post[i].content, test_post_arr[i]->content);
        for (int j = 0; j < 2; ++j) {
            EXPECT_EQ(test_storage->post[i].tags->str[j], test_post_arr[i]->tags->str[j]);
        }
        for (int j = 0; j < 2; ++j) {
            EXPECT_EQ(test_storage->post[i].comments->str[j], test_post_arr[i]->comments->str[j]);
        }
        EXPECT_EQ(test_storage->post[i].likes, test_post_arr[i]->likes);
        EXPECT_EQ(test_storage->post[i].day, test_post_arr[i]->day);
        EXPECT_EQ(test_storage->post[i].month, test_post_arr[i]->month);
        EXPECT_EQ(test_storage->post[i].year, test_post_arr[i]->year);
    }

    freeStorage(test_storage);
    freePost(test_post1);
    freePost(test_post2);
}

TEST(free, free_storage) {
    Storage *test_storage = storage();
    EXPECT_TRUE(test_storage);
    fillStorage(test_storage, test_str);

    freeStorage(test_storage);
    ASSERT_TRUE(test_storage->post->tags == NULL);
    ASSERT_TRUE(test_storage->post == NULL);
    ASSERT_TRUE(test_storage == NULL);
}



