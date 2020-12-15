#include <stdio.h>
#include "process.h"

void process(FileContent *c)
{
    for(int i = 0; i < c->t_lines; i++)
    {
        printf("%d - %s", i, c->lines[i]);
    }
}
