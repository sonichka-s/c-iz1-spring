#include "storage.h"
#include "stdlib.h"
//#include "string.h"
#include "stdio.h"
//#include "ctype.h"

int main() {
    Storage *s = storage();

    fillStorage(s, "../input.txt");
    postFilter(s, 12, 20, 2, 9);
    freeStorage(&s);

    return 0;
}