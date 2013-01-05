#include <stdio.h>
#include <stdlib.h>

#include "test.h"

int main()
{
    Private *a = InitPrivate();
    if (NULL == a) {
        return;
    }
    TestPrivate(a);
}
