#include "storage.h"
#include "stdlib.h"
#include "string.h"
#include "stdio.h"
#include "ctype.h"

int main() {
    Storage *s = storage();

    fillStorage(s);
    printStorage(s);

    return 0;
}