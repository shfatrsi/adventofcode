/** Includes **/
#include <stdio.h>
#include "perl_interp.h"

/** Main **/
int main(int argc, char **argv, char **env)
{
    pSetup(argc, argv, env);
    fgetLines(argv[2]);
    pFree();

    //getchar();
    return(0);
}
