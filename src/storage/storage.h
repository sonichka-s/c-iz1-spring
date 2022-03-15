#pragma once
#include "stdlib.h"
#include "blog_data.h"

typedef struct {
    Post* post;
    size_t length;
    size_t capacity;
} Storage;

Storage* storage();
Post* getPost(char *rowData);
void updateStorage(Storage *storage, Post *post);
void printStorage(Storage* storage);
void commentFilter(Storage* storage);
void likeFilter(Storage* storage);
void freeStorage(Storage* storage);
void fillStorage(Storage *storage);