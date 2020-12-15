/** Includes **/
#include <stdio.h>
#include <stdlib.h>
#include "perl_interp.h"
#include "process.h"

/** Prototypes **/
void freeFileContent(FileContent *c);

/** Main **/
int main(int argc, char **argv, char **env)
{
    pSetup(argc, argv, env);
    FileContent *c = fgetLines(argv[2]);
    pFree();

    process(c);

    freeFileContent(c);
    return(0);
}

void freeFileContent(FileContent *c)
{
    for(int i = 0; i < c->t_lines; i++)
    {
        free(c->lines[i]);
    }
    free(c);
}
