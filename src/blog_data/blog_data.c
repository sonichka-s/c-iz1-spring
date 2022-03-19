#include "stdlib.h"
#include "blog_data.h"
#include "string_storage.h"

void freePost(Post *post) {
    if (post->tags != NULL)
        freeSStorage(post->tags);
    if (post->comments != NULL)
        freeSStorage(post->comments);
    free(post);
    post = NULL;
}
