#include "stdlib.h"
#include "tags_storage.h"
#define INIT_LENGTH 100

Tags_storage* tags_storage() {
    Tags_storage *buf = (Tags_storage *) malloc(sizeof(Tags_storage *) * INIT_LENGTH);

    if (buf == NULL)
        return NULL;

    buf->tag = (char **) malloc(sizeof(char **) * INIT_LENGTH);
    buf->length = 0;

    return buf;
}

void addTag(Tags_storage* tags_storage, char *tag) {
    if(tags_storage == NULL)
        return;

    if(tags_storage->length + 1 >= INIT_LENGTH) {
        tags_storage->tag = (char **) realloc(tags_storage->tag, sizeof(char **) * INIT_LENGTH * 2);
    }

    tags_storage->tag[tags_storage->length] = tag;
    tags_storage->length += 1;
}

void freeTStorage(Tags_storage *s) {
    free(s->tag);
}
