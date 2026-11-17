#include <stdio.h>
#include "itemType.h"

void freeItemType(itemType item) {
    (void)item;
}

int itemcmp(itemType item1, itemType item2) {
        if (item1 < item2) {
        return -1;
    } else if (item1 == item2) {
        return 0;
    } else {
        return 1;
    }
}

char *toItemString(itemType item) {
    static char str;
    snprintf(str, sizeof(str), "%d", item);
    return str;

}