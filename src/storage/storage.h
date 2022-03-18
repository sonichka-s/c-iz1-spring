#pragma once
#include "stdlib.h"
#include "blog_data.h"

typedef struct {
    Post* post;
    size_t length;
    size_t capacity;
} Storage;

Storage* storage();
static Post* getPost(char *rowData);
static void updateStorage(Storage *storage, Post *post);
void printStorage(Storage* storage);
static void commentSort(Storage *s);
void postFilter(Storage* storage, int cur_month, int cur_year, int n, int min_likes);
void freeStorage(Storage* storage);
void fillStorage(Storage *storage);