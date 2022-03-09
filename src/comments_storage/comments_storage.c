#include "stdlib.h"
#include "comments_storage.h"

Comment *comment() {
    Comment *buf = (Comment *) malloc(sizeof(Comment *));

    if (buf == NULL)
        return NULL;

    buf->comment = NULL;
    buf->length = 0;
    buf->capacity = 1;
}