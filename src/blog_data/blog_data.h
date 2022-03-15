#pragma once
#include "comments_storage.h"
#include "tags_storage.h"

typedef struct {
    char *name;
    char *content;
    Tags_storage *tags;
    Comment_storage *comments;
    int likes;
    int day;
    int month;
    int year;

} Post;

Post *post();
void freePost(Post *post);