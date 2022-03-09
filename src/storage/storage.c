#include "stdlib.h"
#include "stdio.h"
#include "storage.h"
#include "blog_data.h"

Storage *storage() {
    Storage* buf =(Storage *) malloc(sizeof(Storage *));

    if (buf == NULL)
        return NULL;

    buf->post = NULL;
    buf->length = 0;
    buf->capacity = 1;

    return buf;
}

void addPost(Storage *storage, char* name, char* content, char **tags, char **comments, int likes, int d, int m, int y) {
    Post *post = (Post *) malloc(sizeof(Post *));

    if (storage == NULL || post == NULL)
        return;

    if (storage->length + 1 > storage->capacity) {
        storage->capacity *= 2;
        storage->post = (Post *) realloc(storage->post, sizeof(Post *) * storage->capacity);

        if (storage->post == NULL)
            return;
    }

    post->name = name;
    post->content = content;
    post->tags = tags;
    post->comments = comments;
    post->likes = likes;
    post->day = d;
    post->month = m;
    post->year = y;

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

        while(storage->post[i].tags != NULL) {
            puts(*storage->post[i].tags);
            *storage->post[i].tags++;
            printf(" ");
        }
        printf("\n");
        printf("comments: ");

        while(storage->post[i].comments != NULL) {
            puts(*storage->post[i].comments);
            *storage->post[i].comments++;
            printf(" ");
        }
        printf("\n");
        printf("likes: %i", storage->post[i].likes);
        printf("Date:  %d.%d.%d", storage->post[i].day, storage->post[i].month, storage->post[i].year);
    }
}
