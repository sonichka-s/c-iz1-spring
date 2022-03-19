#pragma once
#include "string_storage.h"

typedef struct {
    char *name;
    char *content;
    String_storage *tags;
    String_storage *comments;
    int likes;
    int day;
    int month;
    int year;

} Post;

void freePost(Post *post);