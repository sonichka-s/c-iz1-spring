#pragma once
#include "stdlib.h"

typedef struct {
    char **tag;
    size_t length;
} Tags_storage;

Tags_storage* tags_storage();
void addTag(Tags_storage* tags_storage, char *tag);
void freeTStorage(Tags_storage *s);