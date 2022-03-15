#include "stdlib.h"
#include "comments_storage.h"
#define INIT_LENGTH 100

Comment_storage *comment_storage() {
    Comment_storage *buf = (Comment_storage *) malloc(sizeof(Comment_storage *));

    if (buf == NULL)
        return NULL;

    buf->comment = (char **) malloc(sizeof(char **) * INIT_LENGTH);
    buf->length = 0;

    return buf;
}

void addComment(Comment_storage *comment_storage, char* comment) {
    if(comment_storage == NULL)
        return;

    if(comment_storage->length + 1 >= INIT_LENGTH) {
        comment_storage->comment = (char **) realloc(comment_storage->comment, sizeof(char **) * INIT_LENGTH * 2);
    }

    comment_storage->comment[comment_storage->length] = comment;
    comment_storage->length += 1;
}

void freeCStorage(Comment_storage *s) {
    free(s->comment);
}
