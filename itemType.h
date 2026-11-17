#ifndef ITEMTYPE_H
#define ITEMTYPE_H

#include <limits.h>

#define NULLITEM INT_MIN
//#define NEED_TO_FREE

typedef int itemType;

void freeItemType(itemType);
int itemcmp(itemType, itemType);
char *toItemString(itemType);

#endif
