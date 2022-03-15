#pragma once
#include "stdlib.h"

typedef struct {
    char **comment;
    size_t length;
} Comment_storage;

Comment_storage *comment_storage();
void addComment(Comment_storage *comment_storage, char *comment);
void freeCStorage(Comment_storage *s);