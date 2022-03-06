#include "stdlib.h"
#include "blog_data.h"

Post* post(char* name, char* content, char** tags, char** comments, int likes, int d, int m, int y) {
    Post* buf = (Post*)malloc(sizeof(Post));

    if (buf == NULL) {
        return NULL;
    }

    buf->name = name;
    buf->content=content;
    buf->tags = tags;
    buf->comments = comments;
    buf->likes = likes;
    buf->day = d;
    buf->month = m;
    buf->year = y;

    return buf;
}