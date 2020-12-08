/** Includes **/
#include <stdio.h>
#include "perl_interp.h"

/** Main **/
int main(int argc, char **argv, char **env)
{
    pSetup(argc, argv, env);
    //p(argc, argv, env);
    subRun(argv[2]);
    pFree();
    return(0);
}
