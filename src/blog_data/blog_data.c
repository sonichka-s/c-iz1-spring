#include "stdlib.h"
#include "blog_data.h"
#include "string_storage.h"

Post *post() {
    Post* buf = (Post*) malloc(sizeof(Post *));

    if (buf == NULL) {
        return NULL;
    }

    return buf;
}

void freePost(Post *post) {
    free(post->name);
    free(post->content);
    freeSStorage(post->tags);
    freeSStorage(post->comments);
}
