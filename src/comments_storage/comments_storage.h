#pragma once
#include "stdlib.h"

typedef struct {
    char *comment;
    size_t length;
    size_t capacity;
} Comment;

Comment *comment();