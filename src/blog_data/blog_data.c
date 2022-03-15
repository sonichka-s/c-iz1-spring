#include "stdlib.h"
#include "blog_data.h"
#include "comments_storage.h"
#include "tags_storage.h"

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
    freeTStorage(post->tags);
    freeCStorage(post->comments);
}
