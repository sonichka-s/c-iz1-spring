#pragma once
#include "stdlib.h"

typedef struct {
    char **str;
    size_t length;
} String_storage;

String_storage* string_storage();
void addStr(String_storage* string_storage, char *str);
void printSStorage(String_storage* s);
void freeSStorage(String_storage *s);