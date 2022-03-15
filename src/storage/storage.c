#include "stdlib.h"
#include "string.h"
#include "stdio.h"
#include "storage.h"
#include "blog_data.h"
#include "tags_storage.h"
#include "comments_storage.h"
#include "ctype.h"

Storage *storage() {
    Storage* buf = (Storage *) malloc(sizeof(Storage *));

    if (buf == NULL)
        return NULL;

    buf->post = NULL;
    buf->length = 0;
    buf->capacity = 1;

    return buf;
}

Post* getPost(char* rawData) {
    Post *post = (Post *) malloc(sizeof(Post));
    char *post_str[8];
    Tags_storage *tag_arr = tags_storage();
    Comment_storage *com_arr = comment_storage();


    char *token = strtok(rawData, " ");

    for (int i = 0; i < 8; ++i) {
        if (i == 2) {
            while (token[0] == '#') {
                addTag(tag_arr, token);
                token = strtok(NULL, " ");
            }
            post_str[i] = NULL;
            continue;
        }

        if (i == 3) {
            while (!(isdigit(token[0]))) {
                addComment(com_arr, token);
                token = strtok(NULL, " ");
            }
            post_str[i] = NULL;
            continue;
        }

        post_str[i] = token;
        token = strtok(NULL, " ");
    }

    post->name = post_str[0];
    post->content = post_str[1];
    post->tags = tag_arr;
    post->comments = com_arr;
    post->likes = atoi(post_str[4]);
    post->day = atoi(post_str[5]);
    post->month = atoi(post_str[6]);
    post->year = atoi(post_str[7]);

//    freePost(post);
    return post;

}

void updateStorage(Storage *storage, Post *post) {
    if (storage == NULL || post == NULL)
        return;

    if (storage->length + 1 >= storage->capacity) {
        storage->capacity *= 2;
        storage->post = (Post *) realloc(storage->post, sizeof(Post *) * storage->capacity);

        if (storage->post == NULL)
            return;
    }

    storage->post[storage->length] = *post;
    storage->length += 1;
}



void printStorage(Storage* storage) {
    for (size_t i = 0; i < storage->length; ++i) {
        printf("name: ");
        puts(storage->post[i].name);
        printf("\n");
        printf("content: ");
        puts(storage->post[i].content);
        printf("\n");
        printf("tags: ");

        for (int j = 0; j < storage->post[i].tags->length; ++j) {
            puts(storage->post[i].tags->tag[i]);
            printf(" ");
        }
        printf("\n");
        printf("comments: ");

        for (int j = 0; j < storage->post[i].comments->length; ++j) {
            puts(storage->post[i].comments->comment[i]);
            printf(" ");
        }
        printf("\n");
        printf("likes: %i", storage->post[i].likes);
        printf("Date:  %d.%d.%d", storage->post[i].day, storage->post[i].month, storage->post[i].year);
    }
}

void fillStorage(Storage *storage) {
    FILE *f = fopen("../input.txt", "r");
    char temp[1000];
    char *postString;

    if (f == NULL)
        perror("File open error");

    while (1) {
        postString = fgets(temp, 1000, f);
        Post *post = getPost(postString);
        updateStorage(storage, post);

        if (postString == NULL) {
            if (feof(f) != 0) {
                break;
            }

            else {
                perror("File open error");
                break;
            }
        }
    }
}


