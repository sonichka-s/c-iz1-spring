#include "stdlib.h"
#include "string.h"
#include "stdio.h"
#include "storage.h"
#include "blog_data.h"
#include "string_storage.h"
#include "ctype.h"
#define INIT_LENGTH 100

Storage *storage() {
    Storage* buf = (Storage *) malloc(sizeof(Storage *));

    if (buf == NULL)
        return NULL;

    buf->length = 0;
    buf->capacity = 1;
    buf->post = NULL;

    return buf;
}

static Post* getPost(char* rawData) {
    Post *post = (Post *) malloc(sizeof(Post));

    if(post == NULL)
        return NULL;

    char *post_str[8];
    String_storage *tag_arr = string_storage();

    if(tag_arr == NULL)
        return NULL;

    String_storage *com_arr = string_storage();

    if(com_arr == NULL)
        return NULL;


    char *token = strtok(rawData, " ");

    if(token == NULL)
        return NULL;

    post->name = token;
    token = strtok(NULL, " ");

    post->content = token;
    token = strtok(NULL, " ");



    while (!isdigit(token[0])) {
        if (token[0] == '#') {
            addStr(tag_arr, token);
            token = strtok(NULL, " ");
        }

        else {
            addStr(com_arr, token);
            token = strtok(NULL, " ");
        }
    }

    post->tags = tag_arr;
    post->comments = com_arr;

    post->likes = atoi(token);
    token = strtok(NULL, " ");

    post->day = atoi(token);
    token = strtok(NULL, " ");

    post->month = atoi(token);
    token = strtok(NULL, " ");

    post->year = atoi(token);

    return post;
}

Post *getPostTest(char *rawData) {
    return getPost(rawData);
}

static void updateStorage(Storage *storage, Post *post) {
    if (storage == NULL || post == NULL)
        return;

    if (storage->length + 1 >= storage->capacity) {
        storage->capacity *= 2;
        storage->post = (Post *) realloc(storage->post, sizeof(Post) * storage->capacity);

        if (storage->post == NULL)
            return;
    }

    storage->post[storage->length] = *post;
    storage->length += 1;
}

void updateStorageTest(Storage *storage, Post *post) {
    updateStorage(storage, post);
}

void printStorage(Storage* storage) {
    commentSort(storage);
    for (size_t i = 0; i < storage->length; ++i) {
        printf("name: %s\n", storage->post[i].name);
        printf("content: %s\n", storage->post[i].content);
        printf("tags: \n");

        printSStorage(storage->post[i].tags);

        printf("comments: \n");

        printSStorage(storage->post[i].comments);

        printf("likes: %i\n", storage->post[i].likes);
        printf("Date: %d.%d.%d\n", storage->post[i].day, storage->post[i].month, storage->post[i].year);
        printf("\n");
    }
}

void fillStorage(Storage *storage, char *input_file) {
    FILE *f = fopen(input_file, "r");
    size_t max_len = 100;
    ssize_t  len = 0;

    if (f == NULL)
        perror("File open error");

    while (len != -1) {
        char *postString = NULL;
        len = getline(&postString, &max_len, f);

        if(len != -1) {
            Post *post = getPost(postString);
            updateStorage(storage, post);
        }
    }
}

void fillStorageTest(Storage *storage, char *file_data) {
    FILE *f = fmemopen(file_data, strlen(file_data), "r");
    size_t max_len = 100;
    ssize_t  len = 0;

    if (f == NULL)
        perror("File open error");

    while (len != -1) {
        char *postString = NULL;
        len = getline(&postString, &max_len, f);

        if(len != -1) {
            Post *post = getPost(postString);
            updateStorage(storage, post);
        }
    }
}

static void commentSort(Storage *s) {
    for (size_t i = 0; i < s->length - 1; ++i) {
        for (size_t j = (s->length) - 1; i < j; --j) {
            if (s->post[j - 1].comments->length < s->post[j].comments->length) {
                Post temp = s->post[j - 1];
                s->post[j - 1] = s->post[j];
                s->post[j] = temp;
            }
        }
    }
}

void commentSortTest(Storage *s) {
    commentSort(s);
}

void postFilter(Storage* storage, int cur_month, int cur_year, int n, int min_likes) {
    commentSort(storage);
    size_t counter = 0;
    for (int i = 0; i < storage->length; ++i) {
        if (storage->post[i].month == cur_month && storage->post[i].year == cur_year && counter != n && storage->post[i].likes >= min_likes) {
            printf("name: %s\n", storage->post[i].name);
            printf("content: %s\n", storage->post[i].content);
            printf("tags: \n");

            printSStorage(storage->post[i].tags);

            printf("comments: \n");

            printSStorage(storage->post[i].comments);

            printf("likes: %i\n", storage->post[i].likes);
            printf("Date: %d.%d.%d\n", storage->post[i].day, storage->post[i].month, storage->post[i].year);
            printf("\n");

            counter++;
        }
    }
}

void freeStorage(Storage* storage) {
    if (storage->post != NULL)
        freePost(storage->post);
    free(storage);
}



