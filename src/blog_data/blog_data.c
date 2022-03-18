#include "stdlib.h"
#include "blog_data.h"
#include "string_storage.h"

void freePost(Post *post) {
    free(post->name);
    free(post->content);
    freeSStorage(post->tags);
    freeSStorage(post->comments);
}
