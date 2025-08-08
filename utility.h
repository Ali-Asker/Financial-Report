#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

extern int err;

typedef struct client *clientptr;

typedef struct client
{
    clientptr prev;

    char name[128];
    int type;
    int field1;
    int field2;
    int field3;

    clientptr next;
} client;

int fileReader(char *);

int linkedList(clientptr, int);

int printData(void);

int freeList(clientptr *);

int freeAllList();