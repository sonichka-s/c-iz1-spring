#include "stdlib.h"
#include "stdio.h"
#include "string_storage.h"
#include "string.h"
#define INIT_LENGTH 100

String_storage* string_storage() {
    String_storage *buf = (String_storage *) malloc(sizeof(String_storage) * INIT_LENGTH);

    if (buf == NULL)
        return NULL;

    buf->str = NULL;
    buf->length = 0;

    return buf;
}

void addStr(String_storage *string_storage, char *str) {
    if(string_storage == NULL)
        return;

    if(string_storage->str == NULL)
        string_storage->str = (char **) malloc(sizeof(char *) * INIT_LENGTH);

    if(string_storage->length + 1 >= INIT_LENGTH) {
        string_storage->str = (char **) realloc(string_storage->str, sizeof(char *) * string_storage->length * INIT_LENGTH * 2);
    }

    char *temp = str;
    string_storage->str[string_storage->length] = (char *) malloc(sizeof (char) * INIT_LENGTH);
    string_storage->str[string_storage->length] = temp;
    string_storage->length += 1;
}

void printSStorage(String_storage *s) {
    for (int i = 0; i < s->length; ++i) {
        printf("%s\n", s->str[i]);
    }
}

void freeSStorage(String_storage *s) {
    free(s->str);
}


