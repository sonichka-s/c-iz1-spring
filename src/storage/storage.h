#pragma once
#include "stdlib.h"
#include "blog_data.h"

typedef struct {
    Post* post;
    size_t length;
    size_t capacity;
} Storage;

Storage* storage(Post* post, size_t length, size_t capacity);
void addPost(Storage* storage, char* name, char* content, char** tags, char** comments, int likes, int d, int m, int y);
void printStorage(Storage* storage);
void commentFilter(Storage* storage);
void likeFilter(Storage* storage);
void freeStorage(Storage* storage);