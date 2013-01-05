#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "test.h"

struct _Private
{
    int a;
};

Private *InitPrivate()
{
    Private *a = calloc(1, sizeof(Private));

    if (NULL == a) {
        printf("InitPrivate() is failed.\n");
    }
    return a;
}

void TestPrivate(Private *a)
{
    assert(NULL != a);
    a->a = 101;
    printf("a=%d\n", a->a);
}
